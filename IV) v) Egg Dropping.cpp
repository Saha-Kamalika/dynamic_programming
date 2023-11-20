class Solution {
public:
    int t[101][10001];
    int solve(int e,int f){
        if(f==1 || f==0) return f;
        if(e==1) return f;
        if(t[e][f]!=-1) return t[e][f];
        int low=1,high=f;
        int mn=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int left=solve(e-1,mid-1);
            int right=solve(e,f-mid);
            int temp=1+max(left,right);
            if(left<right) low=mid+1;
            else high=mid-1;
            mn=min(mn,temp);
        }
        return t[e][f]=mn;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }
};
