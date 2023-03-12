#include <iostream>

using namespace std;

int main() {
  int rounds, c;
  cin >> rounds;
  while(rounds--) {
    cin >> c;
    switch (c%2)
    {
    case 0:
      cout << "0\n";
      break;
    default:
      cout << "1\n";
      break;
    }
  }
}