void inOrder(TreeNode root, vector int &result){
    if(!root)
        return ;
    inOrder(root-left, result);
    result.push_back(root-val);
    inOrder(root-right, result);
}

class Solution {
public
    vectorint getAllElements(TreeNode root1, TreeNode root2) {
        vector int Tree1 {}, Tree2 {};
        inOrder(root1, Tree1);
        inOrder(root2, Tree2);
        
        vector int result (Tree1.size()+Tree2.size());
        
        merge(Tree1.begin(), Tree1.end(), Tree2.begin(), Tree2.end(), result.begin());
        return result;
    }
};