class Solution {
	public:
	int t[1001][1001];
    int LCS(string X,string Y,int m,int n){
        memset(t,-1,sizeof(t));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1] && i!=j) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        return t[m][n];
    }
	int LongestRepeatingSubsequence(string str){
		return LCS(str,str,str.length(),str.length()); 
	}
};
