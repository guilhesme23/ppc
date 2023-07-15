#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

struct R {
  ll x;
  ll lo;
  ll hi;
  R(ll x, ll lo, ll hi) : x(x), lo(lo), hi(hi) {}
  bool operator<(const R &a) { return (a.x > x && a.hi > hi); };
};

struct ccomp {
  bool operator()(const R &a, const R &b) {
    return !((a.x <= b.x) && (a.hi < b.hi));
  }
};

bool isIncluded(R r, ll val) { return r.hi > val && val >= r.lo; }

int main() {
  ll n, q;
  vector<R> roadworks; 
  priority_queue<R, vector<R>, ccomp> buf1, buf2;

  cin >> n >> q;

  for (auto i = 0; i < n; i++) {
    ll s, t, x;
    cin >> s >> t >> x;
    buf1.push(R(x, s - x, t - x));
  }

  ll t0;
  bool found = false;
  for (;q;q--) {
    cin >> t0;

    while (!buf1.empty()) {
      R r = buf1.top();
      buf1.pop();
      buf2.push(r);

      if (isIncluded(r, t0)) {
        cout << r.x << '\n';
        found = true;
        break;
      }
    }

    while (!buf2.empty()) {
      buf1.push(buf2.top());
      buf2.pop();
    }

    if (!found)
      cout << -1 << '\n';
    found = false;
  }
  return 0;
}
