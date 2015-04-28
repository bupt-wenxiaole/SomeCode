def merge(A,m,B,n):
	for i in range(m+n-1,-1,-1):
		if m==0 or (n>0 and B[n-1]>A[m-1]):
			A[i]=B[n-1]
			n-=1
		else:
			A[i]=A[m-1]
			m-=1
		return A
print merge([1,2,3,0,0,0,0],3,[2,2,2,2],4)