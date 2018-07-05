#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include<string>
#include <enigma/global.h>

namespace enigma {

/**
 * @brief The Reflector (German: Umkehrwalze) class
 *
 * Generally the reflector was fixed and did not rotate during the encryption.
 * The reflector does not allow Enigma to encrypt a letter in itself.
 */
class Reflector {
public:
    /**
     * @brief Reflector
     * @param reflector array of letters used for encryption
     */
    ENIGMA_API Reflector(const std::string& reflector);

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    ENIGMA_API char Translate(char letter) const;

private:
    const std::string reflector_;
};

}

#endif // ENIGMA_REFLECTOR_H
