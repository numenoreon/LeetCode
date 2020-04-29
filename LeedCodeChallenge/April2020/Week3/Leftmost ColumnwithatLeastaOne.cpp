class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &matrix) {
        auto xyPair = matrix.dimensions();
        int i = 0, j = xyPair[1]-1, result = -1;
        
        while(i < xyPair[0] && j >= 0) {
            if(matrix.get(i,j))
                result=j--;
            else
                i++;   
        }
        return result;
    }
};