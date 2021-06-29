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
const bool RED = false;
const bool BLACK = true;

class Node 
{
    public:
  Node *l, *r, *p;
  bool col;
  int data;
};

Node sentinel = {&sentinel, &sentinel, NULL, BLACK, 0};
Node * NIL = & sentinel;
Node * root = NIL;

void rotateLeft (Node * x); //Поворот налево отн узла х 
void rotateRight (Node * x); // Same thing
void insertFixUp (Node * x); //Исправление правил КЧ дерева при вставке
Node * insertNode (int key); // Вставка и она возвращает узел который вставила(Не рекурсивная)
void deleteFixUp (Node * x); // Исправлять правила КЧ дерева при удалении
void deleteNode (Node *z); // Удаление
 //возвращает указатель на ключ
Node* find_min(Node* p)
{
    if (p->l == NIL) return p;
    else return find_min(p->l);
}
void print_tree(Node *p, int level)
{

  if(p==NULL || p == NIL)

    return;

  print_tree(p->l, level+1);

  for(int i=0; i<level; i++)

    cout << ".";

  cout << (p->col == BLACK? 'B' : 'R') <<p->data << endl;

  print_tree(p->r, level+1);

}



Node * insertNode (int key)
{
    Node * current, * parent, *x;
    current = root;
    parent = NULL;
    while (current != NIL)
    {
        
        parent = current;
        if (key > current->data) current = current->r;
        else current = current->l;
    }
    x = new Node();
    x->data = key;
    x->l = NIL;
    x->r = NIL;
    x->p = parent;
    x->col = RED;
    
    if (parent == NULL) root = x;
    else
    {
        if (key < parent->data) parent->l = x;
        else parent->r = x;
    }
    
    insertFixUp(x);
    return x;
}

void insertFixUp (Node * x)
{
    while (x!= root && x->p->col==RED)
    {
        if (x->p == x->p->p->l)// Наш отец это левый сын деда
        {
            Node * y = x->p->p->r; //Наш дядя
            if (y->col == RED )
            {
                x->p->col = BLACK;
                y->col = BLACK;
                x->p->p->col = RED;
                x = x->p->p;
            }
            else //Отец красный дядя черный
            {
                if (x == x->p->r)
                {
                    x = x->p;
                    rotateLeft(x);
                }
                    x->p->col = BLACK;
                    x->p->p->col = RED;
                    rotateRight(x->p->p);
            }
        }
        else // Зеркальная копия когда отец правый сын деда
        {
            Node * y = x->p->p->l;
            if (y->col == RED)
            {
                x->p->col = BLACK;
                y->col = BLACK;
                x->p->p->col = RED;
                x=x->p->p;
            }
            else
            {
                if (x == x->p->l)
                {
                    x = x->p;
                    rotateRight(x);
                }
                x->p->col = BLACK;
                x->p->p->col = RED;
                rotateLeft(x->p->p);
            }
        }
    }
    root->col = BLACK;
}

void rotateLeft (Node * x)
{
    Node * y = x->r;
    x->r = y->l;
    if (y->l != NIL) y->l->p = x;// Обратная привязка родителя
    if (y!= NIL) y->p = x->p;
    if (x->p == NULL)
    {
        root = y;
    }
    else
    {
        if (x == x->p->l) x->p->l = y;
        else x->p->r = y;
    }
    
    y->l = x;
    if (x!=NIL) x->p = y;
}

void rotateRight(Node * x)
{
    Node * y = x->l;
    x->l = y->r;
    if (y->r != NIL) y->r->p = x;
    if ( y != NIL) y->p = x->p;
    if (x->p == NULL)
    {
        root = y;
    }
    else
    {
        if (x==x->p->r) x->p->r = y;
         else x->p->l = y;
    }
    y->r = x;
     if (x != NIL) x->p = y;
}


void deleteNode (Node *z)
{
    Node * x, * y;
    if ( z == NULL || z == NIL) return;
    if (z->l == NIL || z->r == NIL) y=z;
    else
    {
        y = z->r;
        while (y->l != NIL) y = y->l;
    }
    if (y->l != NIL) //Есть только левый сын у z
        x = y->l;
    else
        x = y->r;
    x->p = y->p;
    if (y->p == NULL) root = x;
    else
    {
        if (y == y->p->l) y->p->l = x;
        else y->p->r = x;
    }
    if (z!=y) z->data = y->data;
    if (y->col == BLACK) deleteFixUp(x);
    
    delete y;
}

void deleteFixUp (Node * x)
{
    while (x!=root && x->col == BLACK)
    {
        if (x = x->p->l)
        {
            Node * w = x ->p->r;
            if (w->col == RED) // Случай 1
            {
                w->col = BLACK;
                x->p->col = RED;
                rotateLeft(x->p);
                w = x->p->r;
            }
            if (w->l->col == BLACK && w->r->col == BLACK) //Случай 2
            {
                w->col = RED;
                x= x->p;
            }
            else
            {
                if (w->r->col == BLACK)//Случай 3
                {
                    w->l->col = BLACK;
                    w->col = RED;
                    rotateRight(w);
                    w = x->p->r;
                }
                //Случай 4
                w->col = x->p->col;
                x->p->col = BLACK;
                w->r->col = BLACK;
                rotateLeft(x->p);
                x = root;
            }
        }
        else // x - это правый сын
        {
            Node * w = x ->p->l;
            if (w->col == RED) // Случай 1
            {
                w->col = BLACK;
                x->p->col = RED;
                rotateRight(x->p);
                w = x->p->l;
            }
            if (w->l->col == BLACK && w->r->col == BLACK) //Случай 2
            {
                w->col = RED;
                x= x->p;
            }
            else
            {
                if (w->l->col == BLACK)//Случай 3
                {
                    w->r->col = BLACK;
                    w->col = RED;
                    rotateLeft(w);
                    w = x->p->l;
                }
                //Случай 4
                w->col = x->p->col;
                x->p->col = BLACK;
                w->l->col = BLACK;
                rotateRight(x->p);
                x = root;
            }
        }
    }
    x->col = BLACK;
}


