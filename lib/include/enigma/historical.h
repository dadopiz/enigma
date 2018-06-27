#ifndef ENIGMA_HISTORICAL_H
#define ENIGMA_HISTORICAL_H

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>
#include <enigma/m3.h>
#include <enigma/m4.h>

namespace enigma {

namespace historical {

struct ENIGMA_API rotor {
    static const Rotor I;
    static const Rotor II;
    static const Rotor III;
    static const Rotor IV;
    static const Rotor V;
    static const Rotor VI;
    static const Rotor VII;
    static const Rotor VIII;
    static const Rotor Beta;
    static const Rotor Gamma;
};

struct ENIGMA_API reflector {
    static const Reflector B;
    static const Reflector C;
    static const Reflector BThin;
    static const Reflector CThin;
};

}

}

#endif // ENIGMA_HISTORICAL_H
