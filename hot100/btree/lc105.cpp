//
// Created by SP on 2023/11/27.
//

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

//前序   根左右
//中序   左根右
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //            根节点         中序遍历左边界     中序遍历右边界
    //左子树                       left              i-1
    // 右子树                       i+1              right
}

public TreeNode buildTree(int[] preorder, int[] inorder) {
    return build(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
}
public TreeNode build(int[] preorder,int preStart,int preEnd,
                      int[] inorder,int inStart,int inEnd){
    if(preStart>preEnd){
        return null;
    }
    int rootVal=preorder[preStart];
    int index=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(rootVal==inorder[i]){
            index=i;
            break;
        }
    }
    int leftSize=index-inStart;
    TreeNode root=new TreeNode(rootVal);
    root.left=build(preorder,preStart+1,preStart+leftSize,
                    inorder,inStart,index-1);
    root.right=build(preorder,preStart+leftSize+1,preEnd,
                     inorder,index+1,inEnd);
    return root;
}