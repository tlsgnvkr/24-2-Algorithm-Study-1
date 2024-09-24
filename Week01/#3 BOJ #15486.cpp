// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> t(n + 1, 0);
	vector<int> p(n + 1, 0);
	vector<int> dp(n + 2, 0);
	for (int i = 1; i <= n; i += 1) cin >> t[i] >> p[i];

	int res = 0;
	for (int i = 1; i <= n; i += 1) {
		dp[i] = max(dp[i], res);
		if (i + t[i] <= n + 1) dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		res = max(res, dp[i]);
	}

	res = max(res, dp[n + 1]);
	cout << res << endl;
	return 0;
}
