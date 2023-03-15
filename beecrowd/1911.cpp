#include <iostream>
#include <map>

bool isFakeSign(std::string s1, std::string s2) {
  int counter = 0;
  for (size_t idx = 0; idx < s1.size(); idx++) {
    if (s1[idx] != s2[idx]) {
      counter++;
    }

    if (counter >= 2) {
      return true;
    }
  }
  return false;
}

int main() {
  int n = 1, m;
  while(n) {
    std::cin >> n;
    if (!n) return 0;

    std::map<std::string, std::string> signs;
    std::string name, sign;
    for (auto i = 0; i < n; i++) {
      std::cin >> name >> sign;
      signs[name] = sign;
    }

    std::cin >> m;
    int fakes = 0;
    for (auto i = 0; i<m; i++) {
      std::cin >> name >> sign;
      if (isFakeSign(signs[name], sign)) {
        fakes++;
      }
    }

    std::cout << fakes << std::endl;
  }
  
}