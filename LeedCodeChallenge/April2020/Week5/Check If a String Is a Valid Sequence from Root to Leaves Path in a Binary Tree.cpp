class Solution {
public:
    void returnLeaf(vector <string> &vec, TreeNode* node, string temp){ // search all paths, convert to string and save
        if(!node){
            vec.push_back(temp);
            return ;
        }
        temp+=to_string(node->val);
        
        if(node->left && node->right){
            returnLeaf(vec, node->left, temp);
            returnLeaf(vec, node->right, temp);
        }
        else if(!node->left)    
            returnLeaf(vec, node->right, temp);
        else if(!node->right)
            returnLeaf(vec, node->left, temp); 
    }
       
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root)
            return false;
        
        vector <string> result;
        returnLeaf(result, root, "");
        string tempString;
        
        for(int i = 0; i<arr.size(); ++i){ //convert candidate to string
            tempString+=to_string(arr[i]); 
        }

        for(auto &i : result){ // check if there is a match, if yes true, if no false
            if(tempString==i)
                return true;
        }
        return false; 
    }   
};