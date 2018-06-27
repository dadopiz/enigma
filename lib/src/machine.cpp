#include <enigma/machine.h>

namespace enigma {

Machine::Machine(const std::array<Rotor, 3>& rotors)
    : rotors_(rotors)
{}

char Machine::TranslateStraight(char letter) {
    for(Rotor& rotor : rotors_)
        letter = rotor.TranslateStraight(letter);

    return letter;
}

char Machine::TranslateReverse(char letter) {
    for(auto it = rotors_.rbegin(); it != rotors_.rend(); ++it)
        letter = it->TranslateReverse(letter);

    return letter;
}

void Machine::RingStellung(const std::array<char, 3>& rings) {
    for(std::size_t i = 0; i < 3; ++i)
        rotors_[i].RingStellung(rings[i]);
}

void Machine::GrundStellung(const std::array<char, 3>& offsets) {
    for(std::size_t i = 0; i < 3; ++i)
        rotors_[i].GrundStellung(offsets[i]);
}

void Machine::Turn() {
    if(rotors_[1].IsNotch())
        rotors_[2].Turn();

    if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
        rotors_[1].Turn();

    rotors_[0].Turn();
}

}
