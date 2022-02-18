
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
#CONFIG	+= x86_64
VAA3DPATH = D:/vaa3d_zx
V3DMAINPATH     =  D:/V3D/v3d_external/v3d_main
INCLUDEPATH	+= $$V3DMAINPATH/basic_c_fun
INCLUDEPATH     += $$V3DMAINPATH/common_lib/include

LIBS += -L. -llibtiff -L$$V3DMAINPATH/common_lib/winlib64

HEADERS	+= tiffmix_plugin.h \
    func.h \
    mydialog.h \
    externs.h \
    glbs.h
SOURCES	+= tiffmix_plugin.cpp \
    func.cpp \
    mydialog.cpp

SOURCES	+= $$V3DMAINPATH/basic_c_fun/v3d_message.cpp
SOURCES	+= $$V3DMAINPATH/basic_c_fun/v3d_message.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/stackutil.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/mg_image_lib.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/mg_utilities.cpp
SOURCES += $$V3DMAINPATH/basic_c_fun/basic_memory.cpp

TARGET	= $$qtLibraryTarget(tiffmix)
DESTDIR	= $$VAA3DPATH/bin/plugins/tiffmix/
