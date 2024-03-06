// Description
// Given a set of segments X = {(a
// 1
// , b
// 1
// ), . . . , (a
// n
// , b
// n
// )} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line i+1 (i= 1,...,n): contains ai and bi (0 <= a
// i
//  <= b
// i 
// <= 1000000)
// Output
// Number of segments in the solution found.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start;
    int end;

    Segment(int a, int b) : start(a), end(b) {}
};

bool compareSegments(const Segment& seg1, const Segment& seg2) {
    return seg1.end < seg2.end;
}

int findLargestNonIntersectingSubset(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), compareSegments);

    int count = 1; // Initialize count with 1, as the first segment is always included
    int current_end = segments[0].end;

    for (int i = 1; i < segments.size(); i++) {
        if (segments[i].start > current_end) {
            count++;
            current_end = segments[i].end;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        segments.push_back(Segment(a, b));
    }

    int result = findLargestNonIntersectingSubset(segments);
    cout << result << endl;

    return 0;
}
