#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

using ii = pair<int, int>;

int dd(ii a, ii b) {
  return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

int main() {
  int n, d;
  cin >> n >> d;
  vector<ii> pairs(n);
  set<ii> inf;

  for (auto i = 0; i < n; ++i) {
    cin >> pairs[i].first >> pairs[i].second;
  }

  inf.insert(pairs[0]);

  for (auto p : inf) {
    for (auto o : pairs) {
      if (dd(p, o) <= d) {
        inf.insert(o);
      }
    }
  }

  for (auto p : pairs) {
    if (inf.find(p) != inf.end()) {
      cout << "Yes\n";
      continue;
    }

    cout << "No\n";
  }
}
