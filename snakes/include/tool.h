//
// Created by Dragon on 2020/5/27.
//

#ifndef SNAKES_TOOL_H
#define SNAKES_TOOL_H

#include <string>
#if defined(WIN32)||defined(_WIN32)

#include <Windows.h>
#define OS_WIN
#endif //SNAKES_TOOL_H

class Tool{
public:
    static void setCurPos(const int x = 0, const int y = 0);
    static void write(const std::string &str);
    static void clear();
    static char getCh();
    static void mySetColor(int a);
    static void setWinSize(const int col, const int row);      // windows 下设置窗口大小
    static int myKbhit();
    //void setColor(int id);

};

#endif