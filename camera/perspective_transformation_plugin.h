/* perspective transformation_plugin.h
 * An new method to operate the v3d.
 * 2022-2-16 : by csz
 */
 
#ifndef __PERSPECTIVE_TRANSFORMATION_PLUGIN_H__
#define __PERSPECTIVE_TRANSFORMATION_PLUGIN_H__

#include <QtGui>
#include <v3d_interface.h>

class CameraPlugin : public QObject, public V3DPluginInterface2_1
{
	Q_OBJECT
	Q_INTERFACES(V3DPluginInterface2_1);

public:
	float getPluginVersion() const {return 1.1f;}

	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);

	QStringList funclist() const ;
	bool dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, V3DPluginCallback2 &callback, QWidget *parent);
};

#endif

