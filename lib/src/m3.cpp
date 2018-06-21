#include <enigma/m3.h>

#include <cassert>

namespace enigma {

M3::M3(std::array<Rotor, 3> rotors, Reflector reflector)
    : rotors_(std::move(rotors))
    , reflector_(std::move(reflector))
{}

char M3::Translate(char letter) {
    assert(is_valid(letter) && "invalid letter.");

    Turn();

    for(Rotor& rotor : rotors_)
        letter = rotor.TranslateStraight(letter);

    letter = reflector_.Translate(letter);

    for(auto it = rotors_.rend(); it != rotors_.rbegin(); ++it)
        letter = it->TranslateReverse(letter);

    return letter;
}

void M3::Turn() {
    if(rotors_[1].IsNotch())
        rotors_[2].Turn();

    if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
        rotors_[1].Turn();

    rotors_[0].Turn();
}

}
