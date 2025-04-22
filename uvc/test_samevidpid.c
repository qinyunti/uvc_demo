#include <stdio.h>
#include "libuvc/libuvc.h"

#ifdef _WIN32
#include <windows.h>
static void delay_ms(int ms)
{
    Sleep(ms);
}
#elif __linux__
#include <unistd.h>
static void delay_ms(int ms)
{
    usleep(ms*1000);
}
#else
#error "Unknown compiler"
#endif

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

int test_samevidpid_main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    uvc_context_t *ctx;
    uvc_error_t res;
    uvc_device_t **devs = NULL;
    uvc_device_handle_t *devh[2]={NULL,NULL};
    uvc_stream_ctrl_t ctrl[2];
    int dev_num = 0;
    res = uvc_init(&ctx, NULL);

    if (res < 0) {
        uvc_perror(res, "uvc_init");
        return res;
    }

    printf("UVC initialized\r\n");

    res = uvc_find_devices(
        ctx, &devs,
        0x1993, 0x0101, NULL);

    if(devs == NULL){
        uvc_exit(ctx);
        printf("no device founded");
        return -1;
    }

    for(int i=0; ; i++){
        if(devs[i] != NULL){
            dev_num++;
        }else{
            break;
        }
    }

    if (res < 0)
    {
        uvc_perror(res, "uvc_find_devices");
    }
    else
    {
        printf("Device found\r\n");
        for(long i=0; i<dev_num; i++)
        {
            res = uvc_open(devs[i], &devh[i]);
            if (res < 0)
            {
                uvc_perror(res, "uvc_open");
            }
            else
            {
                printf("Device opened %d\r\n",dev_num);

                uvc_print_diag(devh[i], stderr);

                res = uvc_get_stream_ctrl_format_size(
                    devh[i], &ctrl[i], UVC_FRAME_FORMAT_MJPEG, 1280, 720, 0
                    );

                uvc_print_stream_ctrl(&ctrl[i], stderr);

                if (res < 0)
                {
                    uvc_perror(res, "get_mode");
                }
                else
                {
                    res = uvc_start_streaming(devh[i], &ctrl[i], cb, (void*)i, 0);

                    if (res < 0)
                    {
                        uvc_perror(res, "start_streaming");
                    }
                    else
                    {
                        printf("Streaming for 10 seconds...");
                    }
                }
            }
        }

        delay_ms(10000);

        for(int i=0; i<dev_num; i++)
        {
            uvc_stop_streaming(devh[i]);
            printf("Done streaming %d.\r\n",i);
        }

        for(int i=0; i<dev_num; i++)
        {
            uvc_close(devh[i]);
            printf("Device %d closed\r\n",i);
        }

        for(int i=0; i<dev_num; i++)
        {
            uvc_unref_device(devs[i]);
        }
    }

    uvc_exit(ctx);
    printf("UVC exited");

    return 0;
}
