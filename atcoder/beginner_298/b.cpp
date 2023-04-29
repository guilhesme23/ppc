#include <cstddef>
#include <iostream>
#include <utility>
#include <set>
#include <vector>

using namespace std;
using mat = vector<vector<int>>;

mat rotate(mat A, int N, set<pair<int, int>> &iA) {
  mat res(A);
  iA.clear();
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      res[i][j] = A[(N-1-j)%N][i];
      if (res[i][j] & 1) iA.insert({i, j});
    }
  }
  return res;
}

int main() {
  mat A, B;
  set<pair<int, int>> iA, iB;
  int N;

  cin >> N;

  int tmp;
  for (auto i = 0; i < N; ++i) {
    vector<int> cols;
    A.push_back(cols);
    for (auto j = 0; j < N; ++j) {
      cin >> tmp;
      A[i].push_back(tmp);
      if (tmp & 1) iA.insert({i, j});
    }
  }

  for (auto i = 0; i < N; ++i) {
    vector<int> cols;
    B.push_back(cols);
    for (auto j = 0; j < N; ++j) {
      cin >> tmp;
      B[i].push_back(tmp);
      if (tmp & 1) iB.insert({i, j});
    }
  }
  
  for (auto i = 0; i < 4; i++) {
    size_t count = 0;

    for (auto p : iA) {
      if (!B[p.first][p.second]) {
        break;
      }
      count += 1;
    }
    if (count == iA.size()) {
      cout << "Yes\n";
      return 0;
    }
    A = rotate(A, N, iA);
  }

  cout << "No\n";
  return 0;
}
