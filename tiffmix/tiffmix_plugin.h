/* tiffmix_plugin.h
 * This is a tm plugin, you can use it as a demo.
 * 2021-11-20 : by csznbhh
 */
 
#ifndef __TIFFMIX_PLUGIN_H__
#define __TIFFMIX_PLUGIN_H__
#include "mydialog.h"
#include <QtGui>
#include <v3d_interface.h>

class tmPlugin : public QObject, public V3DPluginInterface2_1
{
	Q_OBJECT
	Q_INTERFACES(V3DPluginInterface2_1);

public:
   // tmPlugin();

	float getPluginVersion() const {return 1.1f;}
    MyDialog *mydialog;
	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);

	QStringList funclist() const ;
	bool dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, V3DPluginCallback2 &callback, QWidget *parent);
    V3DPluginCallback2 *mcallback=NULL;
    QWidget *mparent=NULL;
    //int count=0;
public slots:
    void setalpha(double global_alpha);
};

#endif

