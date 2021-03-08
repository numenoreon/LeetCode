class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int start = 0, length = citations.size(), end = citations.size() - 1;
        while (start <= end) {
            int mid = (start + end)/2;
            if (citations[mid] < length - mid)
                start = mid + 1;
            else if (citations[mid] > length - mid)
                end = mid - 1;
            else return length - mid;
        }
        return length - start;
    }
};