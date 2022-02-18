
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
QT+=opengl
#CONFIG	+= x86_64
VAA3DPATH = D:/vaa3d_zx
V3DMAINPATH     =  D:/V3D/v3d_external/v3d_main
INCLUDEPATH	+= $$V3DMAINPATH/basic_c_fun
INCLUDEPATH     += $$V3DMAINPATH/common_lib/include
INCLUDEPATH     += $$V3DMAINPATH/v3d
INCLUDEPATH     += $$V3DMAINPATH/3drenderer

LIBS += -L. -llibtiff -L$$V3DMAINPATH/common_lib/winlib64

HEADERS	+= perspective_transformation_plugin.h \
    Camera.h \
    camera_manage.h
SOURCES	+= perspective_transformation_plugin.cpp \
    Camera.cpp \
    camera_manage.cpp

SOURCES	+= $$V3DMAINPATH/basic_c_fun/v3d_message.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/stackutil.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/mg_image_lib.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/mg_utilities.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/basic_memory.cpp

TARGET	= $$qtLibraryTarget(perspective_transformation)
DESTDIR	= $$VAA3DPATH/bin/plugins/perspective_transformation/
