#include "app.hpp"

#include <iostream>

#include "day00/day00.cpp"
#include "day02/day02.cpp"
#include "day04/day04.cpp"
#include "day06/day06.cpp"

int main() {
    try {
        Day06 day;
        day.solve();
    } catch(const std::runtime_error& e) {
        std::cerr << "Caught an error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}