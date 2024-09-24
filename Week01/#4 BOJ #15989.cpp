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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n <= 3) {
			cout << n << endl;
			continue;
		}

		vector<vector<int>> dp(n + 1, vector<int>(4, 0));
		// dp[x][i] : x를 만들 수 있는 수식 중에서, 오름차순으로 정렬 시 마지막 수가 i인 개수
		dp[1][1] = 1;
		dp[2][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1;

		for (int i = 4; i <= n; i += 1) {
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}

		cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
	}
	return 0;
}
