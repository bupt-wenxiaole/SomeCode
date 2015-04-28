def romanToInteger(s):
	romanValue={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
	if len(s)==1:
		return romanValue[s]
	length=len(s)
	last=romanValue[s[0]]
	result=0
	sub=romanValue[s[0]]
	for i in range(1,length):
		cur=romanValue[s[i]]
		if cur==last:
			sub+=cur
		elif cur>last:
			sub=cur-sub
		else:  result+=sub;sub=cur
		last=cur
	result+=sub
	return result
print romanToInteger("MDCCCXCIX")

