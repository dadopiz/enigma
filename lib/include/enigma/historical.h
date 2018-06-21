#ifndef ENIGMA_HISTORICAL_H
#define ENIGMA_HISTORICAL_H

#include <enigma/reflector.h>
#include <enigma/rotor.h>
#include <enigma/global.h>

namespace enigma {

namespace historical {

struct rotor {
    static const ENIGMA_API Rotor I;
    static const ENIGMA_API Rotor II;
    static const ENIGMA_API Rotor III;
    static const ENIGMA_API Rotor IV;
    static const ENIGMA_API Rotor V;
};

struct reflector {
    static const ENIGMA_API Reflector B;
    static const ENIGMA_API Reflector C;
};

}

}

#endif // ENIGMA_HISTORICAL_H
