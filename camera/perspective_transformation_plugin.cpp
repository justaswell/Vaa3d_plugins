/* perspective transformation_plugin.cpp
 * An new method to operate the v3d.
 * 2022-2-16 : by csz
 */
 
#include "v3d_message.h"
#include <vector>
#include "perspective_transformation_plugin.h"
#include "camera_manage.h"

using namespace std;
Q_EXPORT_PLUGIN2(perspective_transformation, CameraPlugin);
 
QStringList CameraPlugin::menulist() const
{
	return QStringList() 
		<<tr("Camera")
		<<tr("about");
}

QStringList CameraPlugin::funclist() const
{
	return QStringList()
		<<tr("func1")
		<<tr("func2")
		<<tr("help");
}

void CameraPlugin::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
	if (menu_name == tr("Camera"))
	{
        CameraSwitch *mycameraswitch=new CameraSwitch(&callback,parent);
        mycameraswitch->show();
        //v3d_msg("To be implemented.");
	}
	else
	{
		v3d_msg(tr("An new method to operate the v3d.. "
			"Developed by csz, 2022-2-16"));
	}
}

bool CameraPlugin::dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output, V3DPluginCallback2 & callback,  QWidget * parent)
{
	vector<char*> infiles, inparas, outfiles;
	if(input.size() >= 1) infiles = *((vector<char*> *)input.at(0).p);
	if(input.size() >= 2) inparas = *((vector<char*> *)input.at(1).p);
	if(output.size() >= 1) outfiles = *((vector<char*> *)output.at(0).p);

	if (func_name == tr("func1"))
	{
		v3d_msg("To be implemented.");
	}
	else if (func_name == tr("func2"))
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

