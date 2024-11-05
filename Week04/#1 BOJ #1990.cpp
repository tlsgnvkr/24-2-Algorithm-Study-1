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

vector<bool> isPrime;

void eratosthenes(int num) {
	isPrime = vector<bool>(num + 1, false);
	isPrime[1] = true;
	for (int i = 2; i <= sqrt(num); i += 1) {
		if (isPrime[i]) continue;
		for (int j = i; i * j <= num; j += 1) isPrime[i * j] = true;
	}
}

bool isPalindrome(string num) {
	int s = 0, e = num.size() - 1;
	while (s < e) {
		if (num[s] == num[e]) {
			s += 1;
			e -= 1;
		}
		else return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	if (b > 10000000) b = 10000000;

	eratosthenes(b);

	for (int i = a; i <= b; i += 1) {
		if (!isPrime[i] && isPalindrome(to_string(i))) {
			cout << i << "\n";
		}
	}

	cout << -1 << "\n";
	return 0;
}
