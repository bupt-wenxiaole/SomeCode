def reverse(x):
    maxInt= 2147483647
    minInt=-2147483648
    if x<0:
        sign=-1
    else: sign=1
    strx=str(abs(x))
    result=strx[::-1]
    if (sign*int(result)>maxInt)or(sign*int(result)<minInt):
        return 0
    else: return sign*int(result)

print reverse(1534236469)

