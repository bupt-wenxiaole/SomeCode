def removeDuplicates(A):
	if A==[]: return 0
	start=1;keyValue=A[0];length=len(A)
	for i in range(length):
		if A[i]!=keyValue:
			keyValue=A[i]
			A[start]=A[i]
			start+=1
	A=A[:start]
	return start


print removeDuplicates([1,1,2,2,2,3,3,3])











  
