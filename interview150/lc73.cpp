
    void setZeroes(vector<vector<int>>& matrix) {
        //利用矩阵的第一行和第一列来记录哪些行和列需要被置零，根据这个记录将其他行列置0；
        //在这之前还要对第一行第一列记录是否需要置0；
        int m = matrix.size();
        int n = matrix[0].size();
        bool line = false, col=false;
        //1.记录首行首列是否需要
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                line=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col=true;
                break;
            }
        }
        //首行首列记录哪些行/列需要清零
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //根据第一行清理其他
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        //根据第一列清理其他
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //首行是否需要
        if(line){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }