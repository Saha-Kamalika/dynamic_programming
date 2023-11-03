import java.util.*;
class MinDiff{
    public static int subsetSum(int[] arr,int range){
        boolean[][] t=new boolean[arr.length+1][range+1];
        for(int i=0;i<arr.length+1;i++)
            for(int j=0;j<range+1;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        for(int i=1;i<arr.length+1;i++)
            for(int j=1;j<range+1;j++){
                if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        int ans=getMin(t,range,arr);
        return ans;
    }
    private static int getMin(boolean[][] t,int range,int[] arr){
        int n=arr.length-1,j=0;
        List<Integer> v=new ArrayList<>();
        for(int i=0;i<=range/2;i++){
        if(t[n][i]==true){
            v.add(i);
            }
        }
        int mn=Integer.MAX_VALUE;
        for(int i=0;i<v.size();i++){
          mn=Math.min(mn,range-2*v.get(i));
        }
        return mn;
    }
    public static void main(String[] args){
        int arr[]={1,2,7};
        int range=0;
        for(int i=0;i<arr.length;i++) range+=arr[i];
        int ans=subsetSum(arr,range);
        System.out.println(ans);
    }
}
