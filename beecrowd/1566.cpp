#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

size_t merge(vector<int> left, vector<int> right, vector<int> &target)
{
  size_t l = 0, r = 0, i = 0;
  size_t swaps = 0;

  while (l < left.size() && r < right.size())
  {
    if (left[l] <= right[r])
    {
      target[i] = left[l];
      l++;
      i++;
    }
    else
    {
      target[i] = right[r];
      r++;
      i++;
      swaps += (left.size() - l);
    }
  }

  while (l < left.size())
  {
    target[i] = left[l];
    l++;
    i++;
  }

  while (r < right.size())
  {
    target[i] = right[r];
    r++;
    i++;
  }

  return swaps;
}

// return number of swaps
size_t merge_sort(vector<int> &array)
{
  size_t len = array.size();
  if (len <= 1)
    return 0;

  size_t half = ceil(len / 2);

  vector<int> left;
  vector<int> right;

  left.assign(array.begin(), array.begin() + half);
  right.assign(array.begin() + half, array.end());

  auto swaps1 = merge_sort(left);
  auto swaps2 = merge_sort(right);
  auto swaps3 = merge(left, right, array);

  return swaps1 + swaps2 + swaps3;
}

int main() {
  int nc;
  cin >> nc;
  while(nc--) {
    int n, tmp;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> citzens;
    while(ss >> tmp) {
      citzens.push_back(tmp);
    }

    merge_sort(citzens);
    for (auto it = citzens.begin(); it < citzens.end(); it++) {
      if (it != citzens.end() && next(it) == citzens.end()) {
        printf("%d\n", *it);
        continue;
      };

      printf("%d ", *it);
    }
  }

  return 0;
}