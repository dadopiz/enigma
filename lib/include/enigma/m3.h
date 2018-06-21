#ifndef ENIGMA_M3_H
#define ENIGMA_M3_H

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

class ENIGMA_API M3 {
public:
    M3(std::array<Rotor, 3> rotors, Reflector reflector);

    char Translate(char letter);

private:
    void Turn();

    std::array<Rotor, 3> rotors_;
    Reflector reflector_;
};

}

#endif // ENIGMA_M3_H
