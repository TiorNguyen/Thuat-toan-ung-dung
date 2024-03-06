// Description
// The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. The warehouse i has amount of a
// i
//  (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.
// Input
// Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
// Line 2 contains n integers a
// 1
// ,a
// 2
// ,…,a
// n
// Output
// Contains only one single integer denoting the total amount of golds of selected warehouses.
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> filterInRange(const int arr[], int size, int min, int max)
{
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= min && arr[i] <= max)
        {

            result.push_back(arr[i]); // Thêm vào vector nếu phần tử nằm trong khoảng
        }
    }
    return result;
}
int sumOfVector(const vector<int> &vec)
{
    int sum = 0;
    for (int element : vec)
    {
        sum += element; // Cộng dồn từng phần tử vào tổng
    }
    return sum;
}
int main()
{
    int n;
    int maxx;
    int count = 0;
    int minn;
    cin >> n >> minn >> maxx;
    int a[10000];
    int a1, a2;
    int sum[10000] = {0};
    bool check = true;
    vector<int> arr;
    for (int i = 10000; i < 10000 + n; i++)
    {
        cin >> a[i];
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        sum[i] = a[i];
        for (int j = i - maxx; j <= i - minn; j++)
        {
            if (sum[j] > count)
                count = sum[j];
        }
        sum[i] += count;
        count = 0;
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        if (sum[i] > count)
            count = sum[i];
    }
    cout << count;
}
