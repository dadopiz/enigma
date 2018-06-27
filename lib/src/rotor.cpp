#include <cassert>

#include <enigma/rotor.h>

namespace enigma {

Rotor::Rotor(Letters rotor, std::string notches)
    : rotor_(std::move(rotor))
    , notches_(std::move(notches))
    , ring_(0)
    , offset_(0)
{}

void Rotor::RingStellung(char ring) {
    assert(is_valid(ring) && "ring not valid.");
    ring_ = to_index(ring);
}

void Rotor::GrundStellung(char offset) {
    assert(is_valid(offset) && "offset not valid.");
    offset_ = to_index(offset);
}

void Rotor::Turn() {
    offset_ = (offset_ + 1) % 26;
}

bool Rotor::IsNotch() const {
    return (notches_.find(to_char(offset_)) != std::string::npos);
}

char Rotor::TranslateStraight(char letter) const {
    assert(is_valid(letter) && "letter not valid.");
    letter = AddOffset(letter, offset_ - ring_);
    letter = rotor_[to_index(letter)];
    return AddOffset(letter, ring_ - offset_);
}

char Rotor::TranslateReverse(char letter) const {
    assert(is_valid(letter) && "letter not valid.");
    letter = AddOffset(letter, offset_ - ring_);
    letter = ALPHABET[index_of(rotor_, letter)];
    return AddOffset(letter, ring_ - offset_);
}

char Rotor::AddOffset(char letter, std::size_t offset) const {
    return ALPHABET[(to_index(letter) + offset + 26) % 26];
}

}
