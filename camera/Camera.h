#ifndef CAMERA_H
#define CAMERA_H
#include <QWidget>
#include <QEvent>
//#include <QPushButton>
//#include <QLayout>
#include <v3d_interface.h>
#include "../v3d/v3d_core.h"
#include "../3drenderer/v3dr_glwidget.h"
class Camera:public QWidget{
    Q_OBJECT
public:
    Camera(V3DPluginCallback2 *callback,QWidget *parent);
    ~Camera();

    bool eventFilter(QObject *object, QEvent *event);

public:
    QWidget *myparent;
    V3DPluginCallback2* V3D_env;    //handle of V3D environment
    v3dhandle window;               //generic (void *) handle of the tri-view image window
    XFormWidget* triViewWidget;     //the tri-view image window
    V3dR_GLWidget* view3DWidget;    //3D renderer widget associated to the image window
    QPoint lastPos;
    float zoom,_xShift,_yShift;
    int _xRotate,_yRotate;
//  V3dR_MainWindow* window3D;
//    bool iseventfilter;
//    QPushButton *switchon;
//    QPushButton *switchoff;
//    QVBoxLayout *layout;
};


#endif // CAMERA_H
