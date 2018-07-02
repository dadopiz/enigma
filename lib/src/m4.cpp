#include <enigma/m4.h>

namespace enigma {

namespace historical {

M4::M4(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Rotor& thin_rotor,
       const Reflector& thin_reflector)
{}

std::string M4::Translate(const std::string& phrase) {
    std::string result(phrase);

    for(std::size_t i = 0; i < phrase.size(); ++i)
        result[i] = Translate(result[i]);

    return result;
}

void M4::RingStellung(char fast_ring, char midd_ring, char slow_ring, char thin_ring) {
}

void M4::GrundStellung(char fast_offset, char midd_offset, char slow_offset, char thin_offset) {
}

char M4::Translate(char letter) {
    return letter;
}

void M4::ResetPlugboard() {
}

bool M4::Connect(char lhs, char rhs) {
    return false;
}

}

}
