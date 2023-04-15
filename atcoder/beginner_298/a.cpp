#include <iostream>

using namespace std;

int main() {
  int good_count = 0, bad_count = 0;
  int n;
  char s;
  cin >> n;

  while (n--) {
    cin >> s;
    if (s == 'o') ++good_count;
    if (s == 'x') ++bad_count;
  }

  string result = (good_count > 0 && bad_count == 0) ? "Yes" : "No";

  cout << result << '\n';
}
  
