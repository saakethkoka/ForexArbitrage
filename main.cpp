#include <iostream>
#include "Pathfinder.h"
int main(int argc, char* argv[]) {
    std::cout << "Hello Good Sir,\n" << "how much would you like to invest today?\n" << "$";
    std::string holder;
    double amount;
    std::cin >> amount;
    do{
        Pathfinder pf(argv[1]);
        pf.printPath(amount);
        amount *= pf.getBestROI();
        std::cout << "Would you like to reinvest? (Y/N)" << std::endl;
        std::cin >> holder;
    } while(holder == "Y" || holder == "y");
    return 0;
}
