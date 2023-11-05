class Solution {
    public int change(int amount, int[] coins) {
        int[][] t=new int[coins.length+1][amount+1];
        for(int i=0;i<coins.length+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<coins.length+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j) t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[coins.length][amount];
    }
}
