class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == true) {
                for (int k = i * i; k <= n; k += i) {
                    prime[k] = false;
                }
            }
        }
        int counter = 0;
        for (auto n : prime) {
            if (n == true) {
                ++counter;
            } 
        }
        return counter;
    }
};