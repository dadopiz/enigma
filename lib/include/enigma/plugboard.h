#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include <enigma/global.h>
#include <enigma/utils.h>

namespace enigma {

class ENIGMA_API Plugboard {
public:
    Plugboard();

    char Translate(char letter) const;

    void Reset();

    bool Connect(char lhs, char rhs);

private:
    bool AreConnected(char lhs, char rhs) const;

    int cables_;
    Letters plugboard_;
};

}

#endif // ENIGMA_PLUGBOARD_H
