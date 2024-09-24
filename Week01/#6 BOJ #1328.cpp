// https://www.acmicpc.net/problem/1328

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

#define ll long long int

int mod = 1e9 + 7;
int dp[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i += 1) {
		for (int j = 1; j <= l; j += 1) {
			for (int k = 1; k <= r; k += 1) {
				dp[i][j][k] = ((ll)dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1]) % mod;
			}
		}
	}

	cout << dp[n][l][r] << endl;
	return 0;
}
