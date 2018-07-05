#include <iostream>
#include <algorithm>

#include <enigma/enigma.h>

std::string format_input(const std::string& text) {
    std::string str(text);

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    str.erase(std::remove_if(str.begin(), str.end(), [](char x)
    {
        return !enigma::is_valid(x);
    }), str.end());

    return str;
}

std::string format_output(const std::string& text) {
    std::string str(text);
    for(std::size_t i = 1; i < str.size(); ++i)
        if(i % 5 == 0)
            str.insert(i - 1, 1, ' ');
    return str;
}

int main(int, const char**) {
    using enigma::historical::rotor;

    enigma::Reflector custom_reflector("QWERTYUIOPASDFGHJKLZXCVBNM");
    enigma::M3 machine(rotor::III, rotor::II, rotor::I, custom_reflector);

    std::cout << "Enigma, say hello:" << std::endl;

    std::string hello = "Hello, World!";
    hello = format_input(hello);
    hello = machine.Translate(hello);
    hello = format_output(hello);

    std::cout << hello << std::endl;

    return 0;
}
