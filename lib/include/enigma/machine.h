#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <array>
#include <string>

#include <enigma/utils.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

template<std::size_t ROTORS>
class Machine {
    static_assert(ROTORS >= 3, "Enigma must have at least 3 rotors");
public:
    Machine(const std::array<Rotor, ROTORS>& rotors, const Reflector& reflector)
        : rotors_(rotors)
        , reflector_(reflector)
    {}

    std::string Translate(const std::string& phrase) {
        std::string result(phrase);

        for(std::size_t i = 0; i < phrase.size(); ++i)
            result[i] = Translate(result[i]);

        return result;
    }

    char Translate(char letter) {
        Turn();

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

private:
    void Turn() {
        if(rotors_[1].IsNotch())
            rotors_[2].Turn();

        if(rotors_[0].IsNotch() || rotors_[1].IsNotch())
            rotors_[1].Turn();

        rotors_[0].Turn();
    }

    std::array<Rotor, ROTORS> rotors_;
    Reflector reflector_;
};

}

#endif // ENIGMA_MACHINE_H
