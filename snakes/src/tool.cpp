//
// Created by Dragon on 2020/5/27.
//

#include "../include/tool.h"
#include <cstdio>
#include <cstdlib>
#include <conio.h>

// 设置光标位置
void Tool::setCurPos(const int x, const int y) {
#ifdef OS_WIN
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(out, coord);
#elif defined(OS_UNIX)
    printf("\033[%s\033[0m",str.c_str());
#endif
}
void Tool::write(const std::string &str) {
#ifdef OS_WIN
    printf("%s", str.c_str());
#elif defined(OS_UNIX)
    printf("\033[%s\033[0m",str.c_str());
#endif
}
void Tool::clear() {
#ifdef OS_WIN
    if (system("cls")) {}
#elif defined(OS_UNIX)
    if (system("clear")) {}
#endif
}
char Tool::getCh() {
#ifdef OS_WIN
    return _getch();
#elif defined(OS_UNIX)
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
#endif
}
void Tool::mySetColor(int a) {
#ifdef OS_WIN
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
    //printf("%s", str.c_str());
    //resetColor(originAttr);  // Reset to origin output color
#elif defined(OS_UNIX)
    printf("\033[%s\033[0m",str.c_str());
#endif
}

void Tool::setWinSize(const int col, const int row) {
#ifdef OS_WIN
    //system("title snake");//
    char cmd[30];
    //cmd = new char(row-2);
    sprintf(cmd, "mode con cols=%d lines=%d", col*2+2, row*2);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
#endif
}
int Tool::myKbhit() {
#ifdef OS_WIN
    return _kbhit();
#elif defined(OS_UNIX)
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif
}
