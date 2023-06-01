#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  ll c = a / b;
  if (a-c*b > 0) c += 1;
  cout << c << '\n';
  return 0;
}
