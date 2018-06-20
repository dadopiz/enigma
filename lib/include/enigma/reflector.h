#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <cassert>
#include <string>
#include <enigma/global.h>

namespace enigma {

class ENIGMA_API Reflector {
public:
    Reflector(const std::string& reflector) : reflector_(reflector) {
        assert(reflector_.size() == 26 && "Alphabet must have exactly 26 letters.");
    }

    inline char Translate(char letter) const {
        assert(is_valid_char(letter) && "Invalid letter.");
        return reflector_[static_cast<std::size_t>(letter - 'A')];
    }

private:
    const std::string reflector_;
};

namespace historical {

struct reflector {
    static const Reflector B;
    static const Reflector C;
};

}

}

#endif // ENIGMA_REFLECTOR_H
