QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 config console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    test.c \
    test_iad.c \
    log.c \
    main.cpp \
    mainwindow.cpp \
    libusb/libusb/core.c \
    libusb/libusb/descriptor.c \
    libusb/libusb/hotplug.c \
    libusb/libusb/io.c \
    libusb/libusb/sync.c \
    libusb/libusb/strerror.c \
    libusb/libusb/os/events_windows.c \
    libusb/libusb/os/threads_windows.c \
    libusb/libusb/os/windows_common.c \
    libusb/libusb/os/windows_usbdk.c \
    libusb/libusb/os/windows_winusb.c \
    libuvc/src/ctrl-gen.c \
    libuvc/src/ctrl.c \
    libuvc/src/device.c \
    libuvc/src/diag.c \
    libuvc/src/frame.c \
    libuvc/src/init.c \
    libuvc/src/stream.c \

HEADERS += \
    test.h \
    log.h \
    mainwindow.h \
    libusb/libusb/config.h \
    libusb/libusb/libusb.h \
    libusb/libusb/libusbi.h \
    libusb/libusb/version.h \
    libusb/libusb/version_nano.h \
    libusb/libusb/os/events_windows.h \
    libusb/libusb/os/threads_windows.h \
    libusb/libusb/os/windows_common.h \
    libusb/libusb/os/windows_usbdk.h \
    libusb/libusb/os/windows_winusb.h \
    libuvc/include/utlist.h \
    libuvc/include/libuvc/libuvc.h \
    libuvc/include/libuvc/libuvc_config.h \
    libuvc/include/libuvc/libuvc_internal.h \

INCLUDEPATH += libusb/libusb/
INCLUDEPATH += libusb/libusb/os/
INCLUDEPATH += libuvc/include/
INCLUDEPATH += ./

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
