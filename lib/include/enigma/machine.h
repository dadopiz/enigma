#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <array>

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

class ENIGMA_API Machine {
public:
    Machine(const Rotor& fast_rotor,
            const Rotor& midd_rotor,
            const Rotor& slow_rotor,
            const Reflector& reflector);

    char Translate(char letter);

    void RingStellung(char fast_ring, char midd_ring, char slow_ring);

    void GrundStellung(char fast_offset, char midd_offset, char slow_offset);

private:
    void Turn();

    std::array<Rotor, 3> rotors_;
    Reflector reflector_;
};

}

#endif // ENIGMA_MACHINE_H
