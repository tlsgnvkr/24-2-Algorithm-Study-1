#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 2147483647

vector<vector<pair<int, int>>> val;

int sum(int dx, int mid, int dy) {
	return val[dx][mid].first * val[dx][mid].second * val[mid + 1][dy].second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> matrix(n + 1, { 0, 0 });
	val = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(n + 1, { 0, 0 }));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i += 1) {
		cin >> matrix[i].first >> matrix[i].second;
		val[i][i] = matrix[i];
	}
	
	for (int i = 1; i <= n; i += 1) {
		for (int dx = 1; dx + i <= n; dx += 1) {
			int dy = dx + i;
			dp[dx][dy] = MAX;

			for (int mid = dx; mid < dy; mid += 1) {
				int temp = dp[dx][mid] + dp[mid + 1][dy] + sum(dx, mid, dy);
				dp[dx][dy] = min(dp[dx][dy], temp);
			}

			val[dx][dy].first = matrix[dx].first;
			val[dx][dy].second = matrix[dy].second;
		}
	}

	cout << dp[1][n] << endl;
	return 0;
}
