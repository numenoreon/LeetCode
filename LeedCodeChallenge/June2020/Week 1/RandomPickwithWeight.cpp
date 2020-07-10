class Solution {
    vector <int> weights;
    int sum = 0;
public:
    Solution(vector<int> w) {
        for (auto &i : w) {
            sum += i;
            weights.push_back(sum);
        }
    }
    
    int pickIndex() {
        int temp = rand() % sum;
        auto it = upper_bound(weights.begin(), weights.end(), temp);
        return it - weights.begin();
    }
};