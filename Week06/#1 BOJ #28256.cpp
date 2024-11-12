#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> dy = { 0, -1, 0, 1 };
vector<int> dx = { 1, 0, -1, 0 };

vector<vector<int>> map;
vector<vector<bool>> visited;

vector<int> res;

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	int res = 1;

	while (q.size()) {
		int ry = q.front().first;
		int rx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i += 1) {
			int ny = ry + dy[i];
			int nx = rx + dx[i];
			if (0 <= ny && ny < 3 && 0 <= nx && nx < 3 && !visited[ny][nx]) {
				if (map[ny][nx] == 1) {
					res += 1;
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		map = vector<vector<int>>(3, vector<int>(3, 0));
		for (int i = 0; i < 3; i += 1) {
			string s;
			cin >> s;

			for (int j = 0; j < 3; j += 1) {
				if (s[j] == 'O') map[i][j] = 1;
				else if (s[j] == 'X') map[i][j] = 0;
				else map[i][j] = 2;
			}
		}

		int n;
		cin >> n;

		vector<int> val(n, 0);
		for (int i = 0; i < n; i += 1) cin >> val[i];

		visited = vector<vector<bool>>(3, vector<bool>(3, 0));
		res = vector<int>();

		for (int i = 0; i < 3; i += 1) {
			for (int j = 0; j < 3; j += 1) {
				if (map[i][j] == 1 && !visited[i][j]) res.push_back(bfs(i, j));
			}
		}

		sort(res.begin(), res.end());
		if (res == val) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
