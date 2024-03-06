// Description
// Given N elements (2≤ N ≤100,000) on a straight line at positions x
// 1
// ,…, x
// N
//  (0≤ x
// i 
// ≤1,000,000,000).
// The distance of a subset of N elements is defined to be the minimum distance between two elements.
// Find the subset of N given elements containing exactly C elements such that the distance is maximal.
// Input
// The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
// Subsequent lines are T test cases with the following format:
// Line 1: Two space-separated integers: N and C
// Lines 2: contains  x1, x
// 2
// , . . . , x
// N

// Output
// For each test case output one integer: the distance of the subset found.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& positions, int C, int distance) {
    int count = 1;
    int last_position = positions[0];
    
    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - last_position >= distance) {
            count++;
            last_position = positions[i];
        }
    }
    
    return count >= C;
}

int findMaxDistance(vector<int>& positions, int C) {
    sort(positions.begin(), positions.end());
    int low = 1;
    int high = positions[positions.size() - 1] - positions[0];
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(positions, C, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, C;
        cin >> N >> C;
        vector<int> positions(N);

        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }

        int maxDistance = findMaxDistance(positions, C);
        cout << maxDistance << endl;
    }

    return 0;
}
