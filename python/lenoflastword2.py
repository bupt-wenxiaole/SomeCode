def lengthOfLastWord(s):
	length=len(s);sum=0
	while s[length-1]==' ':
		length-=1
	i=length-1
	while i>=0:
		if s[i]!=' ':
			i-=1
		else: break
	return sum

print lengthOfLastWord('hello world')