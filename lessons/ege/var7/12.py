import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r") #!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w") #!REMOVE


if __name__ == "__main__":
    s = "3"*185
    while "9999" in s or "333" in s:
        if "9999" in s:
            s = s.replace("9999","3",1)
        else:
            s = s.replace("333", "99",1)
    print(s)