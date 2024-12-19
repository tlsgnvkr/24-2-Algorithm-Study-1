#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10001;
vector<int> adj[MAX];
bool visited[MAX];
int hack_count[MAX];

int bfs(int start) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[B].push_back(A);
    }

    int max_hacks = 0;
    vector<int> result;

    for (int i = 1; i <= N; ++i) {
        hack_count[i] = bfs(i);
        if (hack_count[i] > max_hacks) {
            max_hacks = hack_count[i];
            result.clear();
            result.push_back(i);
        } else if (hack_count[i] == max_hacks) {
            result.push_back(i);
        }
    }

    for (int computer : result) {
        cout << computer << " ";
    }
    cout << '\n';

    return 0;
}
