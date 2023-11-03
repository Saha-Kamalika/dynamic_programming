class Solution {
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        else return subsetSum(nums,sum/2);
    }
    public boolean subsetSum(int[] arr,int sum){
        int n=arr.length;
        boolean[][] t=new boolean[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        return t[n][sum];
    }
}
