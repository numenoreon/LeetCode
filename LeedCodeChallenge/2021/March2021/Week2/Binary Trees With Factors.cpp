class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        unordered_map <int, long> mapsMe;
        int result = 0;
        for (auto num : arr) {
            long possible = 1;
            int index = 0, lim = (int) sqrt(num);
            while (arr[index] <= lim) {
                if (num % arr[index] == 0 && mapsMe.find(num / arr[index]) != mapsMe.end()){
                    possible += ((arr[index] == num / arr[index]) ? 1 : 2) * mapsMe[arr[index]] * mapsMe[num / arr[index]];
                    possible % 1000000007;
                }
                index++;
            }
            result = (result + possible) % 1000000007;
            mapsMe[num] = possible;
        }
        
        return result % 1000000007;
    }
};