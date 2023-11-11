class Solution {
public:
    int t[1001][1001];
    int LCS(string A,string B,int m,int n){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(A[i-1]==B[j-1]) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
    }
    int longestPalindromeSubseq(string A) {
        int m=A.length();
        string B=A;
        reverse(B.begin(),B.end());
        return LCS(A,B,m,m);
    }
};
