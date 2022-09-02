from os import remove
import smtpd
import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")


def dec(data): #перевод бинарной строки в десятичное число 
    res = 0
    pw = 0
    while len(data) > 0:
        res += int(data[-1])*(2**pw)
        data = data[:-1]
        pw+=1
    return res


def binn(numb): # так как в python уже есть функция перевода числа, нам надо ее чуть чуть подправить, а именно bin(x) возвращает строку в виде 0b010101, и нам надо убрать первые 2 символа
    tmp = bin(numb)
    return tmp[2:]


#main
u = 19 #board
ans = 10000
for i in range(100000000,1000000000):
    p = 0
    y = i
    while y > 0:
        p+=y%10
        y//=10
    
    n = binn(p) # переводим наше число в временную переменную
    zp = n.count('1')
    if zp%2==0:
        res = "1" + n + "00"
    else :
        res = "10" + n + "1"
    #после выполнения условий мы переводим число обратно в 10ичную
    ress = dec(res)
    if ress == 21 :
        print(ress)
