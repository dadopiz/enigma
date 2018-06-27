#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <enigma/global.h>
#include <enigma/utils.h>

namespace enigma {

/**
 * @brief The Reflector (German: Umkehrwalze) class
 *
 * Generally the reflector was fixed and did not rotate during the encryption.
 * The reflector does not allow Enigma to encrypt a letter in itself.
 */
class ENIGMA_API Reflector {
public:
    /**
     * @brief Reflector
     * @param reflector array of letters used for encryption
     */
    Reflector(Letters reflector);

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    char Translate(char letter) const;

private:
    const Letters reflector_;
};

}

#endif // ENIGMA_REFLECTOR_H
