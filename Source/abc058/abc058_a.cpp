#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (b - a == c - b) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
