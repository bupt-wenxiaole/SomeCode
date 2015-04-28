def lengthOfLastWord(s):
    if s=='':
        return 0
    length=len(s)
    count=0
    for i in range(length):
        if s[i]==' ':
            count+=1
    if count==length:
        return 0
    return len(s.split()[-1])


print lengthOfLastWord('         ')