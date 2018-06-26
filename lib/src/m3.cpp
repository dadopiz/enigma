#include <enigma/m3.h>

namespace enigma {

M3::M3(const Rotor& fast_rotor,
       const Rotor& midd_rotor,
       const Rotor& slow_rotor,
       const Reflector& reflector)
    : machine_({{fast_rotor, midd_rotor, slow_rotor}}, reflector)
{}

void M3::RingStellung(char fast_ring, char midd_ring, char slow_ring) {
    machine_.RingStellung({{fast_ring, midd_ring, slow_ring}});
}

void M3::GrundStellung(char fast_offset, char midd_offset, char slow_offset) {
    machine_.GrundStellung({{fast_offset, midd_offset, slow_offset}});
}

char M3::Translate(char letter) {
    Turn();
    letter = plugboard_.Translate(letter);
    letter = machine_.Translate(letter);
    letter = plugboard_.Translate(letter);
    return letter;
}

std::string M3::Translate(const std::string& phrase) {
    std::string result(phrase);

    for(std::size_t i = 0; i < phrase.size(); ++i)
        result[i] = Translate(result[i]);

    return result;
}

void M3::ResetPlugboard() {
    plugboard_.Reset();
}

bool M3::Connect(char lhs, char rhs) {
    return plugboard_.Connect(lhs, rhs);
}

void M3::Turn() {
    if(machine_[1].IsNotch())
        machine_[2].Turn();

    if(machine_[0].IsNotch() || machine_[1].IsNotch())
        machine_[1].Turn();

    machine_[0].Turn();
}

}
