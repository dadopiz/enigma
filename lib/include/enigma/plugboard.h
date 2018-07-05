#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include <string>

#include <enigma/global.h>

namespace enigma {

class Plugboard {
public:
    ENIGMA_API Plugboard();

    ENIGMA_API char Translate(char letter) const;

    ENIGMA_API void Reset();

    ENIGMA_API bool Connect(char lhs, char rhs);

private:
    bool AreConnected(char lhs, char rhs) const;

    int cables_;
    std::string plugboard_;
};

}

#endif // ENIGMA_PLUGBOARD_H
