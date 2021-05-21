#pragma once

#include<iostream>
using namespace std;
#include<assert.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

#ifdef LINUX

#elif
#include<Windows.h>
#endif


typedef unsigned char u_char;
typedef unsigned long u_long;

void Log(int log_level,const char* file_name,int line_num,const char *forma);