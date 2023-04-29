#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using M = vector<string>;
using pt = pair<int, int>;

set<pt> visited = {};

int bfs(const M &g, pt origin) {
  queue<pt> q({origin});
  int h = (int)g.size(), w = (int)g[0].size();
  int counter = 0;
  while (!q.empty()) {
    pt p = q.front();
    q.pop();
    if (visited.find(p) != visited.end() or g[p.first][p.second] == '.')
      continue;

    visited.insert(p);
    if (g[p.first][p.second] == '#')
      ++counter;

    for (auto i = p.first - 1; i <= p.first + 1; ++i) {
      for (auto j = p.second - 1; j <= p.second + 1; ++j) {
        if (visited.find({i, j}) != visited.end() or
            !(i >= 0 and i < h and j >= 0 and j < w))
          continue;
        q.push({i, j});
      }
    }
  }

  return counter;
}

int main() {
  int h, w;
  cin >> h >> w;
  M grid(h);
  vector<int> result(min(h, w), 0);
  for (int i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == '#') {
        if (visited.find({i, j}) != visited.end())
          continue;

        int n = bfs(grid, {i, j});
        n = (n + 1) / 4;
        result[n-1] += 1;
      }
    }
  }

  for (auto el : result) {
    cout << el << " ";
  }

  cout << '\n';

  return 0;
}
