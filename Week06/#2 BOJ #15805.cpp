#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n, 0);
	vector<int> parent(n, 0);
	set<int> tree;
	for (int i = 0; i < n; i += 1) cin >> A[i];

	parent[A[0]] = -1;
	tree.insert(A[0]);

	for (int i = 1; i < n; i += 1) {
		if (!tree.count(A[i])) {
			parent[A[i]] = A[i - 1];
			tree.insert(A[i]);
		}
	}

	cout << tree.size() << "\n";
	for (int i = 0; i < tree.size(); i++) cout << parent[i] << " ";
	cout << endl;
	return 0;
}
