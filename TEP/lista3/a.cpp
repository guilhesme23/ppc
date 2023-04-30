#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

using ll = long long;

vector<double> solve(ll a, ll b, ll c) {
  vector<double> res = {};

  ll delta = b * b - 4 * a * c;
  if (!a) {
    double r = (-c) / (double) b;
    if (!b) return res;
    res.push_back(r);
    return res;
  }

  if (delta < 0)
    return res;

  if (delta == 0) {
    double x1 = (-b - sqrt(delta)) / (2 * a);
    res.push_back(x1);
    sort(res.begin(), res.end());
    return res;
  }

  double r = sqrt(delta);
  double x0 = (-b + r) / (2 * a);
  double x1 = (-b - r) / (2 * a);
  res.push_back(x0);
  res.push_back(x1);
  sort(res.begin(), res.end());
  return res;
}

int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  cout << setprecision(10);
  cout << fixed;
  if (!a and !b and !c) {
    cout << (double) -1 << '\n';
    return 0;
  }

  vector<double> res = solve(a,b,c);
  cout << res.size() << '\n';
  for (auto el : res) {
    cout << (double) el << '\n';
  }
}
