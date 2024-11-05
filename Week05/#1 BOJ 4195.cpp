#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstring>
using namespace std;

typedef long long int ll;

unordered_map<string, string> parent;
unordered_map<string, int> num;

string find(string s) {
	if (parent[s] == s) return s;
	return parent[s] = find(parent[s]);
}

void Union(string a, string b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	parent[b] = a;
	num[a] += num[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		parent.clear();
		num.clear();

		for (int i = 0; i < n; i += 1) {
			string a, b;
			cin >> a >> b;

			if (!parent.count(a)) {
				parent.insert(make_pair(a, a));
				num.insert(make_pair(a, 1));
			}
			if (!parent.count(b)) {
				parent.insert(make_pair(b, b));
				num.insert(make_pair(b, 1));
			}

			Union(a, b);
			cout << num[find(a)] << "\n";
		}
	}
}
