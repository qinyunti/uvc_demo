#include <stdio.h>
#include <stdarg.h>

#include "log.h"

/**
 * @brief s_log_state 各模块当前的日志等级记录
 */
LOG_LEVEL_e s_log_state[LOG_MODULE_MAX]={LOG_LEVEL_WARNING,LOG_LEVEL_WARNING,LOG_LEVEL_WARNING,LOG_LEVEL_WARNING,LOG_LEVEL_WARNING,LOG_LEVEL_WARNING,LOG_LEVEL_WARNING};

/**
 * @fn log_out
 * @brief 日志输出
 * @param module 日志模块
 * @param level 日志等级
 * @param fmt 格式化字符串
 */
void log_out(LOG_MODULE_e module, LOG_LEVEL_e level, const char * fmt, ...)
{
    if(level <= s_log_state[module])
    {
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}

/**
 * @fn log_set_level
 * @brief 设置指定模块的日志等级
 * @param module 模块
 * @param level 日志等级
 */
void log_set_level(LOG_MODULE_e module, LOG_LEVEL_e level)
{
    s_log_state[module] = level;
}

/**
 * @fn log_get_level
 * @brief 获取指定模块的日志等级
 * @param module 模块
 * @return LOG_LEVEL_e 日志等级
 */
LOG_LEVEL_e log_get_level(LOG_MODULE_e module)
{
    return s_log_state[module];
}
