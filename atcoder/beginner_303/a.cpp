#include <iostream>

using namespace std;

int main() {
  int n;
  string x, y;
  cin >> n >> x >> y;

  for (int i = 0; i<n; ++i) {
    if (x[i] == y[i]) {
      continue;
    }

    if ((x[i] == 'l' and y[i] == '1') or (x[i] == '1' and y[i] == 'l')) {
      continue;
    }

    if ((x[i] == 'o' and y[i] == '0') or (x[i] == '0' and y[i] == 'o')) {
      continue;
    }

    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  return 0;
}
