import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r") #!REMOVE
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w") #!REMOVE


if __name__ == "__main__":
    for i in range(4,100):
        s = "1" * i
        while "1111" in s or "222" in s or "33" in s:
            if "1111" in s:
                s = s.replace("1111","333",1)
            elif "222" in s:
                s = s.replace("222", "11",1)
            else:
                s = s.replace("33", "2",1)
        print(s)