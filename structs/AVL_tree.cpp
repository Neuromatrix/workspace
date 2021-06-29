#include <bits\stdc++.h>
#include <help/instr.cpp>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int counter = 0;

struct Node {
    int val;
    unsigned short int h;
    Node* l = NULL;
    Node* r = NULL;
};

Node* findAndDelMax(Node* p, int& max_val);
Node* balanced(Node* p);
int balance(Node* p);
Node* makeNode(int key)
{
    Node* p = new Node;
    p->val = key;
    p->h = 1;
    return p;
}
int height(Node* p);
void fixHeight(Node* p)
{
    if (p == NULL) return;
    p->h = (height(p->l) > height(p->r) ? height(p->l) : height(p->r)) + 1;
    return;
}

Node* insert(Node* p, int key)
{
    if (p == NULL) return makeNode(key);
    if (p->val > key) p->l = insert(p->l, key);
    if (p->val < key) p->r = insert(p->r, key);
    fixHeight(p);
    return balanced(p);
    //return p;
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
    cout << "(" << p->val << ',' << p->h << ',' << balance(p) << ")" << endl;
    printTree(p->l);
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
        fixHeight(p);
        return balanced(p);
    }
    if (p->val < key)
    {
        p->r = erase(p->r, key);
        fixHeight(p);
        return balanced(p);
    }
    if (p->l == NULL) 
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
        return balanced(p);
    }

}

Node* findAndDelMax(Node* p, int& max_val)
{
    if (p->r != NULL)
    {
        p->r = findAndDelMax(p->r, max_val);
        fixHeight(p);
        return balanced(p);
    }
    else
    {
        max_val = p->val;
        Node* tmp = p->l;
        delete p;
        return tmp;
    }
}

int height(Node* p) // O(1)
{
    if (p == NULL) return 0;
    return p->h;
}

int balance(Node* p) //O(1)
{
    if (p == NULL) return 0;
    return abs(height(p->l) - height(p->r));
}


bool isBalnced(Node* p)
{
    if (p == NULL) return true;
    return ((balance(p)) <= 1) && isBalnced(p->l) && isBalnced(p->r);
}

Node* smallLeftRotate(Node* p)
{
    Node* tmp = p->r;
    p->r = tmp->l;
    tmp->l = p;
    fixHeight(p);
    fixHeight(tmp);
    return tmp;
}

Node* smallRightRotate(Node* p)
{
    Node* tmp = p->l;
    p->l = tmp->r;
    tmp->r = p;
    fixHeight(p);
    fixHeight(tmp);
    return tmp;
}

Node* bigRightRotate(Node* p)
{
    p->l = smallLeftRotate(p->l);
    return smallRightRotate(p);
}

Node* bigLeftRotate(Node* p)
{
    p->r = smallRightRotate(p->r);
    return smallLeftRotate(p);
}











Node* balanced(Node* p)
{
    if (balance(p) == 2)
    {
        if (balance(p->l) == 1 || balance(p->l) == 0) //����� ������� �������
            return smallRightRotate(p);
        if (balance(p->l) == -1) // ������� ������ �������
        {
            return bigRightRotate(p);
        }
    }
    if (balance(p) == -2)
    {
        if (balance(p->r) == -1 || balance(p->r) == 0) //����� ����� �������
            return smallLeftRotate(p);
        if (balance(p->r) == 1) // ������� ����� �������
        {
            return bigLeftRotate(p);
        }
    }
    return p;
}
int count(Node* p)
{
    if (p == NULL) return 0;
    return height(p->l) + height(p->r) + 1;
}





