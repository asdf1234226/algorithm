// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],
// [10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //右上角点为顶点逆时针旋转45°，类似二叉搜索树
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0, j = n-1;
    while (i<m && j>=0)
    {
        if(matrix[i][j]==target){
            return true;
        }else if (matrix[i][j]<target)
        {
            i++;
        }else
        {
            j--;
        }
    }
    return false;
}