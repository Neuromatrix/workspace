import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")


if __name__ == '__main__':
    s = input()
    s = s.replace('AB','x')
    s = s.replace('AC','x')
    print(s)