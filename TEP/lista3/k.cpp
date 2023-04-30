#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int main() {
  ll N;
  while (true) {
    cin >> N;
    if (N < 0) return 0;

    string res = "";
    while(N) {
      res += to_string(N%3);
      N /= 3;
    }
    
    if (res.length() == 0) res = "0";
    
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
}
