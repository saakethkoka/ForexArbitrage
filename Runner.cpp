//
// Created by Ray Irani on 4/20/21.
//

#include "Runner.h"

Runner::Runner(std::string input) {
    std::cout << "Hello Good Sir,\n" << "how much would you like to invest today?\n" << "$";
    std::string holder;
    double amount;
    double profit = 0;
    std::cin >> amount;
    do{
        Pathfinder pf(input);
        profit = pf.printPath(amount,profit);
        amount *= pf.getBestROI();
        std::cout << "Would you like to reinvest? (Y/N)" << std::endl;
        std::cin >> holder;
    } while(holder == "Y" || holder == "y");
}
