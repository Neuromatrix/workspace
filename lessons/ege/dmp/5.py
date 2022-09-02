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
u = 19 #board
ans = 10000
for i in range(0,1000):
    n = binn(i)
    if i%2==0:
        res = "10" + n
    else :
        res = "1" + n + "01"
    ress = dec(res)
    if ress >= u:
        ans = min(ans, i)


print(ans)