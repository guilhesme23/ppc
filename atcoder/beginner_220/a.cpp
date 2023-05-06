#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int multiplier = 1;
  while (c < a) {
    c *= multiplier;
    ++multiplier;
  }

  if (c >= a && c <= b) {
    cout << c << '\n';
    return 0;
  }

  cout << -1 << '\n';
  return 0;
}
