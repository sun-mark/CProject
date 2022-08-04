//
// Created by Administrator on 2022/7/26 0026.
//
#include <stdio.h>
#include <stdarg.h>

#ifndef HELLOWORLDC_IO_UTILS_H
#define HELLOWORLDC_IO_UTILS_H
#define DEBUG
#ifdef DEBUG
#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s : "format"\n",__LINE__,__FUNCTION__,##__VA_ARGS__)
#else
#define PRINTLNF(format, ...) printf(format"\n",##__VA_ARGS__)
#endif

#define PRINTLN_INT(format) PRINTLNF("%d",format)
#define PRINTLN_HEX(format) PRINTLNF("%x",format)
#define PRINTLN_LONG(format) PRINTLNF("%ld",format)
#define PRINTLN_LONG_LONG(format) PRINTLNF("%lld",format)
#define PRINTLN_CHART(format) PRINTLNF("%c",format)
#endif  //HELLOWORLDC_IO_UTILS_H
