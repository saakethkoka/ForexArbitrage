//
// Created by Saaketh Koka on 4/13/21.
//



#pragma once
#include "Currency.h"
#include <sstream>
#include <fstream>
#include "DSAdjacencyList.h"
#include <vector>


class DocumentParser {
private:
DSAdjacencyList<Currency> currencyMatrix;
std::vector<std::string> vect;

public:
    DocumentParser(std::string filename);
    void parseLine(std::string& line);

};

