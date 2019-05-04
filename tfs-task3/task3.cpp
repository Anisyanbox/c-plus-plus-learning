#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

// -----------------------------------------------------------------------------
class polinom {
 public:
  int polinom_power_;

  // p(power, koeff before x^(power), koeff before x^(power - 1), ...)
  polinom(int power, std::vector<int>& k) {
    polinom_power_ = power;
    polinom_koeffs_ = new int[k.size()];

    int i = 0;
    for (std::vector<int>::iterator it = k.begin(); it < k.end(); ++it) {
      polinom_koeffs_[i++] = *it;
    }
  }

  ~polinom() {
    polinom_power_ = 0;
    delete[]polinom_koeffs_;
  }

  polinom operator*(polinom& p) {
    std::vector<int> local_koef(this->polinom_power_ + p.polinom_power_ + 1);

    for (int i = 0; i <= this->polinom_power_; ++i) {
      for (int j = 0; j <= p.polinom_power_; ++j) {
        local_koef[i + j] += this->polinom_koeffs_[i] * p.polinom_koeffs_[j];
      }
    }

    polinom temp(this->polinom_power_ + p.polinom_power_, local_koef);
    return temp;
  }

  void out() {
    int temp_power = polinom_power_;

    for (int i = 0; i <= temp_power; ++i) {
      std::string koef_str = std::to_string(polinom_koeffs_[i]);

      if (polinom_koeffs_[i] != 0) {
        PrintPolinomPart((const std::string&)koef_str, temp_power - i);
      }
    }
  }

 private:
  int* polinom_koeffs_;

  void PrintPolinomPart(const std::string& value, int cur_power) {
    std::string str;

    if (polinom_koeffs_[polinom_power_ - cur_power] > 0) {
      if (cur_power != polinom_power_) {
        str.push_back('+');
      }
      if (polinom_koeffs_[polinom_power_ - cur_power] != 1) {
        str += value;
      }
    } else {
      if (std::abs(polinom_koeffs_[polinom_power_ - cur_power]) == 1) {
        str.push_back('-');
      } else {
        str += value;
      }
    }

    if (cur_power != 0) {
      str.push_back('x');
    }

    if (cur_power > 1) {
      std::string polinom_power_str = std::to_string(cur_power);

      str.push_back('^');
      str += polinom_power_str;
    }

    std::cout << str;
  }
};

// -----------------------------------------------------------------------------
enum class ParsingStringState {
  RX_KOEF,
  RX_POWER
};

// -----------------------------------------------------------------------------
static void ParseInputStr(std::vector<int>& k, const std::string& s) {
  std::stringstream ss;
  std::string temp;
  int p;
  int koef;

  for (size_t i = 0; i <= s.size(); ++i) {
    if ((s[i] != '+') && (s[i] != '-')) {
      temp.push_back(s[i]);
    } else {
      ss << temp;

      ss >> koef >> "x^" >> p;
    }
  }
}

// -----------------------------------------------------------------------------
int main() {
  std::string p1_str;
  std::string p2_str;

  std::getline(std::cin, p1_str);
  std::getline(std::cin, p2_str);

  std::vector<int> k1;
  std::vector<int> k2;

  ParseInputStr(k1, p1_str);
  ParseInputStr(k2, p2_str);

  polinom p1(k1.size() - 1, k1);
  polinom p2(k2.size() - 1, k2);

  polinom p3 = p1 * p2;
  p3.out();
  return EXIT_SUCCESS;
}
