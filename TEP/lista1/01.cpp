#include <iostream>

std::string solve(int a, int b, int c, int d) {
  std::string res = "No";
  if ((abs(a-b) <= d && abs(b-c) <= d) || abs(a-c) <= d) {
    res = "Yes";
  }

  return res;
}

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << solve(a,b,c,d) << '\n';
  return 0;
}
