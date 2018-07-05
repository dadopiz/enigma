#include <enigma/m4.h>

namespace enigma {

M4::M4(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Rotor& thin_rotor,
       const Reflector& thin_reflector)
    : rotors_{{fast_rotor, midd_rotor, slow_rotor, thin_rotor}}
    , thin_reflector_(thin_reflector)
{}

std::string M4::Translate(const std::string& phrase) {
    std::string result(phrase);

    for(std::size_t i = 0; i < phrase.size(); ++i)
        result[i] = Translate(result[i]);

    return result;
}

void M4::RingStellung(char fast_ring, char midd_ring, char slow_ring, char thin_ring) {
    rotors_[0].RingStellung(fast_ring);
    rotors_[1].RingStellung(midd_ring);
    rotors_[2].RingStellung(slow_ring);
    rotors_[3].RingStellung(thin_ring);
}

void M4::GrundStellung(char fast_offset, char midd_offset, char slow_offset, char thin_offset) {
    rotors_[0].GrundStellung(fast_offset);
    rotors_[1].GrundStellung(midd_offset);
    rotors_[2].GrundStellung(slow_offset);
    rotors_[3].GrundStellung(thin_offset);
}

char M4::Translate(char letter) {
    Turn();

    letter = plugboard_.Translate(letter);

    for(Rotor& rotor : rotors_)
        letter = rotor.TranslateStraight(letter);

    letter = thin_reflector_.Translate(letter);

    for(auto it = rotors_.rbegin(); it != rotors_.rend(); ++it)
        letter = it->TranslateReverse(letter);

    letter = plugboard_.Translate(letter);

    return letter;
}

void M4::ResetPlugboard() {
    plugboard_.Reset();
}

bool M4::Connect(char lhs, char rhs) {
    return plugboard_.Connect(lhs, rhs);
}

void M4::Turn() {
    if(rotors_[1].IsNotch())
        rotors_[2].Turn();

    if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
        rotors_[1].Turn();

    rotors_[0].Turn();
}

}
