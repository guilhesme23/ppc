#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;
using ll = long long;

int main() {
  ll m = numeric_limits<ll>::max();
  int mIdx = 0;
  ll n;
  cin >> n;
  vector<pair<string, ll>> table(n);

  for (auto i = 0LL; i < n; ++i) {
    cin >> table[i].first >> table[i].second;
    if (table[i].second < m) {
      mIdx = i;
      m = table[i].second;
    }
  }

  for (auto i = mIdx; i < n; ++i) {
    cout << table[i].first << '\n';
  }

  for (auto i = 0LL; i < mIdx; ++i) {
    cout << table[i].first << '\n';
  }

  return 0;
}
