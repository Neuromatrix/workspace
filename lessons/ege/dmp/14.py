import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")#!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")#!REMOVE

if __name__ == "__main__":
    numb = 5*216**3031+4*36**3042-3*6**3053-3064
    base = 6
    f = 0
    arr = [0]*base

    while numb > 0:
        arr[numb%base] += 1
        numb //= base
    print(arr)
    sum = 0
    for i in range(0,6):
        sum += (i)*arr[i]
    print(sum)