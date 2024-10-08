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

vector<string> val;
vector<int> val_bit;

int n;

int f(int idx, int cnt) {
	if (cnt == (1 << 26) - 1) {
		return 1 << (n - idx);
	}

	if (idx == n) {
		return 0;
	}

	return f(idx + 1, cnt | val_bit[idx]) + f(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i += 1) {
		string s;
		cin >> s;
		val.push_back(s);
	}

	for (int i = 0; i < n; i += 1) {
		int cnt = 0;
		for (auto x : val[i]) cnt |= (1 << x - 'a');
		val_bit.push_back(cnt);
	}

	cout << f(0, 0) << endl;
	return 0;
}
