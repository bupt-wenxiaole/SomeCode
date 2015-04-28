def strStr(haystack,needle):
	if haystack=='' or needle=='':
		return -1
	hayLength=len(haystack);needLength=len(needle)
	for i in range(hayLength):
		if haystack[i]==needle[0] and i+needLength<=hayLength:
			count=0
			for j in range(1,needLength):
				if haystack[i+j]==needle[j]:
					count+=1
				else: break
			if count==needLength-1:
				return i
	return -1

print strStr('abcdef','') 
