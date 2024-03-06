// Description
// The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest. A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse must work and the length of the working period is the number of consecutive days of that working period. The hospital imposes two constraints:
// Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
// The length of each working period must be greater or equal to K
// 1
//  and less than or equal to K
// 2
//  (2) 
// The director of the hospital want to know how many possible working plans satisfying above constraint?	
// Input
//  The input consists of one line which contains 3 positive integers N, K
// 1
// , K
// 2
//  (2 <= N <=  1000, K
// 1 
// < K
// 2
//  <= 400)
// Output
// The output consists of only one single integer M modulo 10
// 9
// +7 where M is the total working plans satisfying the above constraints.

#include <iostream>
#define MAX 1000
using namespace std;

int N;          // số ngày 
int K1,K2;      // K1 <= khoảng thời gian làm việc liên tục <= K2
int A[MAX]={0}; // i là ngày nghỉ 
int B[MAX]={0}; // i là ngày làm 

int solve()
{
    A[0]=1; // TH i=K1  : B[i]  = A[i-K1]+...+A[i-K2] => B[K1]=A[0]   => Thiết lập A[0]=1
    B[0]=1; // TH i=1   : A[i]  = B[i-1]              => A[1]=B[0]    => Thiết lập B[0]=1
    for(int i=1;i<=N;i++)
    {
        A[i]=B[i-1];
        for(int j=K1;j<=K2;j++)
        {
            if(i-j>=0)
            B[i]+=A[i-j];
        }
    }
    return B[N]+A[N];
}

void input(){
    cin >> N >> K1 >> K2;
}

int main()
{
    input();
    cout << solve();
    return 0;
}
