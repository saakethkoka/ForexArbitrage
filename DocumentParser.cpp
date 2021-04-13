//
// Created by Saaketh Koka on 4/13/21.
//

#include "DocumentParser.h"

DocumentParser::DocumentParser(std::string filename) {
    std::fstream infs(filename);
    if(!infs.is_open()){
        std::cout << "File not opened: " << filename << std::endl;
        assert(false);
    }
    std::string first_line;
    getline(infs, first_line); //reads the first line which is not processed
    while(!infs.eof()){
        if(infs.eof()){
            break;
        }
        std::string line;
        getline(infs,line);
        this->parseLine(line);
    }

    infs.close();
}


void DocumentParser::parseLine(std::string& line){
    short indexOfComma = line.find(",");
    for(int i = 0; i < 6; i++){
        line.replace(indexOfComma, 1, " "); // Removes commas from the line
        indexOfComma = line.find(",", indexOfComma); // Finds the 6 commas
        std::cout << indexOfComma << std::endl;
    }

    double USD,EUR,GBP,CNY,CHF,JPY,AUD,CAD,HKD,SGD;
}