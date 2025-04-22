#!/bin/sh

# 先要安装libudev:sudo apt-get install libudev-dev

gcc main.c\
    ../test.c \
    ../test_iad.c \
    ../test_samevidpid.c \
    ../log.c \
    ../libusb/libusb/core.c \
    ../libusb/libusb/descriptor.c \
    ../libusb/libusb/hotplug.c \
    ../libusb/libusb/io.c \
    ../libusb/libusb/sync.c \
    ../libusb/libusb/strerror.c \
    ../libusb/libusb/os/linux_netlink.c \
    ../libusb/libusb/os/linux_udev.c \
    ../libusb/libusb/os/linux_usbfs.c \
    ../libusb/libusb/os/threads_posix.c \
    ../libusb/libusb/os/events_posix.c \
    ../libuvc/src/ctrl-gen.c \
    ../libuvc/src/ctrl.c \
    ../libuvc/src/device.c \
    ../libuvc/src/diag.c \
    ../libuvc/src/frame.c \
    ../libuvc/src/init.c \
    ../libuvc/src/stream.c \
    -I../ -I. -I../libuvc/include -I../libusb/libusb -I../libusb/libusb/os -lpthread -ludev \
    -D_GNU_SOURCE -DHAVE_CLOCK_GETTIME \
    -DTEST \
    -o test

gcc main.c\
    ../test.c \
    ../test_iad.c \
    ../test_samevidpid.c \
    ../log.c \
    ../libusb/libusb/core.c \
    ../libusb/libusb/descriptor.c \
    ../libusb/libusb/hotplug.c \
    ../libusb/libusb/io.c \
    ../libusb/libusb/sync.c \
    ../libusb/libusb/strerror.c \
    ../libusb/libusb/os/linux_netlink.c \
    ../libusb/libusb/os/linux_udev.c \
    ../libusb/libusb/os/linux_usbfs.c \
    ../libusb/libusb/os/threads_posix.c \
    ../libusb/libusb/os/events_posix.c \
    ../libuvc/src/ctrl-gen.c \
    ../libuvc/src/ctrl.c \
    ../libuvc/src/device.c \
    ../libuvc/src/diag.c \
    ../libuvc/src/frame.c \
    ../libuvc/src/init.c \
    ../libuvc/src/stream.c \
    -I../ -I. -I../libuvc/include -I../libusb/libusb -I../libusb/libusb/os -lpthread -ludev \
    -D_GNU_SOURCE -DHAVE_CLOCK_GETTIME \
    -DTEST_IAD \
    -o test_iad

gcc main.c\
    ../test.c \
    ../test_iad.c \
    ../test_samevidpid.c \
    ../log.c \
    ../libusb/libusb/core.c \
    ../libusb/libusb/descriptor.c \
    ../libusb/libusb/hotplug.c \
    ../libusb/libusb/io.c \
    ../libusb/libusb/sync.c \
    ../libusb/libusb/strerror.c \
    ../libusb/libusb/os/linux_netlink.c \
    ../libusb/libusb/os/linux_udev.c \
    ../libusb/libusb/os/linux_usbfs.c \
    ../libusb/libusb/os/threads_posix.c \
    ../libusb/libusb/os/events_posix.c \
    ../libuvc/src/ctrl-gen.c \
    ../libuvc/src/ctrl.c \
    ../libuvc/src/device.c \
    ../libuvc/src/diag.c \
    ../libuvc/src/frame.c \
    ../libuvc/src/init.c \
    ../libuvc/src/stream.c \
    -I../ -I. -I../libuvc/include -I../libusb/libusb -I../libusb/libusb/os -lpthread -ludev \
    -D_GNU_SOURCE -DHAVE_CLOCK_GETTIME \
    -DTEST_SAMEVIDPID \
    -o test_samevidpid 

chmod +x test
chmod +x test_iad
chmod +x test_samevidpid