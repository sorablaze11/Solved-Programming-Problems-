class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return 0;
        int r = matrix.size(), c = matrix[0].size();
        int lo = 0, hi = r * c - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(hi - lo <= 1){
                if(matrix[lo / c][lo % c] == target) return true;
                if(matrix[hi / c][hi % c] == target) return true;
                return false;
            }
            if(matrix[mid / c][mid % c] == target) return true;
            if(matrix[mid / c][mid % c] < target) lo = mid + 1;
            else hi = mid - 1;
        }        
        return false;
    }
};