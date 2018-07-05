#include <enigma/m3.h>

namespace enigma {

M3::M3(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Reflector& reflector)
    : rotors_{{fast_rotor, midd_rotor, slow_rotor}}
    , reflector_(reflector)
{}

void M3::RingStellung(char fast_ring, char midd_ring, char slow_ring) {
    rotors_[0].RingStellung(fast_ring);
    rotors_[1].RingStellung(midd_ring);
    rotors_[2].RingStellung(slow_ring);
}

void M3::GrundStellung(char fast_offset, char midd_offset, char slow_offset) {
    rotors_[0].GrundStellung(fast_offset);
    rotors_[1].GrundStellung(midd_offset);
    rotors_[2].GrundStellung(slow_offset);
}

void M3::Turn() {
    if(rotors_[1].IsNotch())
        rotors_[2].Turn();

    if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
        rotors_[1].Turn();

    rotors_[0].Turn();
}

char M3::Translate(char letter) {
    Turn();

    letter = plugboard_.Translate(letter);

    for(Rotor& rotor : rotors_)
        letter = rotor.TranslateStraight(letter);

    letter = reflector_.Translate(letter);

    for(auto it = rotors_.rbegin(); it != rotors_.rend(); ++it)
        letter = it->TranslateReverse(letter);

    letter = plugboard_.Translate(letter);

    return letter;
}

std::string M3::Translate(const std::string& phrase) {
    std::string result(phrase);

    for(std::size_t i = 0; i < phrase.size(); ++i)
        result[i] = Translate(result[i]);

    return result;
}

void M3::ResetPlugboard() {
    plugboard_.Reset();
}

bool M3::Connect(char lhs, char rhs) {
    return plugboard_.Connect(lhs, rhs);
}

}
