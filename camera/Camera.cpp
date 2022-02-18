#include "Camera.h"

Camera::Camera(V3DPluginCallback2 *callback,QWidget *parent)
{
    this->V3D_env=callback;
    this->myparent=parent;
//    this->setWindowTitle("Camera Switch");
//    this->setFixedWidth(500);

    this->window=(*V3D_env).currentImageWindow();
    this->triViewWidget=(XFormWidget*)window;
    this->view3DWidget=(V3dR_GLWidget*)(V3D_env->getView3DControl(window));
//    this->window3D = view3DWidget->getiDrawExternalParameter()->window3D;

//    switchon=new QPushButton;
//    switchon->setText("On");
//    switchoff=new QPushButton;
//    switchoff->setText("Off");
//    layout=new QVBoxLayout;
//    layout->addWidget(switchon);
//    layout->addWidget(switchoff);
//    this->setLayout(layout);

//    connect(switchon,SIGNAL(clicked()),this,SLOT(switch_on()));
//    connect(switchoff,SIGNAL(clicked()),this,SLOT(switch_off()));
    if(this->view3DWidget)
        this->view3DWidget->installEventFilter(this);
    zoom=0.0;
    _xShift=0.0;
    _yShift=0.0;
    _xRotate=0;
    _yRotate=0;
    //iseventfilter=true;
}

Camera::~Camera()
{
    this->view3DWidget->removeEventFilter(this);
}

bool Camera::eventFilter(QObject *object, QEvent *event)
{
    if(object==view3DWidget){

        if(event->type()==QEvent::KeyPress){
            QKeyEvent *keyEvent=(QKeyEvent*)(event);
            switch(keyEvent->key()){
                case Qt::Key_W:{
                    zoom+=1.0;
                    if(zoom>100) zoom=100;
                    view3DWidget->setZoom(zoom);
                    update();
                    //qDebug()<<"W is pressed!";
                    return true;
                }
                case Qt::Key_S:{
                    zoom-=1.0;
                    if(zoom<-100) zoom=-100;
                    view3DWidget->setZoom(zoom);
                    update();
                    //qDebug()<<"S is pressed!";
                    return true;
                }
                case Qt::Key_A:{
                    view3DWidget->setXShift(--_xShift);
                    return true;
                }
                case Qt::Key_D:{
                    view3DWidget->setXShift(++_xShift);
                    return true;
                }
            }
        }

        if(event->type()==QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent=(QMouseEvent*)(event);
            if(mouseEvent->buttons()&Qt::LeftButton){
                lastPos=mouseEvent->pos();
                return true;
            }
        }
        if(event->type()==QEvent::MouseMove){
            QMouseEvent *mouseEvent=(QMouseEvent*)(event);
            int dx=mouseEvent->x()-lastPos.x();
            int dy=mouseEvent->y()-lastPos.y();
            lastPos=mouseEvent->pos();
            _xShift-=dx;
            _yShift+=dy;
            //zoom=(float(dx+dy)+zoom)/10;
            _xRotate+=dx;
            _yRotate+=dy;
            qDebug()<<_xRotate<<_yRotate;
            if(_xRotate<=100&&_xRotate>=-100)
                view3DWidget->modelRotation(0,dx,0);
            if(_yRotate<=100&&_yRotate>=-100)
                view3DWidget->modelRotation(dy,0,0);
            //view3DWidget->setZoom(zoom);
            view3DWidget->setXShift(_xShift);
            view3DWidget->setYShift(_yShift);
            return true;
        }
    }
    return false;
}

//void Camera::switch_on()
//{
//    qDebug()<<"on is pressed";
//    if(iseventfilter==false)
//    {
//        this->view3DWidget->installEventFilter(this);
//        iseventfilter=true;
//    }
//}

//void Camera::switch_off()
//{
//    qDebug()<<"off is pressed";
//    if(iseventfilter==true)
//    {
//        this->view3DWidget->removeEventFilter(this);
//        iseventfilter=false;
//    }
//}
