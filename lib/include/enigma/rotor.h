#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <cassert>
#include <string>
#include <enigma/utils.h>

namespace enigma {

class Rotor {
public:
    Rotor(Letters rotor, std::string notches)
        : rotor_(std::move(rotor))
        , notches_(std::move(notches))
        , ring_(0)
        , offset_(0)
    {}

    void RingStellung(char ring) {
        assert(is_valid(ring) && "ring not valid.");
        ring_ = to_index(ring);
    }

    void GrundStellung(char offset) {
        assert(is_valid(offset) && "offset not valid.");
        offset_ = to_index(offset);
    }

    void Turn() {
        offset_ = (offset_ + 1) % 26;
    }

    bool IsNotch() const {
        return (notches_.find(to_char(offset_)) != std::string::npos);
    }

    char TranslateStraight(char letter) const {
        assert(is_valid(letter) && "letter not valid.");
        letter = Offset(letter, offset_ - ring_);
        letter = rotor_[to_index(letter)];
        return Offset(letter, ring_ - offset_);
    }

    char TranslateReverse(char letter) const {
        assert(is_valid(letter) && "letter not valid.");
        letter = Offset(letter, offset_ - ring_);
        letter = ALPHABET[index_of(rotor_, letter)];
        return Offset(letter, ring_ - offset_);
    }
private:
    char Offset(char letter, std::size_t offset) const {
        return ALPHABET[(to_index(letter) + offset + 26) % 26];
    }

    const Letters rotor_;
    const std::string notches_;

    std::size_t ring_;
    std::size_t offset_;
};

}

#endif // ENIGMA_ROTOR_H
