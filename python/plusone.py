def plusOne(digits):
	length=len(digits)
	i=length-1
	while(i>=0):
		if i==0:
			if (digits[i]+1)>9:
				digits[i]=0
				result=[1]
				result.extend(digits)
				return result
		if (digits[i]+1)<=9:
			digits[i]+=1
			return digits
		else:
			digits[i]=0
			i-=1
	return digits
print plusOne([print9,9])

