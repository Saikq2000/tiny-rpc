#pragma once
#include "lockqueue.h"
#include <string>
namespace mprpc { 
// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define MPRPC_LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        mprpc::Logger &logger = mprpc::Logger::GetInstance(); \
        logger.SetLogLevel(mprpc::INFO); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c); \
    } while(0) \

#define MPRPC_LOG_ERR(logmsgformat, ...) \
    do \
    {  \
        mprpc::Logger &logger = mprpc::Logger::GetInstance(); \
        logger.SetLogLevel(mprpc::ERROR); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c); \
    } while(0) \

// 定义日志级别
enum LogLevel
{
    INFO,  // 普通信息
    ERROR, // 错误信息
};

// Mprpc框架提供的日志系统
class Logger
{
public:
    // 获取日志的单例
    static Logger& GetInstance();
    // 设置日志级别 
    void SetLogLevel(LogLevel level);
    // 写日志
    void Log(std::string msg);
private:
    int m_loglevel; // 记录日志级别
    LockQueue<std::string>  m_lckQue; // 日志缓冲队列

    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
};
}