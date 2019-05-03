#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

// -----------------------------------------------------------------------------
typedef enum {
  INPUT_SEQ_TRUE,
  INPUT_SEQ_WRONG
} InputSeqType_t;

// -----------------------------------------------------------------------------
static void PrintErrSequenceMsg() {
  std::cout << "[error]" << std::endl;
}

// -----------------------------------------------------------------------------
static int VectorToInt(std::vector<int>& v) {
  int decimal = 1;
  int total = 0;
 
  std::reverse(v.begin(), v.end());
  for (auto& it : v) {
    total += it * decimal;
    decimal *= 10;
  }
  return total;
}

// -----------------------------------------------------------------------------
static bool IsDelemiterInFirstInToken(std::string& s) {
  for (auto it = s.begin(); it < s.end(); ++it) {
    if (*it == '\n') {
      return true;
    }
  }
  return false;
}

// -----------------------------------------------------------------------------
static bool IsFirstTokenOk(std::string& first_token) {
  for (auto it = first_token.begin(); it < first_token.end(); ++it) {
    if ((*it == '+') && (it == first_token.begin())) {
      continue;
    }
    if ((*it == '-') && (it == first_token.begin())) {
      return false;
    }
    if (!std::isdigit((int)*it)) {
      return false;
    }
  }
  return true;
}

// -----------------------------------------------------------------------------
static int GetSeqLenFromFirstToken(std::string& first_token) {
  return std::stoi(first_token);
}

// -----------------------------------------------------------------------------
static bool IsTokenOk(std::string& token) {
  int e_cnt = 0;
  int E_cnt = 0;
  bool is_last_sym_was_e = false;
  
  for (auto it = token.begin(); it < token.end(); ++it) {
    if ((((*it == '+') || (*it == '-')) && (it == token.begin())) || (*it == '.')) {
      is_last_sym_was_e = false;
      continue;
    }
    
    if (!std::isdigit((int)*it)) {
      if (*it == 'e') {
        if (++e_cnt > 1) {
          return false;
        }
        is_last_sym_was_e = true;
        continue;
      }
      if (*it == 'E') {
        if (++E_cnt > 1) {
          return false;
        }
        is_last_sym_was_e = true;
        continue;
      }
      if ((e_cnt == 1) && (E_cnt == 1)) {
        return false;
      }
      if (*it == '+' ) {
        if (!is_last_sym_was_e) {
          return false;
        } else {
          continue;
        }
      }
      if (*it == '-' ) {
        if (!is_last_sym_was_e) {
          return false;
        } else {
          continue;
        }
      }
      return false;
    } else {
      is_last_sym_was_e = false;
    }
  } 
  return true;
}

// input sequence will write into vector v or will return 'INPUT_SEQ_WRONG'
// -----------------------------------------------------------------------------
static InputSeqType_t GetInputSequence(std::vector<long double>& v) {
  std::string in;
  int in_seq_len = 0;

  std::getline(std::cin, in); 
  std::stringstream ss_in(in);

  if (in.size() == 0) {
    return INPUT_SEQ_WRONG;
  }
  
  // parsing input length of sequence
  {
    std::string first_token;
    ss_in >> first_token;
    if (IsDelemiterInFirstInToken(first_token)) {
      std::cout << "there is delemite in first token" << std::endl;
    } else {
      if (IsFirstTokenOk(first_token)) {
        in_seq_len = GetSeqLenFromFirstToken(first_token);
      }
    }
  }

  // parse sequence and it to vector
  for (int i = 0; i < in_seq_len; ++i) {
    std::string token;
    
    ss_in >> token;
    if (!IsTokenOk(token)) {
      return INPUT_SEQ_WRONG;
    }
    
    try {
      v.push_back(std::stold(token));
    } catch (...) {
      return INPUT_SEQ_WRONG;
    }
  }

  // check rest input sequence
  while (!ss_in.eof()) {
    std::string token;

    ss_in >> token;
    if (!IsTokenOk(token)) {
      return INPUT_SEQ_WRONG;
    }
  }

  // check sequence size
  if ((in_seq_len < 2) || (in_seq_len > v.size()) || (v.size() == 0)) {
    return INPUT_SEQ_WRONG;
  }
  return INPUT_SEQ_TRUE;
}

// -----------------------------------------------------------------------------
int main() {
  std::vector<long double> v;

  if (GetInputSequence(v) == INPUT_SEQ_TRUE) {
    for (auto it = v.begin(); it < v.end(); ++it) {
      std::cout << *it << std::endl;
    }
  } else {
    PrintErrSequenceMsg();
  }
  return EXIT_SUCCESS;
}
