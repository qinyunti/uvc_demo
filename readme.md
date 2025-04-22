# windows下

## 打开工程

    打开QT Creator
    [文件]->[打开文件或项目] 打开uvc.pro
    点击Configure Project


## 构建

    [构建]->[构建项目"UVC"]


## 测试
    单UVC设备
    main.cpp中执行test_main(0, 0); 
    IAD多UVC设备
    main.cpp中执行test_iad_main(0,0);
    同VIDPID多UVC设备
    main.cpp中执行test_samevidpid_main(0,0);

    修改以下的PID VID

```
    res = uvc_find_device(
        ctx, &dev,
        0x1993, 0x0101, NULL);
```
    修改以下的分辨率和格式
```
            res = uvc_get_stream_ctrl_format_size(
                devh, &ctrl, UVC_FRAME_FORMAT_MJPEG, 1280, 720, 0
                );
```

# linux下

## 构建
    进入`uvc/Linux`下执行`chmod +x build.sh`和`./build.sh`。

## 测试
    分别执行`./test`,`./test_iad`,`./test_samevidpid`进行测试。

## WSL下使用USBIPD测试

`Windows`下打开`PowerShell`，输入以下命令安装`usbipd` </br>
`winget install usbipd` </br>
输入`usbipd list`查看设备 </br>

我这里3-2,3-3接的是UVC设备
```
PS C:\Users\qinyu> usbipd list
Connected:
BUSID  VID:PID    DEVICE                                                        STATE
2-1    0cf3:e300  Qualcomm Atheros QCA61x4 Bluetooth                            Not shared
2-2    13d3:56ba  Integrated Camera, Integrated IR Camera                       Not shared
3-2    1993:0101  WUQI.UVC (Interface 0)                                        Not shared
3-3    1993:0101  WUQI.UVC (Interface 0)                                        Not shared
3-4    1a81:1021  USB 输入设备                                                  Not shared

Persisted:
GUID                                  DEVICE
1b99ab57-50c3-4164-bd22-77fa811f7a58  UVC1, UVC2
48923770-bbc7-41f5-b7d8-0d36bf0680d0  USB 输入设备
63f2955e-0e6e-4879-ad6c-1e714ea0658b  USB 串行设备 (COM12)
74f74f56-eaef-48dc-9b2b-d54b98a9e4b2  UVC1, UVC2
79511c5c-11a3-493a-ae19-144e11f714f2  UVC1, UVC2
9611c995-8cb4-43b7-adeb-f5317ab752a1  WUQI.UVC
e8186ff6-fd87-46ed-8e68-17d6cedcee26  USB Composite Device
```

然后输入`usbipd bind -b 3-2`和`usbipd bind -b 3-3`绑定该设备到`usbipd`

此时再输入`usbipd list`查看，该设备状态就变为了`shared`
```
PS C:\Users\qinyu> usbipd list
Connected:
BUSID  VID:PID    DEVICE                                                        STATE
2-1    0cf3:e300  Qualcomm Atheros QCA61x4 Bluetooth                            Not shared
2-2    13d3:56ba  Integrated Camera, Integrated IR Camera                       Not shared
3-2    1993:0101  WUQI.UVC (Interface 0)                                        Shared
3-3    1993:0101  WUQI.UVC (Interface 0)                                        Shared
3-4    1a81:1021  USB 输入设备                                                  Not shared

Persisted:
GUID                                  DEVICE
1b99ab57-50c3-4164-bd22-77fa811f7a58  UVC1, UVC2
48923770-bbc7-41f5-b7d8-0d36bf0680d0  USB 输入设备
63f2955e-0e6e-4879-ad6c-1e714ea0658b  USB 串行设备 (COM12)
74f74f56-eaef-48dc-9b2b-d54b98a9e4b2  UVC1, UVC2
79511c5c-11a3-493a-ae19-144e11f714f2  UVC1, UVC2
9611c995-8cb4-43b7-adeb-f5317ab752a1  WUQI.UVC
e8186ff6-fd87-46ed-8e68-17d6cedcee26  USB Composite Device
```

再输入`usbipd attach -w -b 3-2`和`usbipd attach -w -b 3-3`将设备连接到`WSL`中去(注意此时`WSL`需要运行，即至少要先开一个`WSL`终端). <.br>
```
PS C:\Users\qinyu> usbipd attach -w -b 3-2
usbipd: info: Using WSL distribution 'Ubuntu' to attach; the device will be available in all WSL 2 distributions.
usbipd: info: Using IP address 172.31.240.1 to reach the host.
PS C:\Users\qinyu> usbipd attach -w -b 3-3
usbipd: info: Using WSL distribution 'Ubuntu' to attach; the device will be available in all WSL 2 distributions.
usbipd: info: Using IP address 172.31.240.1 to reach the host.
PS C:\Users\qinyu>
```

此时`wsl`中`lsusb`就可以看到该设备了。</br>
```
qinyunti@qinyunti:/mnt/c/Users/qinyu/Desktop/libuvc_mdev/uvc_demo$ lsusb
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 003: ID 1993:0101 WUQI.Technology WUQI.UVC
Bus 001 Device 002: ID 1993:0101 WUQI.Technology WUQI.UVC
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
qinyunti@qinyunti:/mnt/c/Users/qinyu/Desktop/libuvc_mdev/uvc_demo$
```




