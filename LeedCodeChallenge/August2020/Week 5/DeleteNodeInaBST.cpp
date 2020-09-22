class Solution {
public:
	int LOrder(TreeNode* root) {
		while (root->right) {
			root = root->right;
		}
		return root->val;
	}

	int ROrder(TreeNode* root) {
		while (root->left) {
			root = root->left; 
		}
		return root->val;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;
		if (key > root->val)
			root->right = deleteNode(root->right, key);
		else if(key < root->val)
			root->left = deleteNode(root->left, key);
		else {
			if (!root->left && !root->right) {
				TreeNode* temp = root;
				root = nullptr;
				delete temp;
			}
            else if (root->left) {  
                root->val=LOrder(root->left);
                root->left=deleteNode(root->left, root->val);
			}
            else if (root->right) {
                root->val=ROrder(root->right);
                root->right=deleteNode(root->right, root->val);
			}
		}

		return root;
	}
};
