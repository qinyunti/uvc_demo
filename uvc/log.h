#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum LOG_MODULE_e
 * @brief 日志模块枚举
 */
typedef enum
{
    LOG_MODULE_TX = 0,
    LOG_MODULE_RX = 1,
    LOG_MODULE_CTRL = 2,
    LOG_MODULE_DEV = 3,
    LOG_MODULE_LIBUSB = 4,
    LOG_MODULE_SAVE = 5,
    LOG_MODULE_FRAME = 6,
    LOG_MODULE_MAX,
} LOG_MODULE_e;

/**
 * @enum LOG_LEVEL_e
 * @brief 日志等级枚举
 */
typedef enum
{
    LOG_LEVEL_OFF = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_MAX = 5,
} LOG_LEVEL_e;

/**
 * @fn log_out
 * @brief 日志输出
 * @param module 日志模块
 * @param level 日志等级
 * @param fmt 格式化字符串
 */
void log_out(LOG_MODULE_e module, LOG_LEVEL_e level, const char * fmt, ...);

/**
 * @fn log_set_level
 * @brief 设置指定模块的日志等级
 * @param module 模块
 * @param level 日志等级
 */
void log_set_level(LOG_MODULE_e module, LOG_LEVEL_e level);

/**
 * @fn log_get_level
 * @brief 获取指定模块的日志等级
 * @param module 模块
 * @return LOG_LEVEL_e 日志等级
 */
LOG_LEVEL_e log_get_level(LOG_MODULE_e module);

#ifdef __cplusplus
}
#endif

#endif
