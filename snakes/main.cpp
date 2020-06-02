
#include "include/ctrl.h"
#include <iostream>
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Ctrl* g = new Ctrl();
    //g ->setMapSize(10, 10);
    g->game();
    delete g;
    return 0;
}
