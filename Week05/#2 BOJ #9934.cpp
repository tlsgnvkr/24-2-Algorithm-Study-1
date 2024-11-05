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

	int k;
	cin >> k;

	int n = pow(2, k) - 1;
	vector<int> val(n + 1);
	for (int i = 1; i <= n; i += 1) cin >> val[i];

	int idx = (n + 1) / 2;
	cout << val[idx] << endl;
	int d = idx;
	idx /= 2;
	while (idx) {
		for (int i = 0; idx + i * d <= n; i += 1) cout << val[idx + i * d] << " ";
		cout << endl;

		idx /= 2;
		d /= 2;
	}
	return 0;
}
