#include <iostream>
#include <set>

int main() {
  std::string input;
  while (std::cin >> input) {
    int idx = 0;
    size_t step = 14;
    for (size_t i = 0; i < input.length() - 4; i++) {
      std::set<char> tmp;
      for (size_t j = i; j < i+step; j++) {
        tmp.insert(input[j]);
      }
      if (tmp.size() == step) {
        idx = i+(step - 1);
        break;
      }
    }
    std::cout << idx+1 << std::endl;
  }
}