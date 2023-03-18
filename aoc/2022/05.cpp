#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

int main() {
  std::ifstream fin("input.txt");
  std::string input;
  std::vector<std::stack<char>> cargo;
  while (getline(fin, input)) {
    if (input == "") break;
    std::stack<char> crates;
    for (char c : input) {
      if (c != ' ') {
        crates.push(c);
      }
    }
    cargo.push_back(crates);
  }

  while(getline(fin, input)) {
    std::stringstream ss(input);
    int from, to, n;
    std::string tmp;
    while (ss >> tmp) {
      if (tmp == "move") {
        ss >> n;
      } else if (tmp == "from") {
        ss >> from;
        from--;
      } else if (tmp == "to") {
        ss >> to;
        to--;
      }
    }

    std::stack<char> tmpCargo;
    while(n--) {
      tmpCargo.push(cargo[from].top());
      cargo[from].pop();
    }

    while(!tmpCargo.empty()) {
      cargo[to].push(tmpCargo.top());
      tmpCargo.pop();
    }
  }

  for (auto crates : cargo) {
    std::cout << crates.top();
  }

  std::cout << std::endl;

  return 0;
}