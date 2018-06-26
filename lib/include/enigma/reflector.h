#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <enigma/global.h>
#include <enigma/utils.h>

namespace enigma {

class ENIGMA_API Reflector {
public:
    Reflector(Letters reflector);

    char Translate(char letter) const;

private:
    const Letters reflector_;
};

}

#endif // ENIGMA_REFLECTOR_H
