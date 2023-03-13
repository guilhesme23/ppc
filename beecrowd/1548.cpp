#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::size_t;
using std::endl;

size_t merge(vector<int> left, vector<int> right, vector<int> &target)
{
  size_t l = 0, r = 0, i = 0;
  size_t swaps = 0;

  while (l < left.size() && r < right.size())
  {
    if (left[l] >= right[r])
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
  int t;
  cin >> t;
  while(t--) {
    int n;
    vector<int> queue;
    cin >> n;
    for(auto i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      queue.push_back(tmp);
    }
    vector<int> cc;
    cc.assign(queue.begin(), queue.end());
    merge_sort(queue);
    int count = 0;
    
    for(int i = 0; i < n; i++) {
      if (cc[i] == queue[i]) {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}