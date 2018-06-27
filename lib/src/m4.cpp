#include <enigma/m4.h>

namespace enigma {

namespace historical {

M4::M4(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Rotor& thin_rotor,
       const Reflector& thin_reflector)
    : machine_({fast_rotor, midd_rotor, slow_rotor})
    , thin_rotor_(thin_rotor)
    , thin_reflector_(thin_reflector)
{}

std::string M4::Translate(const std::string& phrase) {
    std::string result(phrase);

    for(std::size_t i = 0; i < phrase.size(); ++i)
        result[i] = Translate(result[i]);

    return result;
}

void M4::RingStellung(char fast_ring, char midd_ring, char slow_ring, char thin_ring) {
    machine_.RingStellung({{fast_ring, midd_ring, slow_ring}});
    thin_rotor_.RingStellung(thin_ring);
}

void M4::GrundStellung(char fast_offset, char midd_offset, char slow_offset, char thin_offset) {
    machine_.GrundStellung({{fast_offset, midd_offset, slow_offset}});
    thin_rotor_.GrundStellung(thin_offset);
}

char M4::Translate(char letter) {
    machine_.Turn();
    letter = plugboard_.Translate(letter);
    letter = machine_.TranslateStraight(letter);
    letter = thin_rotor_.TranslateStraight(letter);
    letter = thin_reflector_.Translate(letter);
    letter = thin_rotor_.TranslateReverse(letter);
    letter = machine_.TranslateReverse(letter);
    letter = plugboard_.Translate(letter);
    return letter;
}

void M4::ResetPlugboard() {
    plugboard_.Reset();
}

bool M4::Connect(char lhs, char rhs) {
    return plugboard_.Connect(lhs, rhs);
}

}

}
