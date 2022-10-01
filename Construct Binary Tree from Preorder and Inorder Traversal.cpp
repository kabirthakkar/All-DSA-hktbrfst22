class Solution {
public:
int search(vector&in,int ele,int n)
{
for(int i=0;i<n;i++)
{
if(in[i]==ele)
return i;
}

        return -1;
}
TreeNode* solve(vector<int>& in, vector<int>& pre,int &ind,int is,int ie,int n)
{
    if(ind>n || is>ie)
        return NULL;
    int element=pre[ind];
    ind++;
    TreeNode* root=new TreeNode(element);
    
    int pos=search(in,element,n);
    
    root->left=solve(in,pre,ind,is,pos-1,n);
    root->right=solve(in,pre,ind,pos+1,ie,n);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
    int ind=0;
    TreeNode* ans=solve(inorder,preorder,ind,0,n-1,n);
    return ans;
    
}
};
