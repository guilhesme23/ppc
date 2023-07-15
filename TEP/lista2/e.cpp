#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solve_quad(long long a, long long b, long long c) {
  long long delta = b * b - 4 * a * c;
  if (delta < 0)
    return -1;

  long r = round(sqrt(delta));
  long x0 = (-b + r) / (2 * a);
  long x1 = (-b - r) / (2 * a);
  return max(x0, x1);
}

bool check(long long a, long long b, long long N) {
  long long s = round(((b - a + 1)) * (a + b) / 2);
  return s == N;
}

int main() {
  long long N;
  while (true) {
    cin >> N;
    if (N < 0) return 0;

    long long a = 1;
    long long C;
    long long res = -1;
    while (!check(a, res, N) and a < N) {
      C = -(2 * N) -(a * a) + a;
      res = solve_quad(1, 1, C);
      if (!check(a, res, N)) ++a;
    }

    if (!check(a, res, N)) res = a;
    cout << N << " = " << a << " + ... + " << res << '\n';
  }
}
