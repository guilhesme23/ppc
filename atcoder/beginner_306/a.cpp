#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	for (auto c : s) {
		cout << c << c;
	}

	cout << '\n';
}
