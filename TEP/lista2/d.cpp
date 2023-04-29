#include <iostream>

using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    int res = n, butts = n;

    while(butts >= k) {
      int tmp = butts;
      res += tmp / k;
      butts /= k;
      butts += tmp % k;
    }

    cout << res << '\n';
  }
}
