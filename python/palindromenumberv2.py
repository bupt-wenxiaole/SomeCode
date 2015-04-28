def isPalindrome(x):
	if x<0:
		return False
	string=str(x)
	tmpList=list(string)
	reverseList=tmpList[::-1]
	if reverseList==tmpList:
		return True
	else:
		return False
print isPalindrome(123321)