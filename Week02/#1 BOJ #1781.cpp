// https://www.acmicpc.net/problem/1781

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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int date = 0;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i += 1) {
		int a, b;
		cin >> a >> b;
		date = max(date, a);
		pq.push(make_pair(a, b));
	}

	int res = 0;
	priority_queue<pair<int, int>> temp;
	while (date) {
		while (pq.size() && pq.top().first >= date) {
			temp.push(make_pair(pq.top().second, pq.top().first));
			pq.pop();
		}

		if (temp.size()) {
			res += temp.top().first;
			temp.pop();
		}

		date -= 1;
	}

	cout << res << endl;
	return 0;
}
