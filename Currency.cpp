//
// Created by Saaketh Koka on 4/13/21.
//
#include "Currency.h"

Currency::Currency(const std::string &name, const double &rate) {
    this->curr_name = name;
    this->ratio = rate;
}

bool Currency::operator==(const Currency &other) const {
    return this->curr_name == other.curr_name;
}

std::string &Currency::get_name() {
    return curr_name;
}

double &Currency::get_ratio() {
    return ratio;
}

bool Currency::operator!=(const Currency &other) const {
    return this->curr_name != other.curr_name;
}

std::ostream &operator<<(std::ostream &out, const Currency &data) {
    out << "(" << data.curr_name.c_str() << ", " << data.ratio << ")";
    return out;
}
