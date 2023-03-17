#include <iostream>
#include <set>
#include <algorithm>

int main() {
  std::string A, B, C;
  int total = 0;

  while(std::cin >> A >> B >> C) {
    std::set<char> sA, sB, sC;

    std::copy(A.begin(), A.end(), std::inserter(sA, sA.begin()));
    std::copy(B.begin(), B.end(), std::inserter(sB, sB.begin()));
    std::copy(C.begin(), C.end(), std::inserter(sC, sC.begin()));

    std::string result, tmp;
    std::set_intersection(sA.begin(), sA.end(), sB.begin(), sB.end(), std::inserter(tmp, tmp.begin()));
    std::set_intersection(tmp.begin(), tmp.end(), sC.begin(), sC.end(), std::inserter(result, result.begin()));

    if (islower(result[0])) {
      total += static_cast<int>(result[0]) - 96;
    } else {
      total += static_cast<int>(result[0]) - (64 - 26);
    }
  }

  std::cout << total << std::endl;
  return 0;
}