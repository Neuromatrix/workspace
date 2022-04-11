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
u = 137 #board
ans = 10000
for i in range(10,1000):
    n = str(i)
    mx = 0
    mn = 1000
    for a in range(0,len(n)-1):
        tmp = n[a]+n[a+1]
        y = int(tmp[0])*10+int(tmp[1])
        mx = max(mx, y)
        mn = min(mn, y)
    res = mx + mn
    if res == u:
        ans = min(ans, i)


print(ans)