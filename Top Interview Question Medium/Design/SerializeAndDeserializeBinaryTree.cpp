class Codec {
public:
    void preorderSerialise(string &tempString, TreeNode* tempNode){
        if(tempNode){
            tempString+=to_string(tempNode->val) + ',';
            preorderSerialise(tempString, tempNode->left);
            preorderSerialise(tempString, tempNode->right);
        }
        else{
            tempString+="n,";
        }
    }
    
    TreeNode* preorderDeserialise(stringstream &ss) {
	    string token;
	    getline(ss, token, ',');
    
	    if(token == "n") {
	    	return nullptr;
	    }
	
	    TreeNode* root = new TreeNode(stoi(token));
	    root->left = preorderDeserialise(ss, data);
	    root->right = preorderDeserialise(ss, data);
	    root->right = preorderDeserialise(ss);
	    return root;
    }

    string serialize(TreeNode* root) {
        string codedTree;
        preorderSerialise(codedTree, root);
        return codedTree;
    }

    TreeNode* deserialize(string data) {
        stringstream buffer(data);
        return preorderDeserialise(buffer);
    }
};
