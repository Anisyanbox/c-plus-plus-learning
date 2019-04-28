#include <iostream>
#include <string>
#include <cctype>

static int kWrongInputSequence = 0;

// -----------------------------------------------------------------------------
static bool IsInputArgTrue(std::string s) {
  if (s.size() == 0) {
  return false;
  }
  for(std::string::iterator it = s.begin(); it < s.end(); it++) {
    if (it == s.begin() && *it == '+') {
      continue;
    }
    if (!std::isdigit((int)*it)) {
      return false;
    }
  }
  return true;
}

// -----------------------------------------------------------------------------
static unsigned long long GetNumberFromString(std::string s) {
  std::string::size_type sz = 0;
  return std::stoull(static_cast<const std::string&>(s), &sz, 10);
}

// -----------------------------------------------------------------------------
static unsigned long long GetTriangularIndexIfPossible(unsigned long long n) {
  if (n == 0) {
    return 0;
  }
  return 0;
}

// -----------------------------------------------------------------------------
int main (int argc, char * argv[]) {
  std::string input;

  std::getline(std::cin, input);      
  if (!IsInputArgTrue(input)) {
      std::cout << kWrongInputSequence;
  } else {
      std::cout << GetTriangularIndexIfPossible(GetNumberFromString(input));
  }
  return EXIT_SUCCESS;
}
