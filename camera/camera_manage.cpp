#include "camera_manage.h"

CameraSwitch::CameraSwitch(V3DPluginCallback2 *callback, QWidget *parent)
{
    this->V3D_env=callback;
    this->myparent=parent;
    this->setWindowTitle("Camera Switch");
    this->setFixedWidth(500);

    switchon=new QPushButton;
    switchon->setText("On");
    switchoff=new QPushButton;
    switchoff->setText("Off");
    layout=new QVBoxLayout;
    layout->addWidget(switchon);
    layout->addWidget(switchoff);
    this->setLayout(layout);

    connect(switchon,SIGNAL(clicked()),this,SLOT(switch_on()));
    connect(switchoff,SIGNAL(clicked()),this,SLOT(switch_off()));

    ison=false;
}

void CameraSwitch::switch_on()
{
    if(ison==false)
    {
        mycamera=new Camera(V3D_env,myparent);
        ison =true;
    }
}

void CameraSwitch::switch_off()
{
    if(ison=true)
    {
        delete mycamera;
        ison=false;
    }
}
