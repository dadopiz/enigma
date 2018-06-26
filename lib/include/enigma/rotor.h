#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <string>

#include <enigma/global.h>
#include <enigma/utils.h>

namespace enigma {

class ENIGMA_API Rotor {
public:
    Rotor(Letters rotor, std::string notches);

    void RingStellung(char ring);

    void GrundStellung(char offset);

    void Turn();

    bool IsNotch() const;

    char TranslateStraight(char letter) const;

    char TranslateReverse(char letter) const;

private:
    char Offset(char letter, std::size_t offset) const;

    const Letters rotor_;
    const std::string notches_;

    std::size_t ring_;
    std::size_t offset_;
};

}

#endif // ENIGMA_ROTOR_H
