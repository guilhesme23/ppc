#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b-a>1 || a%3==0) {
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	return 0;
}
