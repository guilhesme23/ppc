#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

vector<bool> genPrimes() {
  ll n = 1000001;
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
  ll x;
  cin >> x;
  vector<bool> primes = genPrimes();

  while(!primes[x]) {
    ++x;
  }

  cout << x << '\n';
}
