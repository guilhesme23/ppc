#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;
using ll = long long;
const auto BITSIZE = 64;

int main() {
  ll l, r;

  cin >> l >> r;
  if (l > r) {
    cout << "0\n";
    return 0;
  }

  auto L = std::bitset<BITSIZE>(l);
  auto R = std::bitset<BITSIZE>(r);
  auto res = std::bitset<BITSIZE>(0);

  for (auto i = BITSIZE - 1; i >= 0; i--) {
    if (L[i] + R[i] == 2) continue;
    if (L[i] + R[i] < 2 && L[i] == 0 && R[i] == 0 && res.to_ulong() == 0) continue;
    res.set(i, true);
  }

  cout << res.to_ullong() << '\n';
  return 0;
}
