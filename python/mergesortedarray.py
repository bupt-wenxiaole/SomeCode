def merge(A,m,B,n):
	p=0;q=0;C=[]
	while p<m and q<n:
		if A[p]<=B[q]:
			C.append(A[p])
			p+=1
		else:
			C.append(B[q])
			q+=1
	while p<m:
		C.append(A[p])
		p+=1
	while q<n:
		C.append(B[q])
		q+=1
	A=C
	return A
print merge([],0,[1],1)