#include <iostream>

using namespace std;

// Also works on 1240

int main() {
  int n;
  string b, lb;

  cin >> n;

  while (n--) {
    cin >> b >> lb;

    bool fits = true;

    auto j = b.rbegin();
    for (auto it = lb.rbegin(); it != lb.rend(); it++) {
      if (*it != *j) {
        fits = false;
        break;
      }
      j++;
    }

    if (fits) {
      cout << "encaixa" << endl;
    } else {
      cout << "nao encaixa" << endl;
    }
  }

  return 0;
}