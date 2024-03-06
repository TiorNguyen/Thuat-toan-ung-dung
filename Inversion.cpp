// Description
// Given a sequence of integers a
// 1
// , a
// 2
// , ..., a
// n
// . A pair (i, j) is call an inversion if i < j and a
// i
//  > a
// j
// . Compute the number Q of inversions
// Input
// Line 1: contains a positive integer n (1 <= n <= 10
// 6
// )
// Line 2: contains a
// 1
// , a
// 2
// , ..., a
// n
//  (0 <= a
// i
// <= 10
// 6
// )
// Output
// Write the value Q modulo 10
// 9
// +7

#include <vector>
#include <iostream>

const int MAX_ELEMENT_VALUE = 1e6; // Upper bound for element values
const int MODULUS = 1e9 + 7; // Modulus for large numbers

// Helper function to compute the least significant bit (LSB)
inline int computeLSB(int x) {
    return x & (-x);
}

// Customized Fenwick Tree for tracking counts
class AccumulativeCounter {
private:
    std::vector<int> dataCounter;

public:
    AccumulativeCounter(int maxSize) : dataCounter(maxSize + 1, 0) {}

    // Increment the count for an element
    void incrementCount(int position, int increment) {
        while (position < dataCounter.size()) {
            dataCounter[position] = (dataCounter[position] + increment) % MODULUS;
            position += computeLSB(position);
        }
    }

    // Compute the cumulative count up to a certain element
    int getCumulativeCount(int position) {
        int sum = 0;
        while (position > 0) {
            sum = (sum + dataCounter[position]) % MODULUS;
            position -= computeLSB(position);
        }
        return sum;
    }
};

// Function to compute the number of inversions in the array
long long computeInversions(std::vector<int>& sequence) {
    AccumulativeCounter counter(MAX_ELEMENT_VALUE);
    long long totalInversions = 0;

    for (int index = sequence.size() - 1; index >= 0; --index) {
        totalInversions += counter.getCumulativeCount(sequence[index] - 1);
        totalInversions %= MODULUS;
        counter.incrementCount(sequence[index], 1);
    }

    return totalInversions;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numElements;
    std::cin >> numElements;

    std::vector<int> sequence(numElements);
    for (int &value : sequence) {
        std::cin >> value;
    }

    std::cout << computeInversions(sequence) << std::endl;
    return 0;
}
