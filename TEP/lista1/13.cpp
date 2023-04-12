#include <cstdio>
#include <ios>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  long double n, k;
  cin >> n >> k;
  cout << std::fixed;
  std::printf("%lld\n", (long long) ceil(k/n));
}
