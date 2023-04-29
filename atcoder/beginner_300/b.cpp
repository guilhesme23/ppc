#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using M = vector<string>;

M shift(M a, int s, int t) {
  int h = (int) a.size();
  int w = (int) a[0].size();

  M res(a);
  for (auto i = 0; i < h; ++i) {
    for (auto j = 0; j < w; ++j) {
      res[(i+h-s)%h][(j+w-t)%w] = a[i][j];
    }
  }

  return res;
}

int main() {
  int h, w;
  cin >> h >> w;

  M a(h), b(h);

  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < h; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (shift(a, i, j) == b) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";
}
