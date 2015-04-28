def isValidSudoku(board):
	def isValidPoint(x,y,tmp):
		#判断行
		for j in range(9):
			if board[x][j]== tmp:      #之所以用tmp变量暂存判断点的值是为了防止扫描到自己时直接返回假导致出错
				return False
		#判断列
		for i in range(9):
			if board[i][y]==tmp:
				return False
		#判断小九宫格
		for i in range(3):
			for j in rang(3):
				if board[(x/3)*3+i][(y/3)*3+j]==tmp:
					return False
		return True

	#下面开始遍历整个二维数组,逐个判断每个点是否符合数独要求
	for i in range(9):
		for j in range(9):
			if board[i][j]=='.':
				continue
			else:
				tmp=board[i][j]
				board[i][j]='A'  #这里的A可以换成除了数字0-9之外的任何字符，目的是为配合tmp使用
				if not isValidPoint(i,j,tmp):
					return False
				else:
					board[i][j]=tmp

	return True
