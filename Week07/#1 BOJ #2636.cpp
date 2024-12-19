#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isInBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int meltCheese() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int cheeseCount = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInBounds(nx, ny) && !visited[nx][ny]) {
                if (board[nx][ny] == 0) {
                    q.push({nx, ny});
                } else if (board[nx][ny] == 1) {
                    board[nx][ny] = 0;
                    cheeseCount++;
                }
                visited[nx][ny] = true;
            }
        }
    }
    return cheeseCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    int lastCheeseCount = 0;

    while (true) {
        int currentCheeseCount = meltCheese();
        if (currentCheeseCount == 0) {
            break;
        }
        lastCheeseCount = currentCheeseCount;
        time++;
    }

    cout << time << '\n' << lastCheeseCount << '\n';
    return 0;
}
