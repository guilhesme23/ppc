#include <ios>
#include <limits>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll xp(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll temp = xp(x, y / 2);
    if (y % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

ll solve(vector<ll> cfs, ll n, ll x) {
  ll total = 0;
  n = n-1;
  for (ll i = 0; i < n; ++i) {
    total += cfs[i] * (n-i) * xp(x, (n-i-1));
  }

  return total;
}

int main() {
  ll x;
  string input;
  while (getline(cin, input) and input.size()) {

    x = stoll(input);
    ll tmp;
    getline(cin, input);

    istringstream is(input);
    vector<ll> poly;

    while(is >> tmp) {
      poly.push_back(tmp);
    }

    cout << solve(poly, (ll) poly.size(), x) << '\n';
  }
}
