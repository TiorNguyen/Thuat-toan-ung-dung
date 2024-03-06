// Description
// Given a positive integer n and n positive integers a
// 1
// , a
// 2
// , ..., a
// n
// . Compute the number of positive integer solutions to the equation:
//                           a
// 1
// X
// 1
//  + a
// 2
// X
// 2
//  + . . . + a
// n
// X
// n
//  = M

// Input
// Dòng 1: n và M
// Dòng 2: a
// 1
// , a
// 2
// , ..., a
// n
// Output
//    Số nghiệm nguyên dương
// Ví dụ
// Input
// 3 5
// 1 1 1
// Output
// 6

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n, M;

int countSolutions(int idx, int sum) {
    if (idx == n) {
        return sum == M;
    }

    int count = 0;
    for (int x = 1; x <= (M - sum) / a[idx]; ++x) {
        count += countSolutions(idx + 1, sum + a[idx] * x);
    }

    return count;
}

int main() {
    cin >> n >> M;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << countSolutions(0, 0) << endl;

    return 0;
}
