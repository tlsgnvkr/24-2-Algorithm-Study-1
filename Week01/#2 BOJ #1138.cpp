// https://www.acmicpc.net/problem/1138

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> val(n);
	for (int i = 0; i < n; i += 1) cin >> val[i];

	vector<int> res(n, -1);
	for (int i = 0; i < n; i += 1) {
		int cnt = val[i];
		int iter = 0;
		while (cnt || res[iter] != -1) {
			if (res[iter] == -1) cnt -= 1;
			iter += 1;
		}
		res[iter] = i;
	}

	for (auto x : res) cout << x + 1 << ' ';
	cout << endl;
}
