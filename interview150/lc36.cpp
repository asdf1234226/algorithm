// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// board.length == 9
// board[i].length == 9
// board[i][j] 是一位数字（1-9）或者 '.'
bool isValidSudoku(vector<vector<char>>& board) {
	set<char> st;
	for(int i=0;i<9;i++){
		st.clear();
		for(int j=0;j<9;j++){
			if(board[i][j]=='.') continue;
			if(st.find(board[i][j])!=st.end()){
				return false;
			}
			st.insert(board[i][j]);
		}
	}
	for(int i=0;i<9;i++){
		st.clear();
		for(int j=0;j<9;j++){
			if(board[i][j]=='.') continue;
			if(st.find(board[j][i])!=st.end()){
				return false;
			}
			st.insert(board[j][i]);
		}
	}
	//3x3, 9x9编号0到8
	set<int> st1;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(board[i][j]=='.') continue;
			int index = (i/3)*3+(j/3);
			int num = (board[i][j]-'0')+index*9;//编号，第一个3*3被映射成1-9，第二个被映射成10-18，第三个被映射成19-27
			if(st1.find(num)!=st1.end()){
				return false;
			}
			st1.insert(num);
		}
	}
	return true;
}