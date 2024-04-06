
//每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度
typedef pair<TreeNode*, long long> PII;
int widthOfBinaryTree(TreeNode* root) {
    queue<PII> q;
    long long ans = 0;
    q.push({root,1});
    while(!q.empty()){
        int size = q.size();
        long long st =-1;
        long long ed=-1;
        for(int i=0;i<size;i++){
            PII pii = q.front();
            TreeNode* nod = pii.first;
            long long index = pii.second;
            if(i==0){
                st=index;
            }
            if(i==size-1){
                ed=index;
            }
            q.pop();
            if(nod->left){
                q.push({nod->left,2*index});
            }
            if(nod->right){
                q.push({nod->right,2*index+1});
            }
        }
        ans=max(ans,ed-st+1);
    }
    return ans;
}

//上面方案index编号数值会超大，所以每一层都会重置编号
    int widthOfBinaryTree_opt(TreeNode* root) {
        map<TreeNode*, int> mp;
        mp[root]=1;
        long ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        long st = -1, ed = -1;
        while(!q.empty()){
            int size = q.size();
            long minIndex = mp[q.front()];
            for(int i=0;i<size;i++){
                TreeNode* nod = q.front();
                long index=mp[nod]-minIndex;//每一层重置编号，防止index数值过大
                if(i==0){
                    st=index;
                }
                if(i==size-1){
                    ed=index;
                }
                q.pop();
                if(nod->left){
                    q.push(nod->left);
                    mp[nod->left]=2*index;
                }
                if(nod->right){
                    q.push(nod->right);
                    mp[nod->right]=2*index+1;
                }
            }
            ans=max(ans,ed-st+1);
        }
        return ans;
    }