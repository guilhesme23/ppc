#include <iostream>
#include <deque>

using namespace std;

int main() {
  char c;
  string buffer;
  
  while (cin >> c) {
    if (c == 'B' && !buffer.empty()) {
      buffer.pop_back();
    } else if (c == '0' || c == '1') {
      buffer.push_back(c);
    }
  }

  cout << buffer << '\n';

  return 0;
}