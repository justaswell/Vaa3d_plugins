#ifndef CAMERA_MANAGE_H
#define CAMERA_MANAGE_H
#include <Camera.h>
#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QLayout>
#include <v3d_interface.h>

class CameraSwitch:public QWidget{
    Q_OBJECT
public:
    CameraSwitch(V3DPluginCallback2 *callback,QWidget *parent);
public slots:
    void switch_on();
    void switch_off();
public:
    QWidget *myparent;
    V3DPluginCallback2* V3D_env;
    QPushButton *switchon;
    QPushButton *switchoff;
    QVBoxLayout *layout;
    Camera *mycamera;
    bool ison;
};

#endif // CAMERA_MANAGE_H
