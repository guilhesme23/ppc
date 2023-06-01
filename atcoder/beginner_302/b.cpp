#include <iostream>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

void get_nbr(pair<int, int> pos, int h, int w, stack<pair<int, int>> &to_visit) {
}

vector<pair<int, int>> find_word(vector<string> grid, string word) {
  int h = (int) grid.size();
  int w = (int) grid[0].size();
  int idx = 0;
  set<pair<int,int>> visited = {};
  vector<pair<int, int>> result = {};
  stack<pair<int,int>> to_visit = {};
  set<char> searching(word.begin(), word.end());
  string last = "";


  for (auto i = 0; i < h; ++i) {
    for (auto j = 0; j < w; ++j) {
      if (searching.empty()) break;
      if (searching.find(grid[i][j]) != searching.end()) continue;

      to_visit.push({i, j});
      // DFS <- Find 'snuke' component
      while(!to_visit.empty()) {
        auto p = to_visit.top();
        to_visit.pop();
        if (searching.find(grid[p.first][p.second]) != searching.end()) {
          result.push_back(p);
        }
        searching.erase(grid[p.first][p.second]);
        visited.insert(p);


      }
    }
  }
  return {};
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (auto i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  auto result = find_word(grid, "snuke");

  for (auto p : result) {
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}
