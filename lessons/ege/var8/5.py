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
u = 516 #board
ans = 10000
for i in range(1,1000):
    r = binn(i)
    if i%2==1:
        res = '1' + r +'01'
    else:
        res = r + '10'
    res = dec(res)
    if res > u:
        print(i)
        sys.exit(0)