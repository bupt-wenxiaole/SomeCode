class Solution:
	def generate(self,numRows):
		result=[]
		for i in range(numRows):
			cur=[]
			cur.append(1)
			for j in range(1,i+1):
				if j==i:
					cur.append(1)
				else:
					cur.append(result[i-1][j-1]+result[i-1][j])
			result.append(cur)
		return result
s=Solution()
result=s.generater(5)
print result