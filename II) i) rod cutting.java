class Solution{
    public int cutRod(int price[], int n) {
        int[] length=new int[n];
        for(int i=1;i<=n;i++) length[i-1]=i;
        int[][] t=new int[price.length+1][n+1];
        for(int i=0;i<price.length+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<price.length+1;i++){
            for(int j=1;j<n+1;j++){
                if(length[i-1]<=j) t[i][j]=Math.max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
                else t[i][j]=t[i-1][j];
            }
        }
        return t[price.length][n];
    }
}
