#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <array>

#include <enigma/global.h>
#include <enigma/utils.h>
#include <enigma/rotor.h>

namespace enigma {

class ENIGMA_API Machine {
public:
    Machine(const std::array<Rotor, 3>& rotors);

    char TranslateStraight(char letter);

    char TranslateReverse(char letter);

    void RingStellung(const std::array<char, 3>& rings);

    void GrundStellung(const std::array<char, 3>& offsets);

    void Turn();

private:
    std::array<Rotor, 3> rotors_;
};

}

#endif // ENIGMA_MACHINE_H
