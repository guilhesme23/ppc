#include <iostream>

using namespace std;

int main() {
  while(true) {
    int n;
    cin >> n;
    if (!n) return 0;

    int pA = 0, pB = 0;
    while(n--) {
      int a, b;
      cin >> a >> b;

      if (a > b) {
        pA++;
      } else if (b > a) {
        pB++;
      }
    }

    cout << pA << " " << pB << endl;
  }
}