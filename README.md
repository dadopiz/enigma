[![Build Status](https://travis-ci.com/dadopiz/enigma.svg?branch=master)](https://travis-ci.com/dadopiz/enigma)
[![Build status](https://ci.appveyor.com/api/projects/status/dynbya1dy96deihr?svg=true)](https://ci.appveyor.com/project/dadopiz/enigma)
[![codecov](https://codecov.io/gh/dadopiz/enigma/branch/master/graph/badge.svg)](https://codecov.io/gh/dadopiz/enigma)

# enigma
## C++ library of the Enigma machine
This library implements the M3 and M4 machines used by Wehrmacht and Kriegsmarine during the WW2.

### Notes
This project aims to be an exercise for using C++, CMake, googletest and CI tools.

### Example
```C++
#include <iostream>
#include <string>
#include <enigma/enigma>

int main() {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M3 machine(rotor::III, rotor::II, rotor::I, reflector::B);

    std::cout << "Enigma, say hello:" << std::endl;
    std::cout << machine.Translate("HELLOWORLD") << std::endl;

    return 0;
}
```

### Build
The project require a C++11 compiler.
```Shell
mkdir build
cd build
cmake ..
cmake --build .
```
