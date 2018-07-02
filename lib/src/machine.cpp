#include <enigma/machine.h>

namespace enigma {

Machine::Machine(const Rotor& fast_rotor,
                 const Rotor& midd_rotor,
                 const Rotor& slow_rotor,
                 const Reflector& reflector)
    : rotors_({{fast_rotor, midd_rotor, slow_rotor}})
    , reflector_(reflector)
{}

char Machine::Translate(char letter) {
    Turn();

    for(Rotor& rotor : rotors_)
        letter = rotor.TranslateStraight(letter);

    letter = reflector_.Translate(letter);

    for(auto it = rotors_.rbegin(); it != rotors_.rend(); ++it)
        letter = it->TranslateReverse(letter);

    return letter;
}

void Machine::RingStellung(char fast_ring, char midd_ring, char slow_ring) {
    rotors_[0].RingStellung(fast_ring);
    rotors_[1].RingStellung(midd_ring);
    rotors_[2].RingStellung(slow_ring);
}

void Machine::GrundStellung(char fast_offset, char midd_offset, char slow_offset) {
    rotors_[0].GrundStellung(fast_offset);
    rotors_[1].GrundStellung(midd_offset);
    rotors_[2].GrundStellung(slow_offset);
}

void Machine::Turn() {
    if(rotors_[1].IsNotch())
        rotors_[2].Turn();

    if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
        rotors_[1].Turn();

    rotors_[0].Turn();
}

}
