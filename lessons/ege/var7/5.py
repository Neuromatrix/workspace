from os import remove
import smtpd
import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")


def dec(data):
    res = 0
    pw = 0
    while len(data) > 0:
        res += int(data[-1])*(2**pw)
        data = data[:-1]
        pw+=1
    return res


def binn(numb):
    tmp = bin(numb)
    return tmp[2:]


#main
u = 100 #board
ans = 0
for i in range(10,1000):
    n = binn(i)
    zer = n.count("0")
    one = n.count("1")
    if one>zer:
         n+="1"
    else:
        n+="0"
    res = dec(n) 
    if res < u:
        ans = max(res, ans)


print(ans)