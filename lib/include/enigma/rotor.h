#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <enigma/global.h>

namespace enigma {

    class ENIGMA_API Rotor {
    public:
        Rotor();
		
        Rotor(const Rotor& cp);

		Rotor& operator=(const Rotor& cp);
		
		void RingStellung(char l);

		void GrundStellung(char l);

		void Rotate();

		enum class Direction : bool {
			STRAIGHT = true, //!< alphabet --> code
			REVERSE = false, //!< code --> alphabet
		};

		char Translate(char l, Direction dir) const;

		bool IsNotch() const;
    };
}

#endif
