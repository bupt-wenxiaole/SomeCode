def addBinary(a, b):
	
	lengthA=len(a);lengthB=len(b)
	lendiff=lengthA - lengthB
	diststring=''
	for i in range(abs(lendiff)):
		diststring+='0'
	if lendiff>0:
		b=diststring+b
	else:
		a=diststring+a
	i=max(lengthA,lengthB)-1
	resultString='';curCarry=0
	while i>=0:
		curPos=(int(a[i])+int(b[i])+curCarry)%2
		resultString=str(curPos)+resultString
		if i==0:
			if (int(a[i])+int(b[i])+curCarry)>=2:
				return '1'+resultString
			else:
				return resultString
		if (int(a[i])+int(b[i])+curCarry)>=2:
			curCarry=1
		else:
			curCarry=0
		i-=1
print addBinary('1010','1011')









