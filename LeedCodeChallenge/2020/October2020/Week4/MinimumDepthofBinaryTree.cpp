class Solution {
public
    
    void findDepth(TreeNode root, int depth, int &minD){
        if(!root-left && !root-right){
            minD=min(minD, depth);
            return;
        }
        if(root-left)
            findDepth(root-left, depth+1, minD);
        if(root-right)
            findDepth(root-right, depth+1, minD);
    }
    
    int minDepth(TreeNode root) {
        if(!root)    
            return 0;
        int minD = INT_MAX;
        findDepth(root, 1, minD);
        return minD;
    }

};