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

vector<int> gate;

int find(int v) {
	if (gate[v] == v) return v;
	return gate[v] = find(gate[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	gate[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p;
	cin >> g >> p;

	gate = vector<int>(g + 1, 0);
	for (int i = 1; i <= g; i += 1) gate[i] = i;

	int res = 0;
	for (int i = 0; i < p; i += 1) {
		int gi;
		cin >> gi;

		int docking_point = find(gi);
		if (docking_point) {
			Union(docking_point, docking_point - 1);
			res += 1;
		}
		else break;
	}

	cout << res << endl;
	return 0;
}
