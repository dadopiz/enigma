#include <iostream>

#include <enigma/enigma.h>

inline constexpr bool is_valid_char(char l) {
    return (l >= 'A' && l <= 'Z');
}

template<std::size_t IDX>
inline constexpr bool is_valid(const char* arr) {
    return is_valid_char(arr[IDX]) ? is_valid<IDX - 1>(arr) : false;
}

template<>
inline constexpr bool is_valid<0>(const char* arr) {
    return is_valid_char(arr[0]);
}

template<std::size_t N>
inline constexpr bool is_valid_alphabet(const char(&arr)[N]) {
    return is_valid<N - 2>(arr);
}

int main(int, const char**) {
    enigma::Reflector custom_reflector({"QWERTYUIOPASDFGHJKLZXCVBNM"});
    std::cout << "custom_reflector translate Z in... " << custom_reflector.Translate('Z') << std::endl;

    auto historical_reflector = enigma::historical::reflector::B;
    std::cout << "historical_reflector translate Z in... " << historical_reflector.Translate('Z') << std::endl;

    return 0;
}
