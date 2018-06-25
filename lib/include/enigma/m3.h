#ifndef ENIGMA_M3_H
#define ENIGMA_M3_H

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>
#include <enigma/plugboard.h>

namespace enigma {

class ENIGMA_API M3 {
public:
    M3(const Rotor& fast_rotor
       , const Rotor& midd_rotor
       , const Rotor& slow_rotor
       , const Reflector& reflector);

    char Translate(char letter);

    void RingStellung(char fast_ring, char midd_ring, char slow_ring);

    void GrundStellung(char fast_offset, char midd_offset, char slow_offset);

    void Reset();

    bool Connect(char lhs, char rhs);

private:
    void Turn();

    std::array<Rotor, 3> rotors_;
    Reflector reflector_;
    Plugboard plugboard_;
};

}

#endif // ENIGMA_M3_H
