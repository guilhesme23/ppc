#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

int main() {
  while (true) {
    int n, tmp;
    std::string line;
    std::cin >> n;
    std::cin.ignore();
    if (!n) return 0;

    while (true) {
      getline(std::cin, line);
      if (line == "0")
        break;

      std::stack<int> cargo;
      for (auto i = n; 0 < i; i--) {
        cargo.push(i);
      };

      std::stringstream ss(line);
      std::stack<int> station;
      bool possible = true;
      while (ss >> tmp) {
        if (station.empty()) {
          station.push(cargo.top());
          cargo.pop();
        }

        while (station.top() != tmp && !cargo.empty()) {
          station.push(cargo.top());
          cargo.pop();
        };

        if (station.top() == tmp) {
          station.pop();
        }
        else {
          possible = false;
          break;
        }
      }

      if (possible) {
        std::cout << "Yes\n";
      }
      else {
        std::cout << "No\n";
      }
    }
    std::cout << std::endl;
  }
}