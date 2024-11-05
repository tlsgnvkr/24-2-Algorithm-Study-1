#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstring>
using namespace std;

typedef long long int ll;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}

int gcd(int a, int b) {
	while (a) {
		if (a < b) swap(a, b);
		a %= b;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << b - gcd(a, b) << endl;
	return 0;
}
