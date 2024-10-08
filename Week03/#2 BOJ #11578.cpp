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

	int n, m;
	cin >> n >> m;

	vector<int> checkList(m, 0);
	for (int i = 0; i < m; i += 1) {
		int o;
		cin >> o;

		int temp = 0;
		for (int j = 0; j < o; j += 1) {
			int k;
			cin >> k;
			temp += 1 << (k - 1);
		}
		checkList[i] = temp;
	}

	int res = -1;
	for (int i = 1; i < (1 << m); i += 1) {
		int cnt = 0;
		int solved = 0;
		for (int j = 0; j < m; j += 1) {
			if (i & (1 << j)) {
				cnt += 1;
				solved |= checkList[j];
			}
		}

		if (solved == (1 << n) - 1) {
			if (res == -1) res = cnt;
			else res = min(res, cnt);
		}
	}

	cout << res << endl;
	return 0;
}
