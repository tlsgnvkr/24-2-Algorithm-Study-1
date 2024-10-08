#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
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

	ll n, m;
	cin >> n >> m;

	vector<ll> chance(n, 0);
	for (ll i = 0; i < n; i += 1) {
		string t, s;
		cin >> t >> s;
		for (ll j = 0; j < m; j += 1) {
			if (s[j] == 'Y') chance[i] += (1LL << j);
		}
	}

	ll res = n;
	vector<ll> minValue(m + 1, n + 1);
	for (ll i = 0; i < (1LL << n); i += 1) {
		ll setList = 0;
		ll cnt_guitar = 0;
		ll cnt_setList = 0;
		for (ll j = 0; j < n; j += 1) {
			if (i & (1LL << j)) {
				setList |= chance[j];
				cnt_guitar += 1;
			}
		}
		for (ll j = 0; j < m; j += 1) {
			if (setList & (1LL << j)) cnt_setList += 1;
		}
		minValue[cnt_setList] = min(minValue[cnt_setList], cnt_guitar);
	}

	reverse(minValue.begin(), minValue.end());
	for (auto x : minValue) {
		if (x && x != n + 1) {
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
