#include <iostream>

#include <enigma/enigma.h>

int main(int, const char**) {
    enigma::Reflector custom_reflector("QWERTYUIOPASDFGHJKLZXCVBNM");
    std::cout << "custom_reflector translate Z in... "
              << custom_reflector.Translate('Z')
              << std::endl;

    auto historical_reflector = enigma::historical::reflector::B;
    std::cout << "historical_reflector translate Z in... "
              << historical_reflector.Translate('Z')
              << std::endl;

    return 0;
}
