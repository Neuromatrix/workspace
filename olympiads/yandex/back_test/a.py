import sys

# sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
# sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")


n = int(input())
l = [0]*n

for i in range(n):
    l[i] = input().split(",")
for k in l:
    sur = k[0]
    name = k[1]
    otch = k[2]
    d = k[3]
    m = k[4]
    y = k[5]
    rd = 0
    rm = 0
    for i in d:
        rd+=int(i)
    for i in m:
        rm+=int(i)
    cnt_dif_sumb = len(set(sur+name+otch))
    cnt_sum_month_and_day = (rd+rm)*64
    fsymb = (ord(sur[0].lower())-ord('a')+1)*256
    sum = cnt_dif_sumb+cnt_sum_month_and_day+fsymb
    rsum = str(hex(sum)).upper()
    rsum = rsum[2:]
    if(len(rsum)<3):
        rsum = "0000000"+rsum

    rsum = rsum[-3:]
    print(rsum)
