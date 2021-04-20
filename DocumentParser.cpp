//
// Created by Saaketh Koka on 4/13/21.
//

#include "DocumentParser.h"

DocumentParser::DocumentParser(std::string filename) {
    vect = {"USD","EUR","GBP","CNY","CHF","JPY","AUD","CAD","HKD","SGD"};
    std::fstream infs(filename);
    if(!infs.is_open()){
        std::cout << "File not opened: " << filename << std::endl;
        assert(false);
    }
    std::string trash;
    getline(infs, trash); //reads the first line which is not processed
    getline(infs, trash); //reads the second line which is not processed
    getline(infs, trash); //reads the thrid line which is not processed
    int i = 0;
    while(!infs.eof()){
        if(infs.eof()){
            break;
        }
        std::string line;
        getline(infs,line);
        this->parseLine(line);
        i++;
    }
    infs.close();
}


void DocumentParser::parseLine(std::string& line){
    short indexOfComma = line.find(",");
    for(int j = 0; j < 10; j++){
        line.replace(indexOfComma, 1, " "); // Removes commas from the line
        indexOfComma = line.find(",", indexOfComma); // Finds the 6 commas
    }
    std::stringstream inss(line);

    std::string currencyOfOrgin;
    inss >> currencyOfOrgin;
    for(int q = 0; q < 10; q++){
        std::string eachRateString;
        inss >> eachRateString;
        if(eachRateString == "-"){
            continue;
        }
        double rate = std::stod(eachRateString);
        currencyMatrix.addOneWayEdge(Currency(currencyOfOrgin, 1),Currency(vect[q], rate));
    }



}

DSAdjacencyList<Currency> &DocumentParser::getAdjacencyList() {
    return currencyMatrix;
}
