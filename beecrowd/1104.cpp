#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

int main() {
  while(true) {
    int n1, n2;
    std::cin >> n1 >> n2;
    if (!n1 && !n2) return 0;

    std::set<int> s1, s2, repeated;
    int tmp;
    for (auto i = 0; i < n1; i++) {
      std::cin >> tmp;
      s1.insert(tmp);
    }

    for (auto i = 0; i < n2; i++) {
      std::cin >> tmp;
      s2.insert(tmp);
    }

    
    std::set<int> availableA, availableB;
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(availableA, availableA.end()));
    std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), std::inserter(availableB, availableB.end()));

    std::cout << std::min(availableA.size(), availableB.size()) << std::endl;
  }  
}