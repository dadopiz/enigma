#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <array>

#include <enigma/utils.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

template<std::size_t ROTORS>
class Machine {
public:
    Machine(const std::array<Rotor, ROTORS>& rotors, const Reflector& reflector)
        : rotors_(rotors)
        , reflector_(reflector)
    {}

    char Translate(char letter) {
        for(Rotor& rotor : rotors_)
            letter = rotor.TranslateStraight(letter);

        letter = reflector_.Translate(letter);

        for(auto it = rotors_.rbegin(); it != rotors_.rend(); ++it)
            letter = it->TranslateReverse(letter);

        return letter;
    }

    void RingStellung(const std::array<char, ROTORS>& rings) {
        for(std::size_t i = 0; i < ROTORS; ++i)
            rotors_[i].RingStellung(rings[i]);
    }

    void GrundStellung(const std::array<char, ROTORS>& offsets) {
        for(std::size_t i = 0; i < ROTORS; ++i)
            rotors_[i].GrundStellung(offsets[i]);
    }

    Rotor& operator[](std::size_t index) {
        return rotors_.at(index);
    }

private:
    std::array<Rotor, ROTORS> rotors_;
    Reflector reflector_;
};

}

#endif // ENIGMA_MACHINE_H
