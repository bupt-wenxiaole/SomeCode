def countAndSay(n):
	beforeSeq='1'
	while n>1:
		curLength=len(beforeSeq)
		key=beforeSeq[0];count=0
		afterSeq=''
		for i in range(curLength): 
			if beforeSeq[i]==key:
				count+=1
				if i==curLength-1:
					afterSeq+=(str(count)+key)
			else:
				afterSeq+=(str(count)+key)
				key=beforeSeq[i]
				count=1
				if i==curLength-1:
					afterSeq+=(str(count)+key)
		beforeSeq=afterSeq
		n-=1
	result=afterSeq
	return result

print countAndSay(2)


