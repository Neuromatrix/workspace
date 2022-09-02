import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")

def f(a,b,c,m):
    if a+b>=247:
        return c%2==m%2
    if c==m:
        return 0
    h = [f(a*2,b,c+1,m),f(a+1,b,c+1,m),f(a,b*2,c+1,m),f(a,b+1,c+1,m)]
    return any(h) if(c+1)%2==m%2 else any(h)
if __name__ == "__main__":
    for s in range(1,230):
        for m in range (1,5):
            if f(17,s,0,m):
                print(s,m)
                break