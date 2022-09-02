import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")#!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")#!REMOVE

if __name__ == "__main__":
    numb = 5*729**8+7*81**12+3**16-171
    base = 9
    f = 0
    arr = [0]*base

    while numb > 0:
        arr[numb%base] += 1
        numb //= base
    print(arr)