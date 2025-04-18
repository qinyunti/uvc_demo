# 打开工程

    打开QT Creator
    [文件]->[打开文件或项目] 打开uvc.pro
    点击Configure Project


# 构建

    [构建]->[构建项目"UVC"]


# 测试
    单UVC设备
    main.cpp中执行test_main(0, 0); 
    IAD多UVC设备
    main.cpp中执行test_iad_main(0,0);

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