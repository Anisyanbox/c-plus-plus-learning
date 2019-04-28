#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

static unsigned long long kWrongInputSequence = 0;

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

// T = n(n + 1)/2 --> n^2 + n - 2T - 0
// -----------------------------------------------------------------------------
static unsigned long long GetTriangularIndexIfPossible(unsigned long long t) {
  if (t == 0) {
    return kWrongInputSequence;
  }

  long long int d = 0;
  double sqrt_d_test = 0.0;

  unsigned long long n = 0;
  long long int sqrt_d = 0;
  double root_test = 0;
  double root = 0.0;


  /* calculate discriminant */
  d = 1 + 8 * t;
  if (d <= 0) {
    return kWrongInputSequence;
  } else {
    /* check that sqrt is integer */
    sqrt_d_test = std::ceil(std::sqrt(d)) - std::sqrt(d);
    if (sqrt_d_test == 0) {
      sqrt_d = static_cast<long long int>(std::sqrt(d));
    } else {
      return kWrongInputSequence;
    }

    /* calculate root */
    root = (sqrt_d - 1) / 2;
    root_test = std::ceil(std::pow(root, 2)) - std::pow(root, 2);
    
    if (root_test == 0) {
      n = static_cast<unsigned long long>(root);
    } else {
      return kWrongInputSequence;
    }
  }

  return n;
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
