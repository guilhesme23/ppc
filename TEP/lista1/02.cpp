#include <bitset>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
const auto MAX = 64;

unsigned long long f(bitset<MAX> x, vector<bitset<MAX>> l) {
  long res = 0;
  for (auto el : l) {
    res += (x ^ el).to_ullong();
  }
  return res;
}

unsigned long long solve(vector<bitset<MAX>> l, unsigned long long k) {
  bitset<MAX> x(0);

  for (auto i = MAX - 1; i >= 0; --i) {
    unsigned long long count0 = 0, count1 = 0;
    for (auto el : l) {
      if (el[i]) {
        ++count1;
      } else {
        ++count0;
      }
    }

    if (count0 > count1) {
      x.set(i, true);
    }

    if (x.to_ullong() > k) {
      x.set(i, false);
    }
  }
  return f(x, l);
}

int main() {
  unsigned long long n, k, tmp;
  cin >> n >> k;
  vector<bitset<MAX>> l;
  l.reserve(n);
  while (n--) {
    cin >> tmp;
    l.push_back(bitset<MAX>(tmp));
  }

  cout << solve(l, k) << '\n';

  return 0;
}
