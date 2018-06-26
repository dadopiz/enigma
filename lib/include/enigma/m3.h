#ifndef ENIGMA_M3_H
#define ENIGMA_M3_H

#include <enigma/global.h>
#include <enigma/machine.h>
#include <enigma/plugboard.h>

namespace enigma {

class ENIGMA_API M3 {
public:
    M3(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Reflector& reflector);

    char Translate(char letter);

    std::string Translate(const std::string& phrase);

    void RingStellung(char fast_ring, char midd_ring, char slow_ring);

    void GrundStellung(char fast_offset, char midd_offset, char slow_offset);

    void ResetPlugboard();

    bool Connect(char lhs, char rhs);

private:
    Machine<3> machine_;
    Plugboard plugboard_;
};

}

#endif // ENIGMA_M3_H
