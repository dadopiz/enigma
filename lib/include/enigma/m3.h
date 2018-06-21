#ifndef ENIGMA_M3_H
#define ENIGMA_M3_H

#include <cassert>

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

class ENIGMA_API M3 {
public:
    M3(const Rotor& fast_rotor
       , const Rotor& midd_rotor
       , const Rotor& slow_rotor
       , const Reflector& reflector)
        : fast_rotor_(fast_rotor)
        , midd_rotor_(midd_rotor)
        , slow_rotor_(slow_rotor)
        , reflector_(reflector)
    {}

    char Translate(char letter) {
        assert(is_valid(letter) && "invalid letter.");

        Turn();

        letter = fast_rotor_.TranslateStraight(letter);
        letter = midd_rotor_.TranslateStraight(letter);
        letter = slow_rotor_.TranslateStraight(letter);

        letter = reflector_.Translate(letter);

        letter = slow_rotor_.TranslateReverse(letter);
        letter = midd_rotor_.TranslateReverse(letter);
        letter = fast_rotor_.TranslateReverse(letter);

        return letter;
    }

private:
    void Turn() {
        if(midd_rotor_.IsNotch())
            slow_rotor_.Turn();

        if(fast_rotor_.IsNotch() || midd_rotor_.IsNotch())
            midd_rotor_.Turn();

        fast_rotor_.Turn();
    }

    Rotor fast_rotor_;
    Rotor midd_rotor_;
    Rotor slow_rotor_;
    Reflector reflector_;
};

}

#endif // ENIGMA_M3_H
