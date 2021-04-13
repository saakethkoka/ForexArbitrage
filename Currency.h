//
// Created by Saaketh Koka on 4/13/21.
//
#pragma once
#include <string>

class Currency{
private:
    std::string curr_name;
    double ratio;

public:
    Currency(const std::string& name = "",const double& rate = 1.0);
    bool operator== (const Currency& other) const;

    std::string& get_name();
    double& get_ratio();

};


