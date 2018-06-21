#include <enigma/historical.h>

namespace enigma {

namespace historical {

const Reflector reflector::B({"YRUHQSLDPXNGOKMIEBFZCWVJAT"});
const Reflector reflector::C({"FVPJIAOYEDRZXWGCTKUQSBNMHL"});

const Rotor rotor::I({"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}, 'Q');
const Rotor rotor::II({"AJDKSIRUXBLHWTMCQGZNPYFVOE"}, 'E');
const Rotor rotor::III({"BDFHJLCPRTXVZNYEIWGAKMUSQO"}, 'V');
const Rotor rotor::IV({"ESOVPZJAYQUIRHXLNFTGKDCMWB"}, 'J');
const Rotor rotor::V({"VZBRGITYUPSDNHLXAWMJQOFECK"}, 'Z');

//TODO: insert multiple notches in Rotor class 
const Rotor rotor::VI({"JPGVOUMFYQBENHZRDKASXLICTW"}, 'Z'); // + 'M'
const Rotor rotor::VII({"NZJHGRCXMYSWBOUFAIVLPEKQDT"}, 'Z'); // + 'M'
const Rotor rotor::VIII({"FKQHTLXOCBJSPDZRAMEWNIUYGV"}, 'Z'); // + 'M'

}

}
