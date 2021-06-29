#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>


using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
struct Node {
    int val;
    Node* l = NULL;
    Node* r = NULL;
};

Node* findAndDelMax(Node* p, int& max_val);
Node* makeNode(int key)
{
    Node* p = new Node;
    p->val = key;
    return p;
}

Node* insert(Node* p, int key, int& n)
{
    if (p == NULL) return makeNode(key);
    if (p->val > key) p->l = insert(p->l, key, n);
    if (p->val < key) p->r = insert(p->r, key, n);
    if (p->val == key) n--;
    return p;
}

Node* find(Node* p, int key)
{
    if (p == NULL) return NULL;
    if (p->val > key) return find(p->l, key);
    if (p->val < key) return find(p->r, key);
    return p;
}

void printTree(Node* p)
{
    if (p == NULL) return;

    printTree(p->l);

    cout << p->val << endl;

    printTree(p->r);
    return;
}
void printLeaves(Node* p)
{
    if (p == NULL) return;

    printLeaves(p->l);

    if (p->l == NULL && p->r == NULL) cout << p->val << endl;

    printLeaves(p->r);
    return;
}
void printWays(Node* p)
{
    if (p == NULL) return;

    printWays(p->l);

    if (p->l != NULL && p->r != NULL) cout << p->val << endl;

    printWays(p->r);
    return;
}

void printOneWays(Node* p)
{
    if (p == NULL) return;

    printOneWays(p->l);

    if (p->l != NULL && p->r == NULL || p->l == NULL && p->r != NULL) cout << p->val << endl;

    printOneWays(p->r);
    return;
}


Node* erase(Node* p, int key)
{
    if (p == NULL) return NULL;
    if (p->val > key)
    {
        p->l = erase(p->l, key);
        return p;
    }
    if (p->val < key)
    {
        p->r = erase(p->r, key);
        return p;
    }
    // p ����� �������
    if (p->l == NULL) //����� �����
    {
        Node* tmp = p->r;
        delete p;
        return tmp;
    }
    else
    {
        int new_val;
        p->l = findAndDelMax(p->l, new_val);
        p->val = new_val;
        return p;
    }

}

Node* findAndDelMax(Node* p, int& max_val)
{
    if (p->r != NULL)
    {
        p->r = findAndDelMax(p->r, max_val);
        return p;
    }
    else
    {
        max_val = p->val;
        Node* tmp = p->l;
        delete p;
        return tmp;
    }
}

int height(Node* p)
{
    if (p == NULL) return 0;
    return max(height(p->l), height(p->r)) + 1;
}

int balance(Node* p)
{
    if (p == NULL) return 0;
    return height(p->l) - height(p->r);
}

bool isBalnced(Node* p)
{
    if (p == NULL) return true;
    return (abs(balance(p)) <= 1) && isBalnced(p->l) && isBalnced(p->r);
}

int count(Node* p)
{
    if (p == NULL) return 0;
    return height(p->l) + height(p->r) + 1;
}

