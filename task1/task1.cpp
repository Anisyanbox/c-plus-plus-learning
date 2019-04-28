#include <iostream>
#include <algorithm>

// -----------------------------------------------------------------------------
static bool IsPalindrom(int n) {
  std::string str = std::to_string(n);

  std::reverse(str.begin(), str.end());
  return std::to_string(n) == str;
}

// -----------------------------------------------------------------------------
int main(int argc, char const* argv[]) {
  int palindrom_cnt = 0;
  int num = 0;

  static_cast<void>(argc);
  static_cast<void>(argv);

  std::cin >> num;

  if (num <= 0) {
    return EXIT_FAILURE;
  }

  for (int i = 1; i <= num; ++i) {
    if (IsPalindrom(i)) {
      ++palindrom_cnt;
    }
  }

  std::cout << palindrom_cnt;
  return EXIT_SUCCESS;
}
