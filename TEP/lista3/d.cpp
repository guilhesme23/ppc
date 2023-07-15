#include <iostream>
#include <map>
#include <utility>

using namespace std;
using ll = long long;

map<pair<ll, ll>, ll> cache;

ll xp(ll x, ll y) {
    if (y == 0) {
        return 1;
    }

    if (cache[{x, y}]) return cache[{x, y}];

    ll temp = xp(x, y / 2);
    if (y % 2 == 0) {
        cache[{x, y}] = temp * temp;
    } else {
        cache[{x,y}] = x * temp * temp;
    }

    return cache[{x,y}];
}

int main() {
  ll x;
  while (cin >> x) {
    ll total = 0;
    for (auto i = 1LL; i <= x; ++i) {
      total += xp(i, 3);
    }

    cout << total << '\n';
  }
}
