#ifndef ENIGMA_M3_H
#define ENIGMA_M3_H

#include <array>

#include <enigma/global.h>
#include <enigma/reflector.h>
#include <enigma/rotor.h>
#include <enigma/plugboard.h>

namespace enigma {

/**
 * @brief The M3 class
 *
 * Enigma machine used by the Wehrmacht and Kriegsmarine during the WW2.
 * The Wehrmacht had available the first 5 rotors (I to V),
 * while the Kriegsmarine had all 8 rotors.
 */
class ENIGMA_API M3 {
public:
    /**
     * @brief M3
     * @param fast_rotor first rotor
     * @param midd_rotor second rotor
     * @param slow_rotor third rotor
     * @param reflector reflector
     */
    M3(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Reflector& reflector);

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    char Translate(char letter);

    /**
     * @brief Translate
     * @param phrase input string
     * @return encrypted string
     */
    std::string Translate(const std::string& phrase);

    /**
     * @brief RingStellung
     * @param fast_ring the position of each alphabet ring relative to first rotor
     * @param midd_ring the position of each alphabet ring relative to second rotor
     * @param slow_ring the position of each alphabet ring relative to third rotor
     */
    void RingStellung(char fast_ring, char midd_ring, char slow_ring);

    /**
     * @brief GrundStellung
     * @param fast_offset starting position of the first rotor
     * @param midd_offset starting position of the second rotor
     * @param slow_offset starting position of the third rotor
     */
    void GrundStellung(char fast_offset, char midd_offset, char slow_offset);

    /**
     * @brief ResetPlugboard
     */
    void ResetPlugboard();

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
     * @brief Turn the rotors checking the notch
     */
    void Turn();

    std::array<Rotor, 3> rotors_;
    Reflector reflector_;
    Plugboard plugboard_;
};

}

#endif // ENIGMA_M3_H
