from dataclasses import replace
import sys

sys.stdin = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\input.txt","r")
sys.stdout = open(r"C:\\Users\\grivi\\vscodes\\.vscode\\output.txt","w")


s = "1"*70

while "2222" in s or "1111" in s:
    if "2222" in s:
        s = s.replace("2222","11",1)
    else:
        s = s.replace("1111", "22",1)
print(s)