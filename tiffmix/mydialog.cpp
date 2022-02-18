#include "mydialog.h"
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QHBoxLayout>
#include <glbs.h>
#include <externs.h>
MyDialog::MyDialog(QWidget *parent) :QDialog(parent)
{
  lineEdit = new QLineEdit("0");

  //新建一个水平方向的滑动条QSlider控件
  slider = new QSlider(Qt::Horizontal);
  //设置滑动条控件的最小值
  slider->setMinimum(0);
  //设置滑动条控件的最大值
  slider->setMaximum(100);
  //设置滑动条控件的值
  slider->setValue(0);

  //信号和槽 当滑动条的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件的显示文本
  connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue(int)));

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(lineEdit);
  layout->addWidget(slider);

  this->setLayout(layout);
  this->resize(200, 50);
  this->setWindowTitle("Tiffmix");
  //this->pos=50;
}

void MyDialog::setLineEditValue(int value)
{
  int pos = slider->value();
  QString str = QString("%1").arg(pos);
  lineEdit->setText(str);

  global_alpha=pos/100.0;
  //qDebug()<<"value:"<<global_alpha;
  emit MyvalueChanged(global_alpha);
}
