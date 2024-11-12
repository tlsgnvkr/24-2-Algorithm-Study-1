#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

int n, m, k;
int parent[1000001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int isLink(int a, int b) {
	if (find(a) == find(b)) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i += 1) {
		cout << "Scenario " << i << ":\n";

		cin >> n >> m;
		for (int j = 0; j < n; j += 1) parent[j] = j;
		for (int j = 0; j < m; j += 1) {
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}

		cin >> k;
		for (int j = 0; j < k; j += 1) {
			int node_1, node_2;
			cin >> node_1 >> node_2;
			cout << isLink(node_1, node_2) << "\n";
		}
		cout << "\n";
	}
	return 0;
}
