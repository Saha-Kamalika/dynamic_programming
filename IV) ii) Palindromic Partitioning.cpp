class Solution {
public:
    int t[2001][2001];
    bool isPalin(string& s,int i,int j){
        if(i>=j) return true;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string& s,int i,int j){
        if((i>=j) || (isPalin(s,i,j))) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int left,right;
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            if(t[i][k]!=-1) left=t[i][k];
            else{
                left=solve(s,i,k);
                t[i][k]=left;
            }
            if(t[k+1][j]!=-1) right=t[k+1][j];
            else{
                right=solve(s,k+1,j);
                t[k+1][j]=right;
            }
            int temp=1+left+right;
            ans=min(ans,temp);
        }
        return t[i][j]=ans;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.length()-1);
    }
};
