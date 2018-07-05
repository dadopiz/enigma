#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include <string>

#include <enigma/global.h>

namespace enigma {

/**
 * @brief The Plugboard  (German: Steckerbrett) class
 *
 * The Plugboard allows a variable configuration by the operator.
 * This possibility has improved encryption in the Enigma machine.
 */
class ENIGMA_API Plugboard {
public:
    /**
     * @brief Plugboard
     */
    Plugboard();

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    char Translate(char letter) const;

    /**
     * @brief Reset the plugboard
     */
    void Reset();

    /**
     * @brief Connect
     * Connects two letters to each other by inverting their translation
     * @param lhs left letter
     * @param rhs right letter
     * @return true if connected, false otherwise
     */
    bool Connect(char lhs, char rhs);

private:
    /**
     * @brief AreConnected
     * @param lhs left letter
     * @param rhs right letter
     * @return true if are connected, false otherwise
     */
    bool AreConnected(char lhs, char rhs) const;

    int cables_;
    std::string plugboard_;
};

}

#endif // ENIGMA_PLUGBOARD_H
