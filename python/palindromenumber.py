def isPalindrome(x):
	flag=True
	if x<0:
		flag=False
		return flag
	string=str(x)
	tmpList=list(string)
	
	length=len(tmpList)
	for number in range(length/2):
		if tmpList[number] != tmpList[length-1-number]:
			flag=False
			return flag
	return flag
print isPalindrome(-2147447412)



