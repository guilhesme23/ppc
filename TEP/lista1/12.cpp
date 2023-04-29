#include <iostream>

using namespace std;

long long solve(long long n) {
  if (n == 0) return 0;

  if (n&1) return solve(n-1) - n;
  
  return n/2;
}

int main() {
  long long n;
  cin >> n;
  cout << solve(n) << '\n';
  return 0;
}