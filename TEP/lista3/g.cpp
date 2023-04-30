#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {

  string a;
  cin >> a;

  auto p = a.find_first_of('0');
  if (p != string::npos) {
    a.erase(a.find_first_of('0'), 1);
    a.erase(0, a.find_first_not_of('0'));
  } else {
    a.erase(0, 1);
  }
  cout << a << '\n';
}
