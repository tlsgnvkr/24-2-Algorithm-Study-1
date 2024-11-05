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

#define MOD 1000000007
#define MAX 10000000

typedef long long ll;

vector<bool> erastothenes(int bound) {
	vector<bool> nums(bound + 1, true);
	nums[0] = nums[1] = false;
	for (int i = 2; i <= bound; i++) {
		if (nums[i]) {
			for (int j = i + i; j <= bound; j += i) {
				nums[j] = false;
			}
		}
	}
	return nums;
}

ll power(ll n, int k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll p = power(n, k / 2);
	p = (p * p) % MOD;
	if (k % 2) p = (p * n) % MOD;
	return p;
}

int main() {
	vector<bool> nums = erastothenes(MAX / 2);
	int n;
	while (cin >> n && n) {
		ll result = 1;
		for (int i = 2; i <= n / 2; i++) {
			if (!nums[i]) continue;

			int cnt = 0;
			ll j = i;
			while (j <= n) {
				cnt += n / j;
				j *= i;
			}
			if (cnt % 2) {
				cnt -= 1;
			}
			result = (result * power(i, cnt)) % MOD;
		}

		cout << result << endl;
	}
	return 0;
}
