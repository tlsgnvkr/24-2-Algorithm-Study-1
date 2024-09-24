// https://www.acmicpc.net/problem/13699

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<ll> dp(n + 1, 1);
	for (int i = 1; i <= n; i += 1) {
		ll temp = 0;
		for (int j = 0; j <= i - 1; j += 1) {
			temp += dp[j] * dp[i - 1 - j];
		}
		dp[i] = temp;
	}

	cout << dp[n] << endl;
	return 0;
}
