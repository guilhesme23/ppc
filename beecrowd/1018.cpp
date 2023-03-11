#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> coins{100, 50, 20, 10, 5, 2, 1};

  int value;
  cin >> value;
  cout << value << endl;

  for (auto coin = coins.begin(); coin != coins.end(); coin++) {
    cout << value / *coin << " nota(s) de R$ " << *coin << ",00\n";
    value = value%(*coin);
  }

  return 0;
}