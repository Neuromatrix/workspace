import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")

def f(s,c,m):
    if s>=166:
        return (c%2==m%2 and c==m)
    if c==m:
        return 0
    h = [f(s+10,c+1,m),f(s+2,c+1,m)]
    for i in range(2,85):
        if s*(i-1)<=80:
            h.append(f(s*i,c+1,m))
    return any(h) if(c+1)%2==m%2 else all(h)
if __name__ == "__main__":
    for s in range(1,230):
            if f(s,0,4):
                print(s,4)
