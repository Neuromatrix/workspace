import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")#!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")#!REMOVE

if __name__ == "__main__":
    numb = 3*5**1984-7*25**777-11*125**666-404
    base = 5
    f = 0
    arr = [0]*base
    numb = abs(numb)
    while numb > 0:
        arr[numb%base] += 1
        numb //= base
    print(arr)