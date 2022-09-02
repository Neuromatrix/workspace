import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")#!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")#!REMOVE

if __name__ == "__main__":
    numb = 3*16**2018-2*8**1028-3*4**1100-2**1050-2022
    base = 4
    f = 0
    arr = [0]*base

    while numb > 0:
        arr[numb%base] += 1
        numb //= base
    print(arr)