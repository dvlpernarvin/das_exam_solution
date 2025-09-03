// PROBLEM-2: Top K Frequent Elements using.

#include <iostream>
using namespace std;

void topKFrequent(int nums[], int n, int k) {
    int freq[20001] = {0}; 
    
    for (int i = 0; i < n; i++)
        freq[nums[i] + 10000]++;

    int count = 0;

    for (int f = n; f >= 1 && count < k; f--) {
        for (int i = 0; i < 20001 && count < k; i++) {
            if (freq[i] == f) {
                cout << (i - 10000) << " "; 
                count++;
            }
        }
    }
    cout << endl;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int n = 6;
    int k = 2;
    topKFrequent(nums, n, k); 
    return 0;
}