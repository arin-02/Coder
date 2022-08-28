 
 /*
 
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        bool lefttoright=true;
        q.push(root);
        while(!q.empty())
        {
            
            
            int sz=q.size();
             vector<int> v(sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode*x=q.front();
                q.pop();
                int index;
                if(lefttoright)
                {
                    index=i;
                    
                }
                else if(!lefttoright)
                {
                    index=sz-i-1;
                }
                v[index]=x->val;
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
                    
            }
            ans.push_back(v);
            lefttoright=!lefttoright;
            
        }
        return ans;
        
    }
};

*/