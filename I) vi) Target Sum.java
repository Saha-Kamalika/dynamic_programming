class Solution {
    private int countSubset(int[] nums,int sum){
        int[][] t=new int[nums.length+1][sum+1];
        for(int i=0;i<nums.length+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<nums.length+1;i++){
            for(int j=0;j<sum+1;j++){
                if(nums[i-1]<=j) t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                else if(nums[i-1]>j) t[i][j]=t[i-1][j];
            }
        }
        return t[nums.length][sum];
    }
    public int findTargetSumWays(int[] nums, int target) {
        int range=0;
        for(int i=0;i<nums.length;i++) range+=nums[i];
        if(range<target) return 0;
        if(target+range<0 ||(range+target)%2!=0) return 0;
        return countSubset(nums,(range+target)/2);
    }
}
