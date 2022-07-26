//
// Created by Administrator on 2022/7/26 0026.
//
#include <stdio.h>
#include <stdarg.h>

#ifndef HELLOWORLDC_IO_UTILS_H
#define HELLOWORLDC_IO_UTILS_H
#define PRINTLNF(format, ...) printf(format"\n",##__VA_ARGS__)
#endif  //HELLOWORLDC_IO_UTILS_H
