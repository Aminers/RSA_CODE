#pragma once
#ifndef WINDOW_CODE
#define WINDOW_CODE
#include "Math.h"//自己编写的文件，包含生成素数的函数
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
char numBuf[102];
long long p, q,e, d, plainText,cipherText;
Fl_Output *showP,*showQ,*showN,*showFn,*showE,*showD,*showEnCodeText,*showDeCodeText;
Fl_Input *plainText_IN, *cipherText_IN;

#endif // !WINDOW_CODE
