class Solution {
public:
    int countElements(vector<int>& arr) {
        set <int> numbers;
        
        for(int i=0; i<arr.size(); ++i){
            numbers.insert(arr[i]);
        }
        
        int cnt=0;
        
        for(int i=0; i<arr.size(); ++i){
            if(numbers.count(arr[i]+1))
               ++cnt;
        }
               
        return cnt;
    }
};