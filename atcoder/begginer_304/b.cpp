#include <iostream>
#include <string>

using namespace std;

using ll = long long;

const ll c1 = 1000;
const ll c2 = 10000;
const ll c3 = 100000;
const ll c4 = 1000000;
const ll c5 = 10000000;
const ll c6 = 100000000;
const ll c7 = 1000000000;
const ll c8 = 10000000000;

string trunc(string s, int d) {
  for (int i = d; i < (int) s.size(); ++i) {
    s[i] = '0';
  }

  return s;
}

int main() {
  string n;
  cin >> n;
  ll c = stoll(n);
  int d = (int) n.size();
  if (c < c1) {
    cout << n << '\n';
  } else if (c >= c1 && c < c2) {
    cout << trunc(n, d-1) << '\n';
  } else if (c >= c2 && c < c3) {
    cout << trunc(n, d-2) << '\n';
  } else if (c >= c3 && c < c4) {
    cout << trunc(n, d-3) << '\n';
  } else if (c >= c4 && c < c5) {
    cout << trunc(n, d-4) << '\n';
  } else if (c >= c5 && c < c6) {
    cout << trunc(n, d-5) << '\n';
  } else if (c >= c6 && c < c7) {
    cout << trunc(n, d-6) << '\n';
  }

  return 0;
}
