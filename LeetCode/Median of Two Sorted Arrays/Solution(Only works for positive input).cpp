class Solution {
public:
    
    double rec(vector<int>& nums1, int& idx1L, int& idx1R, vector<int>& nums2, int& idx2L, int& idx2R){
        // cout << idx1L << ' ' << idx1R << ' ' << idx2L << ' ' << idx2R << '\n';
        int size1 = idx1R - idx1L + 1;
        int size2 = idx2R - idx2L + 1;
        // Base conditions
        if(size1 == 1 || size2 == 1){
            // cout << "Base condition called\n";
            double ans = 0;
            if(size1 == 1 && size2 == 1){
                // cout << "Both size are 1\n";
                ans = nums1[idx1L] + nums2[idx2L];
                ans /= 2;
            }else if(size1 == 1){
                // cout << "Nums1 hase size 1";
                if(size2 % 2){
                    int mid = nums2[(idx2L + idx2R) / 2];
                    if(mid == nums1[(idx1L + idx1R) / 2]){
                        ans = mid;
                    }else if(mid < nums1[(idx1L + idx1R) / 2]){
                        ans = mid;
                        if(nums2[(idx2L + idx2R) / 2 + 1] < nums1[(idx1L + idx1R) / 2]) ans += nums2[(idx2L + idx2R) / 2 + 1];
                        else ans += nums1[(idx1L + idx1R) / 2];
                        ans /= 2;
                    }else{
                        ans = mid;
                        if(nums2[(idx2L + idx2R) / 2 - 1] > nums1[(idx1L + idx1R) / 2]) ans += nums2[(idx2L + idx2R) / 2 + 1];
                        else ans += nums1[(idx1L + idx1R) / 2];
                        ans /= 2;
                    }
                }else{
                    int f = nums2[(idx2L + idx2R) / 2];
                    int s = nums2[(idx2L + idx2R) / 2 + 1];
                    if(nums1[(idx1L + idx1R) / 2] >= f && nums1[(idx1L + idx1R) / 2] <= s) ans = nums1[(idx1L + idx1R) / 2];
                    else if(nums1[(idx1L + idx1R) / 2] <= f) ans = f;
                    else ans = s;
                }
            }else{
                // cout << "Nums2 hase size 1";
                if(size1 % 2){
                    int mid = nums1[(idx1L + idx1R) / 2];
                    if(mid == nums2[(idx2L + idx2R) / 2]){
                        ans = mid;
                    }else if(mid < nums2[(idx2L + idx2R) / 2]){
                        ans = mid;
                        if(nums1[(idx1L + idx1R) / 2 + 1] < nums2[(idx2L + idx2R) / 2]) ans += nums1[(idx1L + idx1R) / 2 + 1];
                        else ans += nums2[(idx2L + idx2R) / 2];
                        ans /= 2;
                    }else{
                        ans = mid;
                        if(nums1[(idx1L + idx1R) / 2 - 1] > nums2[(idx2L + idx2R) / 2]) ans += nums1[(idx1L + idx1R) / 2 + 1];
                        else ans += nums2[(idx2L + idx2R) / 2];
                        ans /= 2;
                    }
                }else{
                    int f = nums1[(idx1L + idx1R) / 2];
                    int s = nums1[(idx1L + idx1R) / 2 + 1];
                    if(nums2[(idx2L + idx2R) / 2] >= f && nums2[(idx2L + idx2R) / 2] <= s) ans = nums2[(idx2L + idx2R) / 2];
                    else if(nums2[(idx2L + idx2R) / 2] <= f) ans = f;
                    else ans = s;
                }
            }
            return ans;
        }
        double median1, median2;
        int rem1, rem2;
        rem1 = (idx1R - idx1L) / 2;
        rem2 = (idx2R - idx2L) / 2;
        if(size1 % 2){
            median1 = nums1[(idx1L + idx1R) / 2];
        }else{
            median1 = nums1[(idx1L + idx1R) / 2];
            median1 += nums1[(idx1L + idx1R) / 2 + 1];
            median1 /= 2.0;
            rem1++;
        }
        if(size2 % 2){
            median2 = nums2[(idx2L + idx2R) / 2];
        }else{
            median2 = nums2[(idx2L + idx2R) / 2];
            median2 += nums2[(idx2L + idx2R) / 2 + 1];
            median2 /= 2.0;
            rem2++;
        }
        if(median1 <= median2){
            idx1L += min(rem1, rem2);
            idx2R -= min(rem1, rem2);
        }else{
            idx2L += min(rem1, rem2);
            idx1R -= min(rem1, rem2);
        }
        return rec(nums1, idx1L, idx1R, nums2, idx2L, idx2R);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() == 0){
            double ans = 0;
            if(nums1.size() % 2){
                return nums1[nums1.size() / 2];
            }else{
                ans += nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1];
                return ans / 2;
            }
        }
        if(nums1.size() == 0){
            double ans = 0;
            if(nums2.size() % 2){
                return nums2[nums2.size() / 2];
            }else{
                ans += nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1];
                return ans / 2;
            }
        }
        int l1, r1, l2, r2;
        l1 = l2 = 0;
        r1 = nums1.size() - 1, r2 = nums2.size() - 1;
        return rec(nums1, l1, r1, nums2, l2, r2);
    }
};