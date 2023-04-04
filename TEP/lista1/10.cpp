#include <iostream>
#include <map>
#define ll long long

using namespace std;

int main() {
  ll j1, j2, tmp;
  ll total = 0;
  ios_base::sync_with_stdio(false);

  while (cin >> j1 >> j2) {
    if (!j1 && !j2) return 0;
    map<ll, ll> uniques;
    for (auto i = 0; i < j1; i++) {
      cin >> tmp;
      uniques[tmp] = 1;
    }

    for (auto i = 0; i < j2; i++) {
      cin >> tmp;
      if (uniques[tmp]) ++total;
    }

    cout << total << '\n';
    total = 0;
  }
}