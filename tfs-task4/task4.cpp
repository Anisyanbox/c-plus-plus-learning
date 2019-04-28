#include <iostream>
#include <stack>

// -----------------------------------------------------------------------------
int main() {
  std::stack<char> opened_bracket;
  std::stack<char> closed_bracket;
  std::string str;
  int q_symbols_cnt = 0;

  std::getline(std::cin, str);

  for (size_t i = 0; i < str.size(); ++i) {
    if (str.at(i) == '(') {
      opened_bracket.push(str.at(i));
    } else if (str.at(i) == ')') {
      closed_bracket.push(str.at(i));
    } else if (str.at(i) == '?') {
      ++q_symbols_cnt;
    }
  }
  return EXIT_SUCCESS;
}
