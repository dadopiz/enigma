#ifndef ENIGMA_M4_H
#define ENIGMA_M4_H

#include <array>

#include <enigma/global.h>
#include <enigma/reflector.h>
#include <enigma/rotor.h>
#include <enigma/plugboard.h>

namespace enigma {

/**
 * @brief The M4 class
 *
 * The M4 machine was introduced on February 2, 1942 by the Kriegsmarine.
 * The standard reflector was divided into a thin rotor and a thin reflector.
 */
class ENIGMA_API M4 {
public:
    /**
     * @brief M4
     * @param fast_rotor first rotor
     * @param midd_rotor second rotor
     * @param slow_rotor third rotor
     * @param thin_rotor fourth rotor
     * @param thin_reflector reflector
     */
    M4(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Rotor& thin_rotor,
       const Reflector& thin_reflector);

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
     * @param thin_ring the position of each alphabet ring relative to fourth rotor
     */
    void RingStellung(char fast_ring, char midd_ring, char slow_ring, char thin_ring);

    /**
     * @brief GrundStellung
     * @param fast_offset starting position of the first rotor
     * @param midd_offset starting position of the second rotor
     * @param slow_offset starting position of the third rotor
     * @param thin_offset starting position of the fourth rotor
     */
    void GrundStellung(char fast_offset, char midd_offset, char slow_offset, char thin_offset);

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

    std::array<Rotor, 4> rotors_;
    Reflector thin_reflector_;
    Plugboard plugboard_;
};

}

#endif // ENIGMA_M4_H
