#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int ll;

int n, m;
vector<vector<int>> map;
vector<int> inDeg;
vector<int> res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	map = vector<vector<int>>(n + 1);
	inDeg = vector<int>(n + 1);
	for (int i = 0; i < m; i += 1) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		inDeg[b] += 1;
	}

	res = vector<int>(n + 1);
	queue<int> q;
	for (int i = 1; i <= n; i += 1) {
		if (!inDeg[i]) q.push(i);
		res[i] = 1;
	}

	while (q.size()) {
		int cur = q.front();
		q.pop();

		for (auto next : map[cur]) {
			inDeg[next] -= 1;
			if (!inDeg[next]) {
				q.push(next);
				res[next] = max(res[next], res[cur] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i += 1) cout << res[i] << " ";
	cout << endl;
	return 0;
}
