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

	int max_value = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i += 1) {
		int x;
		cin >> x;
		pq.push(x);
		max_value = max(x, max_value);
	}

	int current_max = max_value;
	int res = max_value - pq.top();
	while (pq.top() < max_value) {
		int v = pq.top();
		pq.pop();
		res = min(res, current_max - v);
		current_max = max(current_max, 2 * v);
		pq.push(2 * v);
	}

	cout << min(res, current_max - pq.top()) << endl;
	return 0;
}
