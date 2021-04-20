#include <iostream>
#include "Pathfinder.h"
int main(int argc, char* argv[]) {
    std::cout << "Hello Good Sir,\n" << "how much would you like to invest today?\n" << "$";
    int amount;
    std::cin >> amount;
    Pathfinder pf(argv[1]);
    pf.printPath(amount);
    return 0;
}
