#include <iostream>
#include <set>
#include <map>

int main() {
  while (true) {
    int n, m;
    std::cin >> n >> m;
    if (!n && !m) return 0;

    std::map<int, int> tickets;
    for (auto i = 1; i <= n; i++) {
      tickets[i] = 0;
    }

    int tmp;
    for(auto i = 0; i < m; i++) {
      std::cin >> tmp;
      tickets[tmp] += 1; 
    }

    int fakes = 0;
    for (auto kv : tickets) {
      if (kv.second > 1) fakes++;
    }

    std::cout << fakes << std::endl;
  }
}