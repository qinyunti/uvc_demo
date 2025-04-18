#include <stdio.h>
#include "libuvc/libuvc.h"
#include <windows.h>

static void cb(uvc_frame_t *frame, void *ptr) {
    uvc_frame_t *bgr;
    uvc_error_t ret;

    printf("callback! length = %zu, ptr = %p\n", frame->data_bytes, ptr);

    bgr = uvc_allocate_frame(frame->width * frame->height * 3);
    if (!bgr) {
        printf("unable to allocate bgr frame!");
        return;
    }

    /* 格式解析 */
    ret = uvc_any2bgr(frame, bgr);
    if (ret) {
        uvc_perror(ret, "uvc_any2bgr");
        uvc_free_frame(bgr);
        return;
    }
    // 显示等操作
    uvc_free_frame(bgr);
}

int test_main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    uvc_context_t *ctx;
    uvc_error_t res;
    uvc_device_t *dev;
    uvc_device_handle_t *devh;
    uvc_stream_ctrl_t ctrl;

    res = uvc_init(&ctx, NULL);

    if (res < 0) {
        uvc_perror(res, "uvc_init");
        return res;
    }

    printf("UVC initialized");

    res = uvc_find_device(
        ctx, &dev,
        0x1993, 0x0101, NULL);

    if (res < 0) {
        uvc_perror(res, "uvc_find_device");
    } else {
        printf("Device found");

        res = uvc_open(dev, &devh);

        if (res < 0) {
            uvc_perror(res, "uvc_open");
        } else {
            printf("Device opened");

            uvc_print_diag(devh, stderr);

            res = uvc_get_stream_ctrl_format_size(
                devh, &ctrl, UVC_FRAME_FORMAT_MJPEG, 1280, 720, 0
                );

            uvc_print_stream_ctrl(&ctrl, stderr);

            if (res < 0) {
                uvc_perror(res, "get_mode");
            } else {
                res = uvc_start_streaming(devh, &ctrl, cb, (void*)1234, 0);

                if (res < 0) {
                    uvc_perror(res, "start_streaming");
                } else {
                    printf("Streaming for 10 seconds...");
                    Sleep(10000);
                    uvc_stop_streaming(devh);
                    printf("Done streaming.");
                }
            }

            uvc_close(devh);
            printf("Device closed");
        }

        uvc_unref_device(dev);
    }

    uvc_exit(ctx);
    printf("UVC exited");

    return 0;
}
