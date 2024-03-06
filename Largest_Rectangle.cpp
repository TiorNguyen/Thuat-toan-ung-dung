// Description
// Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
// Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
// Dữ liệu
// · Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
// · Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
// Kết quả
// · Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Hàm tính diện tích của hình chữ nhật lớn nhất trong mảng histogram
int maxRectangleArea(vector<int>& histogram) {
    int maxArea = 0;
    stack<int> s;
    int i = 0;

    while (i < histogram.size()) {
        if (s.empty() || histogram[i] >= histogram[s.top()]) {
            s.push(i);
            i++;
        } else {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, histogram[top] * width);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, histogram[top] * width);
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    // Đọc ma trận từ input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Tạo histogram từ hàng đầu tiên
    vector<int> histogram(m);
    for (int j = 0; j < m; j++) {
        histogram[j] = matrix[0][j];
    }

    int maxArea = maxRectangleArea(histogram);

    // Tính histogram và tìm diện tích lớn nhất cho mỗi hàng sau đó cộng dồn vào maxArea
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                histogram[j] = 0;
            } else {
                histogram[j] += matrix[i][j];
            }
        }
        maxArea = max(maxArea, maxRectangleArea(histogram));
    }

    cout << maxArea << endl;

    return 0;
}
