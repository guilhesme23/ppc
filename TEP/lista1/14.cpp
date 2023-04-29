#include <cmath>
#include <iostream>
#include <map>
#include <utility>

using namespace std;
using ll = long;

map<ll, ll> cache;

ll ackerman(ll n) {
  // If is a cached result, return it.
  if (cache[n]) return cache[n];

  // If function already converged to 1, return 0. 
  if (n == 1) {
    return 0;
  }

  // If n is a power of 2, return log2(n) since it will be the number of times n will be divided by 2.
  if (!(n & (n-1))) {
    cache[n] = log2(n);
    return cache[n];
  }

  // General function rule and recursive call
  if (n & 1) {
    cache[n] = 1 + ackerman(3 * n + 1);
  } else {
    cache[n] = 1 + ackerman(n / 2);
  }

  return cache[n];
}

pair<ll, ll> solve(ll l, ll h) {
  pair<ll, ll> result;
  result.first = 0;
  result.second = 0;
  ll tmp;
  for (auto x = l; x <= h; x++) {
    tmp = ackerman(x);
    // If argument is 1, return 3
    if (x == 1) tmp = 3;
    if (tmp > result.second) {
      result.first = x;
      result.second = tmp;
    }
  }

  return result;
}

int main() {
  ll l, h;
  pair<ll, ll> res;
  while (true) {
    cin >> l >> h;
    if (!l && !h) break;
    if (l > h) swap(l,h);
    res = solve(l, h);
    cout << "Between " << l << " and " << h << ", " << res.first << " generates the longest sequence of " << res.second <<" values.\n";
  }
  
  return 0;
}