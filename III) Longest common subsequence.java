class Solution {
    static int[][] t=new int[1001][1001];
    public int longestCommonSubsequence(String text1, String text2) {
        for(int[] r: t) Arrays.fill(r,-1);
        return lcs(text1,text2,text1.length(),text2.length());
    }
    public int lcs(String x,String y,int m,int n){
        if(n==0 || m==0) return 0;
        if(t[m][n]!=-1) return t[m][n];
        if(x.charAt(m-1)==y.charAt(n-1)) return t[m][n]=1+lcs(x,y,m-1,n-1);
        else t[m][n]=Math.max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
        return t[m][n];
    }
}
