#include <v3d_interface.h>
#include "v3d_message.h"
#include "stackutil.h"
#include "func.h"
#include <vector>
#include <iostream>
#include <QString>
#include "mydialog.h"
#include <externs.h>


using namespace std;

const QString title="Tiffmix";



int tiffmix(V3DPluginCallback2 &callback, QWidget *parent)
{
    v3dhandleList curlist=callback.getImageWindowList();

    if(curlist.size()<3){
        QMessageBox::information(0, title, QObject::tr("You need at least three images, the last image is needed as the result stack."));
        return -1;
    }

    v3dhandle win1=curlist[0];
    v3dhandle win2=curlist[1];
    v3dhandle win3=curlist[2];
    Image4DSimple *p4DImage1 = callback.getImage(win1);
    Image4DSimple *p4DImage2 = callback.getImage(win2);
    Image4DSimple *p4DImage3 = callback.getImage(win3);

    V3DLONG sz[3];
    sz[0] = p4DImage1->getXDim();
    sz[1] = p4DImage1->getYDim();
    sz[2] = p4DImage1->getZDim();
    unsigned char * inimg1d1 = p4DImage1->getRawDataAtChannel(0);
    unsigned char * inimg1d2 = p4DImage2->getRawDataAtChannel(0);
    V3DLONG tb = sz[0]*sz[1]*sz[2]*p4DImage1->getUnitBytes();
    unsigned char * nm = NULL;
    try {
        nm = new unsigned char [tb];
    } catch (...) {
        throw("Fail to allocate memory in Tiffmix plugin.");
    }
    qDebug()<<"global_alpha:"<<global_alpha;
    for (V3DLONG i=0;i<tb;i++)
    {

        nm[i]=inimg1d1[i]*(global_alpha)+inimg1d2[i]*(1-(global_alpha));
    }

    p4DImage3->setData(nm, sz[0], sz[1], sz[2], 1, p4DImage3->getDatatype());
    //v3dhandle newwin = callback.newImageWindow();

    callback.close3DWindow(win3);

    callback.setImage(win3, p4DImage3);
    //callback.setImageName(newwin, QObject::tr("Tiffmix"));
    callback.pushImageIn3DWindow(win3);

    callback.open3DWindow(win3);
//    callback.setImage(newwin, p4DImage1);
//    callback.setImageName(newwin, QObject::tr("Tiffmix"));
//    callback.updateImageWindow(newwin);
//    callback.open3DWindow(newwin);

//    v3dhandle curwin = callback.currentImageWindow();
//        if(!curwin)
//        {
//            QMessageBox::information(0, title, QObject::tr("No image is open."));
//            return -1;
//        }
//    Image4DSimple *p4DImage = callback.getImage(curwin);
//    bool ok;

//    int c = -1;
//    c = QInputDialog::getInteger(parent, "Channel Number", "Set the subject channel number:", 0, 0, p4DImage->getCDim()-1, 1, &ok);
//    if (!ok) return -1;

//    QString segname;
//    segname=QInputDialog::getText(parent,"Segmentation File","File diretory:",QLineEdit::Normal,"your filedir", &ok);
//    if (!ok) return -1;
//    char* ch;
//    QByteArray sn = segname.toLatin1();
//    ch=sn.data();
//    Image4DSimple *p4DImage_seg=callback.loadImage(ch);

//    //while(1){
//        double alpha = -1;
//        alpha = QInputDialog::getDouble(parent, "alpha", "Set alpha:", 0.5, 0, 1, 2, &ok);
//        if (!ok) return -1;
//        //if(alpha==1) break;
//        V3DLONG sz[3];
//        sz[0] = p4DImage->getXDim();
//        sz[1] = p4DImage->getYDim();
//        sz[2] = p4DImage->getZDim();
//        unsigned char * inimg1d = p4DImage->getRawDataAtChannel(c);
//        unsigned char * inimg1d2 = p4DImage_seg->getRawDataAtChannel(c);
//        V3DLONG tb = sz[0]*sz[1]*sz[2]*p4DImage->getUnitBytes();
//        unsigned char * nm = NULL;
//        try {
//                nm = new unsigned char [tb];
//        } catch (...) {
//                throw("Fail to allocate memory in Tiffmix plugin.");
//        }
//        for (V3DLONG i=0;i<tb;i++)
//        {
//            nm[i]=inimg1d[i]*alpha+inimg1d2[i]*(1-alpha);
//        }
//        v3dhandle newwin = callback.newImageWindow();
//        p4DImage->setData(nm, sz[0], sz[1], sz[2], 1, p4DImage->getDatatype());
//        callback.setImage(newwin, p4DImage);
//        callback.setImageName(newwin, QObject::tr("Tiffmix"));
//        callback.updateImageWindow(newwin);
    //}
    return 1;
}

int tiffmix(const V3DPluginArgList &input, V3DPluginArgList &output)
{
    v3d_msg("To be implemented. Suggest to use the menu");
    return 1;
}

void printHelp()
{
    cout<<"\nThis is a demo plugin to perform Tiffmix in an image. by csznbhh 2012-02"<<endl;
        cout<<"\nUsage: v3d -x <example_plugin_name> -f tiffmix -i <input_image_file> -o <output_image_file> -p <subject_color_channel> <threshold>"<<endl;
        cout<<"\t -i <input_image_file>                      input 3D image (tif, raw or lsm)"<<endl;
        cout<<"\t -o <output_image_file>                     output image of the thresholded subject channel"<<endl;
        cout<<"\t -p <subject_color_channel> <alpha>     the channel you want to perform thresholding and the threshold"<<endl;
        cout<<"\t                                            the 2 paras must come in this order"<<endl;
        return;
}
