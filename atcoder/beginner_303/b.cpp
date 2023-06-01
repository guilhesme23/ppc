#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

using ii = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> photos(m);
  for (auto i = 0; i < m; ++i) {
    cin >> photos[i];
  }
  map<ii, int> pairs;

  // Get possible pairs
  vector<int> base(n);
  vector<int> perms;
  iota(base.begin(), base.end(), 1);
  
  do {
    for (auto el : base) {
      perms.push_back(el);
    }
  } while(next_permutation(base.begin(), base.end()));

  for (int i = 0; i < m; ++i) {
    stringstream ss;
    ss << photos[i];
    int a, b;
    ss >> a;
    while(ss >> b) {
      pairs[{a,b}] += 1;
      pairs[{b,a}] += 1;
      a = b;
    }
  }

  int sad = 0;
  for (auto i = 0; i < (int) perms.size() - 1; ++i) {
    ii p = {perms[i], perms[i+1]};
    if (pairs[p] == 0) {
      sad++;
      pairs[p] = 1;
      pairs[{p.second, p.first}] = 1;
    };
  }

  cout << sad << '\n';

  return 0;
}
