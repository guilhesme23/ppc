#include <iostream>
#include <set>

using namespace std;

int main() {
  long tmp, i = 4;
  set<long> shoes;
  while (i--) {
    cin >> tmp;
    shoes.insert(tmp);
  }

  cout << 4 - shoes.size() << '\n';
  return 0;
}