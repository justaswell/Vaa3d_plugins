/* tiffmix_plugin.cpp
 * This is a tm plugin, you can use it as a demo.
 * 2021-11-20 : by csznbhh
 */
 
#include "v3d_message.h"
#include <vector>
#include "tiffmix_plugin.h"
#include "func.h"
#include <externs.h>


using namespace std;
const QString title="Tiffmix";
Q_EXPORT_PLUGIN2(tiffmix, tmPlugin);
 


QStringList tmPlugin::menulist() const
{
	return QStringList() 
		<<tr("tiffmix")
		<<tr("about");
}

QStringList tmPlugin::funclist() const
{
	return QStringList()
		<<tr("ftiffmix")
		<<tr("help");
}

void tmPlugin::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
	if (menu_name == tr("tiffmix"))
	{
        mydialog=new MyDialog;
        mydialog->show();
        this->mcallback=&callback;
        this->mparent=parent;
        connect(mydialog, SIGNAL(MyvalueChanged(double)), this, SLOT(setalpha(double)));
        //v3d_msg("To be implemented.");
	}
	else
    {

        v3d_msg(tr("You need at least 3 images to run this plugin. The first two images"
                   "are the images you want to mix, and the third image is used as the"
                   "3Dviewer stack to show the mixed result."
			"Developed by csznbhh, 2021-11-20"));
	}
}

bool tmPlugin::dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output, V3DPluginCallback2 & callback,  QWidget * parent)
{
	vector<char*> infiles, inparas, outfiles;
	if(input.size() >= 1) infiles = *((vector<char*> *)input.at(0).p);
	if(input.size() >= 2) inparas = *((vector<char*> *)input.at(1).p);
	if(output.size() >= 1) outfiles = *((vector<char*> *)output.at(0).p);

	if (func_name == tr("ftiffmix"))
	{
		v3d_msg("To be implemented.");
	}
	else if (func_name == tr("help"))
	{
		v3d_msg("To be implemented.");
	}
	else return false;

    return true;
}


void tmPlugin::setalpha(double global_alpha)
{
//    count++;
//    if(count%20!=0) return;
    tiffmix(*mcallback,mparent);
    //qDebug()<<global_alpha;

}

