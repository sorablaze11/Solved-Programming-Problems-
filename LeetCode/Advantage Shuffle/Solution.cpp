class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> search(A.begin(), A.end());
        vector<int> ans(A.size());
        vector<pair<int, int> > B_with_idx;
        for(int i = 0; i < B.size(); i++){
            B_with_idx.push_back({B[i], i});
        }
        sort(B_with_idx.begin(), B_with_idx.end());
        for(int i = 0; i < B_with_idx.size(); i++){
            set<int>::iterator it = search.lower_bound(B_with_idx[i].first + 1);
            int val;
            if(it == search.end()){
                val = *search.begin();
                search.erase(search.begin());
            }else{
                val = *it;
                search.erase(it);
            }
            ans[B_with_idx[i].second] = val;
        }
        return ans;
    }
};