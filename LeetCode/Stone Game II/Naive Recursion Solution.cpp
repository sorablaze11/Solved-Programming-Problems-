// This solution will give TLE.
class Solution {
public:
    int rec(int idx, int M, vector<int> &piles, int turn){
        if(idx >= piles.size()) return 0;
        
        if(turn){
            int alexStones = INT_MAX;
            for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
                alexStones = min(alexStones, rec(idx + i + 1, max(M, i + 1), piles, !turn));
            }
            return alexStones;
        }else{
            int alexStones = 0, temp = 0;
            for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
                temp += piles[idx + i];
                alexStones = max(alexStones, temp + rec(idx + i + 1, max(M, i + 1), piles, !turn));
            }
            return alexStones;
        }
    }
    
    int stoneGameII(vector<int>& piles) {
        // vector<vector<int> > 
        // int pilesLength = piles.size();
        return rec(0, 1, piles, 0);        
    }
};