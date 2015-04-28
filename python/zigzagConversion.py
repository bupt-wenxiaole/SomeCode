def convert(s,nRows):
    if nRows==1: return s
    tmp=['' for i in range(nRows)]
    index=-1;step=1
    for i in range(len(s)):
        index+=step
        if index==nRows:
            index=nRows-2;step=-1
        elif index==-1:
            index=1;step=1
        tmp[index]+=s[i]
    return ''.join(tmp)

print convert("PAYPALISHIRING",3)




















