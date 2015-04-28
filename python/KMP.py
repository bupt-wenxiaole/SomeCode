
def kmpSerch(haystack,needle):
	def GetNext(needle,next=[]):
		needleLength=len(needle)
		next.append(-1)
		k=-1;j=0
		while(j<needleLength-1):
			if k==-1 or needle[j]==needle[k]:
				k+=1
				j+=1
				next.append(k)
			else:
				k=next[k]
		return next
	next=GetNext(needle)
	
	i=0;j=0
	hayLength=len(haystack);needleLength=len(needle)
	while i<hayLength and j<needleLength:
		if j==-1 or haystack[i]==needle[j]:
			i+=1
			j+=1
		else:
			j=next[j]
	if j==needleLength:
		return i-j
	else:
		return -1
print kmpSerch('abcd','cd')
