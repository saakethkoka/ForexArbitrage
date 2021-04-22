//
// Created by Ray Irani on 4/20/21.
//

#include "Runner.h"

Runner::Runner(std::string input) {
    std::cout << "Hello Good Sir,\n" << "how much would you like to invest today?\n" << "$";
    std::string holder;
    std::string amount;
    double amountDouble;
    double profit = 0;
    std::cin >> amount;
    try{
        amountDouble = std::stod(amount);
    } catch (std::invalid_argument){
        std::cout << "Shame on you." << std::endl;
        return;
    }
    do{
        Pathfinder pf(input);
        profit = pf.printPath(amountDouble,profit);
        amountDouble *= pf.getBestROI();
        std::cout << "Would you like to reinvest? (Y/N)" << std::endl;
        std::cin >> holder;
    } while(holder == "Y" || holder == "y");
}
