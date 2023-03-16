#include <iostream>
#include <map>

int main() {
  std::string p1, p2;
  std::map<std::string, std::string> win = {
    {"A", "B"},
    {"B", "C"},
    {"C", "A"}
  };

  std::map<std::string, std::string> lose = {
    {"A", "C"},
    {"B", "A"},
    {"C", "B"}
  };

  std::map<std::string, int> handsValues = {
    {"A", 1},
    {"B", 2},
    {"C", 3},
  };

  std::map<std::string, int> resultPoints = {
    {"X", 0},
    {"Y", 3},
    {"Z", 6}
  };

  int total = 0;
  while (std::cin >> p1 >> p2) {
    total += resultPoints[p2];
    if(p2 == "X") {
      total += (handsValues[lose[p1]]);
    } else if (p2 == "Y") {
      total += (handsValues[p1]);
    } else {
      total += handsValues[win[p1]];
    }
  }

  std::cout << total << std::endl;

  return 0;
}