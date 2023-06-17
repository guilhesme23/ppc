#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	set<int> pre_center, centered;
	vector<int> result;
	for (auto i = 0; i < 3*n; ++i) {
		cin >> a;
		if (pre_center.find(a) != pre_center.end() and centered.find(a) == centered.end()) {
			centered.insert(a);
			result.push_back(a);
		}
		if (pre_center.find(a) == pre_center.end()) {
			pre_center.insert(a);
		}
	}

	for (auto el : result) {
		cout << el << ' ';
	}
	cout << '\n';
}
