class Solution {
public:
    int t[1001][1001];
    int LCS(string a,string b){
        int m=a.length();
        for(int i=0;i<m+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
                if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        return t[m][m];
    }
    int minInsertions(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int len_LPS=LCS(s,rev);
        return (s.length()-len_LPS);
    }
};
