#ifndef FUNC_H
#define FUNC_H

#include <v3d_interface.h>

int tiffmix(V3DPluginCallback2 &callback, QWidget *parent);
int tiffmix(const V3DPluginArgList & input, V3DPluginArgList & output);
void printHelp();

#endif // FUNC_H
