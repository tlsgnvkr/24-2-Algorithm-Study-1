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

struct Team {
	ll k;
	ll da;
	ll db;
};

bool cmp(const Team& a, const Team& b) {
	return abs(a.db - a.da) > abs(b.db - b.da);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (!n && !a && !b) break;

		vector<Team> teams;
		for (int i = 0; i < n; i += 1) {
			ll k, da, db;
			cin >> k >> da >> db;
			teams.push_back({ k, da, db });
		}

		sort(teams.begin(), teams.end(), cmp);

		ll res = 0;
		for (ll i = 0; i < n; i += 1) {
			if (teams[i].da < teams[i].db) {
				if (a >= teams[i].k) {
					res += teams[i].k * teams[i].da;
					a -= teams[i].k;
				}
				else {
					res += a * teams[i].da;
					teams[i].k -= a;
					a = 0;
					res += teams[i].k * teams[i].db;
					b -= teams[i].k;
				}
			}
			else {
				if (b >= teams[i].k) {
					res += teams[i].k * teams[i].db;
					b -= teams[i].k;
				}
				else {
					res += b * teams[i].db;
					teams[i].k -= b;
					b = 0;
					res += teams[i].k * teams[i].da;
					a -= teams[i].k;
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}
