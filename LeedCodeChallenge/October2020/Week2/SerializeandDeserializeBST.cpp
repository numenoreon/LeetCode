class Codec {
public:
    void preOrder(TreeNode *root, string &temp){
        if(!root){
            temp+="n,";
            return ;
        }
        temp+=to_string(root->val);
        temp+=',';
        preOrder(root->left, temp);
        preOrder(root->right, temp);
    }
    
    TreeNode* reOrder(stringstream &ss){
        string temp;
        getline(ss, temp, ',');
        if(temp=="n"){
            return nullptr;
        }
        TreeNode *root = new TreeNode (stoi(temp));
        
        root->left = reOrder(ss);
        root->right = reOrder(ss);
        return root;
    }
    
    string serialize(TreeNode* root) {
        string temp="";
        
        preOrder(root, temp);
        cout << temp << endl;
        return temp;
    }

    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        int position=0;
        stringstream ss(data);
        TreeNode *root = reOrder(ss);
        return root;
    }
};
