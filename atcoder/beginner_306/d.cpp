#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

using ii = pair<long long, long long>;

int main() {
	int n;
	cin >> n;
	vector<ii> course(n);
	vector<ii> bests;
	set<ii> bigger;
	int current = -1;
	for (auto i = 0; i < n; ++i) {
		cin >> course[i].first >> course[i].second;
		if (current >=0 and course[i].first != current) {
			auto b = *bigger.rbegin();
			bests.push_back(b);
			bigger = {};
		}

		current = course[i].first;
		bigger.insert(course[i]);
	}
	auto b = *bigger.rbegin();
	bests.push_back(b);

	long long total = 0;
	int upset = 0;

	cout << "========\n";
	for (auto el : bests) {
		cout << el.first << ' ' << el.second << '\n';
	}
	cout << "========\n";

	for (auto it = bests.begin(); it != bests.end(); ++it) {
		auto peek = next(it);
		if (!upset and it->second < 0) {
			continue;
		}

		if ((!it->first and it->second > 0) or (!upset and it->first and it->second > 0) or (peek != bests.end() and upset and !it->first and peek->second >= it->second)) {
			upset = it->first;
			total += it->second;
		}
	}

	cout << total << '\n';
}
