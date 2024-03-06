// Description
// Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

// Input
// Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
// Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

// Output
// Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, distance;
};

bool isValid(int x, int y, int n, int m, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);
}

int shortestPath(vector<vector<int>>& maze, int n, int m, int startX, int startY) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Lên, xuống, trái, phải

    queue<Cell> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Cell cell = q.front();
        q.pop();
        int x = cell.x;
        int y = cell.y;
        int distance = cell.distance;

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            return distance + 1;
        }

        for (const pair<int, int>& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, n, m, maze, visited)) {
                q.push({newX, newY, distance + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    int result = shortestPath(maze, n, m, r - 1, c - 1);
    cout << result << endl;

    return 0;
}
