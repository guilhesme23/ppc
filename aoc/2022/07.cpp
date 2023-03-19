#include "../../utils/shellParser.hpp"
#include <iostream>

int main() {
  std::string input;
  while (std::cin >> input) {
    auto res = parse(input);
    for (auto tk : res) {
      std::cout << tk << std::endl;
    }
  }

  return 0;
}