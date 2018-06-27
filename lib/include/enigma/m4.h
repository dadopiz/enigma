#ifndef ENIGMA_M4_H
#define ENIGMA_M4_H

#include <enigma/global.h>
#include <enigma/machine.h>
#include <enigma/reflector.h>
#include <enigma/plugboard.h>

namespace enigma {

namespace historical {

class ENIGMA_API M4 {
public:
    M4(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Rotor& thin_rotor,
       const Reflector& thin_reflector);

    std::string Translate(const std::string& phrase);

    char Translate(char letter);

    void RingStellung(char fast_ring, char midd_ring, char slow_ring, char thin_ring);

    void GrundStellung(char fast_offset, char midd_offset, char slow_offset, char thin_offset);

    void ResetPlugboard();

    bool Connect(char lhs, char rhs);

private:
    Machine machine_;
    Rotor thin_rotor_;
    Reflector thin_reflector_;
    Plugboard plugboard_;
};

}

}

#endif // ENIGMA_M4_H
