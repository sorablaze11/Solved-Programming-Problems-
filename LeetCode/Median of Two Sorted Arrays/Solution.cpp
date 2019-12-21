class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(B.size() == 0){
            double ans = 0;
            if(A.size() % 2){
                return A[A.size() / 2];
            }else{
                ans += A[A.size() / 2] + A[A.size() / 2 - 1];
                return ans / 2;
            }
        }
        if(A.size() == 0){
            double ans = 0;
            if(B.size() % 2){
                return B[B.size() / 2];
            }else{
                ans += B[B.size() / 2] + B[B.size() / 2 - 1];
                return ans / 2;
            }
        }
        int n = A.size(), m = B.size();
        int lo, hi, mid, i, j;
        double ans;
        if(m < n) return findMedianSortedArrays(B, A);
        lo = 0, hi = n;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            i = mid;
            j = (n + m + 1) / 2 - i;
            if(i < n && B[j - 1] > A[i]) lo = mid + 1;
            else if(i > 0 && A[i - 1] > B[j]) hi = mid - 1;
            else{
                double max_of_left, min_of_right;
                if(i == 0) max_of_left = B[j - 1];
                else if(j == 0) max_of_left = A[i - 1];
                else max_of_left = max(A[i-1], B[j-1]);
                if((m + n) % 2 == 1) return max_of_left;

                if (i == n) min_of_right = B[j];
                else if (j == m) min_of_right = A[i];
                else min_of_right = min(A[i], B[j]);
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        return ans;
    }
};