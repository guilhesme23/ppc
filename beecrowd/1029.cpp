#include <iostream>

using namespace std;

int count = 0;

pair<int, int> fib(int n) {
  if (n <= 1) {
    return {n, count};
  }

  count += 2;
  return {fib(n-1).first + fib(n-2).first, count};
}

int main() {
  int n, tests;
  cin >> tests;
  
  while (tests--) {
    cin >> n;
    count = 0;
    pair<int, int> result = fib(n);
    printf("fib(%d) = %d calls = %d\n", n, result.second, result.first);
  }
}

