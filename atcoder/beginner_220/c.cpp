#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, total = 0, x;
  cin >> n;
  vector<ll> a(n);
  for (auto i = 0LL; i < n; ++i) {
    cin >> a[i];
    total += a[i];
  }
  cin >> x;

  ll res;
  res = x / total;
  total = total * res;
  res = res * (ll) a.size();

  for (auto el : a) {
    total += el;
    ++res;
    if (total > x) break;
  }

  cout << res << '\n';
   
}
