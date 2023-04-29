#include <iostream>
#include <set>

using namespace std;

int main() {
  char c;
  set<char> input;
  while(cin >> c) {
    input.insert(c);
  }

  string res = (input.size() % 2 == 0) ? "CHAT WITH HER!\n" : "IGNORE HIM!\n";
  cout << res;
}