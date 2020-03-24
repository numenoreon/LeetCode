OVERFLOW SOLUTION

class Solution {
public:
    void get_width(map <long long int,vector< long long int> > &mapsMe, TreeNode *root, long long int depth, long long int position){
            mapsMe[depth].push_back(position);
            if(root->left)
                get_width(mapsMe,root->left,depth+1,2*position);
            if(root->right)
                get_width(mapsMe,root->right,depth+1,2*position+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        map <long long int,vector<long long int>> mapping;
        get_width(mapping,root,0,0);  
        
        long long int minVal=0, maxVal=0, maxDiff=-1;
                
        for(auto &i : mapping){
            minVal=i.second[0];
            maxVal=i.second.back();
            maxDiff=max(maxDiff,maxVal-minVal);
        }
        
        return maxDiff+1;
    }
};
