#include <iostream>
#include <queue>

int main() {
  int n;
  while (std::cin >> n) {
    if (!n) return 0;

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }

    std::cout << "Discarded cards: ";
    while(q.size() > 1) {
      std::string c;
      
      if (q.size() == 2) {
        c ="\n";
      } else {
        c = ", ";
      }
      int tmp = q.front();
      q.pop();
      std::cout << tmp << c;
      q.push(q.front());
      q.pop();
    }

    int tmp = q.front();
    q.pop();
    std::cout << "Remaining card: " << tmp << std::endl;
  }
}