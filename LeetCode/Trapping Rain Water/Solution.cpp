class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size()), rightMax(height.size());
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            leftMax[i] = height[i];
            if(i) leftMax[i] = max(leftMax[i], leftMax[i - 1]);
        }
        for(int i = height.size() - 1; i >= 0; i--){
            rightMax[i] = height[i];
            if(i < height.size() - 1) rightMax[i] = max(rightMax[i], rightMax[i + 1]);
        }
        for(int i = 0; i < height.size(); i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};