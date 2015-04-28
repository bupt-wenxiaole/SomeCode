def longestCommonPrefix(strs):
	strlen=len(strs)
	if strlen==0:
		return ''
	if strlen==1:
		return strs[0]
	minLen=min([len(strs[i]) for i in range(strlen)])
	resultString=''
	for j in range(minLen):
		equalNum=0
		for i in range(1,strlen):
			if strs[0][j]==strs[i][j]:
				equalNum+=1;
		if equalNum==strlen-1:
			resultString+=strs[0][j]
		else: return resultString
	return resultString
string=['ss']
print longestCommonPrefix(string)







