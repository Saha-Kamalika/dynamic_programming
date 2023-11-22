class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int solve(Node* root,int& res){
        if(root==nullptr) return 0;
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        int temp=max(max(l,r)+root->data,root->data);
        int ans=max(temp,root->data+l+r);
        res=max(ans,res);
        return temp;
    }
    int findMaxSum(Node* root)
    {
        int res=INT_MIN;
        if(root==nullptr) return 0;
        solve(root,res);
        return res;
    }
};
