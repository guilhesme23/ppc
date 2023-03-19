#include "shellParser.hpp"
#include <sstream>

std::ostream& operator<<(std::ostream& os, Token& tk) {
  if (tk.value.length() > 0) {
    os << "Token{ " << tk.name << ", " << tk.value << " }";
  } else {
    os << "Token{ " << tk.name << " }";
  }

  return os;
}

std::vector<Token> parse(std::string input) {
  std::vector<Token> result;
  std::string tmp;
  std::stringstream ss(input);
  while (ss >> tmp) {
    Token tk;
    if (tmp == "$") {
      tk.name = "shell";
    } else if (tmp == "cd" || tmp == "ls") {
      tk.name = "command";
      tk.value = tmp;
    } else if (tmp == "dir") {
      tk.name = "modifier";
      tk.value = tmp;
    } else if (is_number(tmp)) {
      tk.name = "filesize";
      tk.value = tmp;
    } else {
      tk.name = "literal";
      tk.value = tmp;
    }
    result.push_back(tk);
  }

  return result;
}

bool is_number(const std::string& s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}