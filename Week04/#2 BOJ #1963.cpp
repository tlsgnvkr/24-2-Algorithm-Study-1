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

vector<bool> isPrime;
vector<bool> visited(10001, false);

void eratosthenes(int num) {
	isPrime = vector<bool>(num + 1, false);
	isPrime[1] = true;
	for (int i = 2; i <= sqrt(num); i += 1) {
		if (isPrime[i]) continue;
		for (int j = i; i * j <= num; j += 1) isPrime[i * j] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	eratosthenes(10000);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		queue<pair<string, int>> q;
		visited = vector<bool>(10001, false);
		visited[a] = true;
		q.push(make_pair(to_string(a), 0));
		while (q.size()) {
			string s = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (stoi(s) == b) {
				cout << cnt << endl;
				goto EXIT;
			}

			for (int i = 49; i <= 57; i += 1) {
				string ns = s;
				ns[0] = i;
				if (visited[stoi(ns)]) continue;
				if (!isPrime[stoi(ns)]) {
					q.push(make_pair(ns, cnt + 1));
					visited[stoi(ns)] = true;
				}
			}
			for (int i = 48; i <= 57; i += 1) {
				for (int j = 1; j <= 3; j += 1) {
					string ns = s;
					ns[j] = i;
					if (visited[stoi(ns)]) continue;
					if (!isPrime[stoi(ns)]) {
						q.push(make_pair(ns, cnt + 1));
						visited[stoi(ns)] = true;
					}
				}
			}
		}
		cout << "Impossible" << "\n";

	EXIT:
		continue;
	}
}
