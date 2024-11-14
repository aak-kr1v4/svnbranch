#ifndef LOG_WRAPPER_HPP
#define LOG_WRAPPER_HPP

#include <spdlog/spdlog.h>

    #ifdef NDEBUG
    
    #define LOG_INFO(...)
    #define LOG_WARN(...)
    #define LOG_ERROR(...)
    #define LOG_CRITICAL(...)
    
    #else
    
    #define LOG_INFO(...)       spdlog::info(__VA_ARGS__)
    #define LOG_WARN(...)       spdlog::warn(__VA_ARGS__)
    #define LOG_ERROR(...)      spdlog::error(__VA_ARGS__)
    #define LOG_CRITICAL(...)   spdlog::critical(__VA_ARGS__)
    
    #endif

#endif