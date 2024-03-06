// Given a sequence of n integers a
// 0
// ,. . .,a
// n-1
// . We denote rmq(i,j) the minimum element of the sequence a
// i
// , a
// i+1
// , . . .,a
// j
// . Given m pairs (i
// 1
// , j
// 1
// ),. . .,(i
// m
// , j
// m
// ), compute the sum Q = rmq(i
// 1
// ,j
// 1
// ) + . . . + rmq(i
// m
// , j
// m
// )
// Input
// Line 1: n (1 <=  n <= 10
// 6
// )
// Line 2: a
// 0
// , . . . ,a
// n-1
//  ( 1  <=  ai <= 10
// 6
// )
// line 3: m (1  <= m <= 10
// 6
// )
// Line k+3 (k=1, . . ., m): i
// k
// , j
// k 
//  (0  <=  i
// k
//  < j
// k
//  < n)
// Output
// Write the value Q

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to compute the minimum of a subarray using segment tree
void buildSegmentTree(vector<int>& arr, vector<int>& segmentTree, int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildSegmentTree(arr, segmentTree, low, mid, 2 * pos + 1);
    buildSegmentTree(arr, segmentTree, mid + 1, high, 2 * pos + 2);
    segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

int querySegmentTree(vector<int>& segmentTree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }

    if (qlow > high || qhigh < low) {
        return numeric_limits<int>::max();
    }

    int mid = (low + high) / 2;
    int leftMin = querySegmentTree(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1);
    int rightMin = querySegmentTree(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);

    return min(leftMin, rightMin);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the segment tree
    vector<int> segmentTree(4 * n);
    buildSegmentTree(arr, segmentTree, 0, n - 1, 0);

    int m;
    cin >> m;

    long long Q = 0;
    for (int i = 0; i < m; i++) {
        int ik, jk;
        cin >> ik >> jk;

        int minVal = querySegmentTree(segmentTree, ik, jk, 0, n - 1, 0);
        Q += minVal;
    }

    cout << Q << endl;

    return 0;
}
