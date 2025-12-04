#include "app.hpp"

#include <iostream>

#include "day01/day01.cpp"
#include "day02/day02.cpp"

int main() {
    try {
        Day02 day;
        day.solve();
    } catch(const std::runtime_error& e) {
        std::cerr << "Caught an error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}