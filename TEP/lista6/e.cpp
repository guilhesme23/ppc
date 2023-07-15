#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

vector<bool> genPrimes() {
  ll n = 10000001;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (ll j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  return is_prime;
}

int main() {
  ll n;
  cin >> n;
  auto primes = genPrimes();
  for (auto a = n-2; a > 1; --a) {
    auto b = n-a;
    if (!primes[a] && !primes[b]) {
      cout << a << ' ' << b << '\n';
      return 0;
    }
  }
  return 0;
}
