#include <bitset>
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 64;

int main() {
	string s;
	getline(cin, s);
	string sanitized = "";
	for (auto c = s.crbegin(); c != s.crend(); c++) {
		if (*c != ' ') {
			sanitized.push_back(*c);
		}
	}
	bitset<SIZE> b(sanitized);
	cout << b.to_ullong() << '\n';
}
