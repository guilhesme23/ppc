#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N), b(N);

  for (ll i = 0; i < N; ++i) {
    cin >> a[i];
  }

  for (ll i = 0; i < N; ++i) {
    cin >> b[i];
  }

  ll total = 0;
  for (auto ai : a) {
    for (auto bi : b) {
      total ^= (ai + bi);
    }
  }

  cout << total << '\n';

}
