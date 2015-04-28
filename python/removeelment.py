def removeElenment(A,elem):
	if A==[]: return 0
	length=len(A);start=0
	for i in range(length):
		if A[i]!=elem:
			A[start]=A[i]
			start+=1
	A=A[:start]
	return len(A)
print removeElenment([4,5],5)