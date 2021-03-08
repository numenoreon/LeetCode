class Solution {
public:
	int minRotation(int number, vector<int>& A, vector<int>& B) {
		int counter = 0;

		for (int i = 0; i < A.size(); ++i) {
			if (A[i] == number)
				continue;
			else if (B[i] == number)
				++counter;
			else
				return INT_MAX;
		}
		return counter;
	}

	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int one = minRotation(A[0], A, B), two = minRotation(B[0], A, B), 
		    three = minRotation(B[0], B, A), four = minRotation(A[0], B, A);

		int result = min({ one, two, three, four });
		return result == INT_MAX ? -1 : result;
	}
};