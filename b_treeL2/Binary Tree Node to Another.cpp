
class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root)
            return 0;
        if (root->val == p || root->val == q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
            return root;
        else if (l)
            return l;
        else
            return r;
    }
    bool findPath(TreeNode* root, int target, string &path) {
        if (!root) return false;
        if (root->val == target) return true;
        
        path += 'L';
        if (findPath(root->left, target, path)) return true;
        path.pop_back();
        
        path += 'R';
        if (findPath(root->right, target, path)) return true;
        path.pop_back();
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        TreeNode* lca=lowestCommonAncestor(root,startValue,destValue);
        findPath(lca, startValue, startPath);
        findPath(lca, destValue, destPath);
        
        string upMoves(startPath.size() , 'U');

        
        return upMoves + destPath;
    }
};

// using DFS 

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int s, int d)
    {
        if (root == NULL || root->val == s || root->val == d)
            return root;
        
        TreeNode* left = LCA(root->left, s, d);
        TreeNode* right = LCA(root->right, s, d);
    
        if (left == NULL)
            return right;
        
        if (right == NULL)
            return left;

        return root;
    }
    bool dfs(TreeNode* root, int val, string &path)
    {
        if (root == NULL)
            return false;
        
        if (root->val == val)
            return true;

        bool left = dfs(root->left, val, path);
        bool right = dfs(root->right, val, path);

        if (left == true)
        {
            path.push_back('L');
            return true;
        }
        if (right == true)
        {
            path.push_back('R');
            return true;
        }

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* parent = LCA(root, startValue, destValue);

        string sPath = "";
        dfs(parent, startValue, sPath);
        string dPath = "";
        dfs(parent, destValue, dPath);

        reverse(sPath.begin(), sPath.end());
        reverse(dPath.begin(), dPath.end());
        
        for (auto &x : sPath)
            x = 'U';
        
        return sPath + dPath;
    }
};