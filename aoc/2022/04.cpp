#include <iostream>
#include <vector>

int main() {
  std::string input;
  int total = 0;
  while (std::cin >> input) {
    std::string tmp = "";
    std::vector<int> ids;
    for (char c : input) {
      if (c == ',' || c == '-') {
        ids.push_back(std::stoi(tmp));
        tmp = "";
      } else {
        tmp += c;
      }
    }

    if (tmp.length() > 0) {
      ids.push_back(std::stoi(tmp));
    }

    if (ids[2] <= ids[1] && ids[0] <= ids[3]) {
      total++;
    }
  }

  std::cout << total << std::endl;
}
