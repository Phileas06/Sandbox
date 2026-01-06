#include <iostream>

#include "Fahrzeug.h"

std::ostream& operator<<(std::ostream& ostream, const Fahrzeug fz) {
    return ostream << fz.p_dTestValue;
};

int main() {
    Fahrzeug objekt1;
    std::cout << objekt1;
    return 0;
}