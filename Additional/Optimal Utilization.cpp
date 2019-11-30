// https://leetcode.com/discuss/interview-question/373202
#include <bits/stdc++.h>
using namespace std;

int lenA, lenB, key, value, target, minDiff = INT_MAX;
vector<pair<int, int>> arrA, arrB, ans, tempAns;
map<int, vector<int> > valueToIdxA, valueToIdxB;
vector<int> A, B;

int bs(int idx){
    int a = A[idx];
    int b = target - a;
    int lo = 0, hi = B.size() - 1, mid;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(hi - lo <= 1){
            if(lo == hi) return lo;
            int diff = b - B[lo];
            if(b >= B[hi] && diff > (b - B[hi])){
                return hi;
            }
            return lo;
        }else if(B[mid] <= b) lo = mid;
        else hi = mid - 1;
    }
    return hi;
}

int main(){
    cin >> lenA;
    for(int i = 0; i < lenA; i++){
        cin >> key >> value;
        arrA.push_back({key, value});
        valueToIdxA[value].push_back(key);
    }
    cin >> lenB;
    for(int i = 0; i < lenB; i++){
        cin >> key >> value;
        arrB.push_back({key, value});
        valueToIdxB[value].push_back(key);
    }
    cin >> target;
    for(auto x : valueToIdxA) A.push_back(x.first);
    for(auto x : valueToIdxB) B.push_back(x.first);
    for(int i = 0; i < A.size(); i++){
        if(B[0] + A[i] > target) break;
        int idx = bs(i);
        // cout << idx << ' ';
        if(minDiff < (target - B[idx] - A[i])) continue;
        if(minDiff == (target - B[idx] - A[i])){
            // cout << "S";
            tempAns.push_back({A[i], B[idx]});
            continue;
        }
        minDiff = (target - B[idx] - A[i]);
        tempAns.clear();
        tempAns.push_back({A[i], B[idx]});
    }
    for(auto x : tempAns){
        for(auto y : valueToIdxA[x.first]){
            for(auto z : valueToIdxB[x.second]) ans.push_back({y, z});
        }
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}