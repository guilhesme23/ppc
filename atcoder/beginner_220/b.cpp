#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

ll toBase10(string n, int k) {
  ll res = 0;

  ll exp = 0;
  for (auto el = n.rbegin(); el != n.rend(); ++el) {
    res += pow(k,exp) * (int) (*el - '0');
    ++exp;
  }

  return res;
}

int main() {
  int k;
  string a, b;
  cin >> k >> a >> b;

  cout << toBase10(a,k) * toBase10(b,k) << '\n';
}
