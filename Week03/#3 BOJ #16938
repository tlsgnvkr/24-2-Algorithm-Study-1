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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, r, x;
	cin >> n >> l >> r >> x;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i += 1) cin >> a[i];

	// 몰라 걍 브루트포스 돌리자...
	
	sort(a.begin(), a.end());
	
	int res = 0;
	for (int i = 1; i < (1 << n); i += 1) {
		vector<int> temp;
		int min_value = 0;
		for (int k = 0; k < n; k += 1) {
			if (i & (1 << k)) {
				if (temp.empty()) min_value = a[k];
				temp.push_back(a[k]);
			}
		}
		int max_value = temp.back();
		if (temp.size() >= 2) {
			int sum_value = accumulate(temp.begin(), temp.end(), 0);
			if (l <= sum_value && sum_value <= r && max_value - min_value >= x) res += 1;
		}
	}
	
	cout << res << endl;
	return 0;
}
