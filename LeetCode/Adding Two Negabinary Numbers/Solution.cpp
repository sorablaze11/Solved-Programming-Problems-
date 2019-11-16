class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        // Reversing the arrays for calculation from lsb instead of msb.
        /**
            64 -32 16 -8 4 -2 1
            -------------------
            0   0  0   0 0  1 1
            0   0  0   0 0  0 1
                    ==
            0   0  0   0 0  0 0
            As two 2 * 1 cancel outs -2 * 1;

            64 -32 16 -8 4 -2 1
            -------------------
            0   0  0   0 0  0 1
            0   0  0   0 0  0 1
                    ==
            0   0  0   0 1  1 0
            As two 2 * 1 is equal to 1 * 4 + (-2) * 1
        **/
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        vector<int> ans(max(arr1.size(), arr2.size()) + 2);
        int idx = 0, min_len = min(arr1.size(), arr2.size());
        while(idx < min_len){
            int total = arr1[idx] + arr2[idx] + ans[idx];
            if(total == 1){
                ans[idx] = 1;
            }else if(total == 2 || total == 3){
                ans[idx] = (total == 3);
                int temp = 0;
                if(idx + 1 < arr1.size()) temp += arr1[idx + 1];
                if(idx + 1 < arr2.size()) temp += arr2[idx + 1];
                if(temp == 1){
                    if(idx + 1 < arr1.size()) arr1[idx + 1] = 0;
                    if(idx + 1 < arr2.size()) arr2[idx + 1] = 0;
                }else if(temp == 2){
                    arr1[idx + 1] = 0;
                }else{
                    ans[idx + 1]++;
                    ans[idx + 2]++;
                }
            }
            idx++;
        }
        while(idx < arr1.size()){
            int total = arr1[idx] + ans[idx];
            if(total == 1){
                ans[idx] = 1;
            }else if(total == 2){
                ans[idx] = 0;
                int temp = 0;
                if(idx + 1 < arr1.size()) temp += arr1[idx + 1];
                if(temp == 1){
                    arr1[idx + 1] = 0;
                }else{
                    ans[idx + 1]++;
                    ans[idx + 2]++;
                }
            }
            idx++;
        }
        while(idx < arr2.size()){
            int total = arr2[idx] + ans[idx];
            if(total == 1){
                ans[idx] = 1;
            }else if(total == 2){
                ans[idx] = 0;
                int temp = 0;
                if(idx + 1 < arr2.size()) temp += arr2[idx + 1];
                if(temp == 1){
                    arr2[idx + 1] = 0;
                }else{
                    ans[idx + 1]++;
                    ans[idx + 2]++;
                }
            }
            idx++;
        }
        while(ans.size() > 0 && ans[ans.size() - 1] == 0) ans.pop_back();
        if(ans.size() == 0) ans.push_back(0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};