#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QWidget>
#include <QDialog>
#include <QDebug>
class QLineEdit;
class QSlider;
class MyDialog : public QDialog
{
  Q_OBJECT
public:
  explicit MyDialog(QWidget *parent = 0);
signals:
  void MyvalueChanged(double value);
public slots:
  void setLineEditValue(int value);
private:
  QLineEdit *lineEdit;
  QSlider *slider;
  //int pos;
};

#endif // MYDIALOG_H
