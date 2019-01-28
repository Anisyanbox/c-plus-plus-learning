#include <iostream>

// На вход поступает стркоа латинских символов. Вывести все символы из входной
// строки, которые встречались в ней более одного раза
// Пример:
// in: sos
// out: s

#define LATIN_ALPHABET_SIZE     (26U)

// -----------------------------------------------------------------------------
int main(int argc, char const* argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);

  static char latin_alphabet_symbols_cnt[LATIN_ALPHABET_SIZE];
  static char latin_alphabet_symbols[LATIN_ALPHABET_SIZE] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
  };

  std::string str;
  std::getline(std::cin, str);

  for (size_t i = 0; i < str.size(); ++i) {
    ++latin_alphabet_symbols_cnt[static_cast<int>(str.at(i) - 'a')];
  }

  for (int i = 0; i < LATIN_ALPHABET_SIZE; ++i) {
    if (latin_alphabet_symbols_cnt[i] > 1) {
      std::cout << latin_alphabet_symbols[i];
    }
  }

  return EXIT_SUCCESS;
}
