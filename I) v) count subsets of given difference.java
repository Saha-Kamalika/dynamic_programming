import java.util.*;
class countDiff{
    private static int countSubsetSum(int[] arr,int sum){
        int[][] t=new int[arr.length+1][sum+1];
        for(int i=0;i<arr.length+1;i++)
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        for(int i=1;i<arr.length+1;i++)
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j) t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
                else t[i][j]=t[i-1][j];
            }
        return t[arr.length][sum];
    }
    public static void main(String[] args){
        int[] arr={1,1,2,3};
        int diff=1;
        int range=0;
        for(int i=0;i<arr.length;i++)   
            range+=arr[i];
        int ans=countSubsetSum(arr,(diff+range)/2);
        System.out.println(ans);
    }
}
