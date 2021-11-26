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
    string value;
    Node* next;
};

struct List {
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
};

Node* makeNode(string key)
{
    Node* ans = new Node;
    ans->value = key; // (*ans).value = key;
    ans->next = NULL;
    return ans;
}

void pushFront(List& l, string key)
{
    Node* tmp = makeNode(key); // ����� � �������
    if (l.size == 0)
    {
        l.head = tmp;
        l.tail = tmp;
    }
    else
    {
        tmp->next = l.head;
        l.head = tmp;
    }
    l.size++;
    return;
}

void pushBack(List& l, string key)
{
    Node* tmp = makeNode(key);
    if (l.size == 0)
    {
        l.head = tmp;
        l.tail = tmp;
    }
    else
    {
        Node* p = l.head;
        for (int i = 0; i < l.size - 1; i++) p = p->next;
        p->next = tmp;
        l.tail = tmp;
    }
    l.size++;
    return;
}

/*bool insert(List& l, int index, int key) // index ==0 ������������ ������� � ������
{
    if (index < 0 || index > l.size) return false;
    if (l.size == 0)
    {
        pushBack(l, key);
        return true;
    }
    if (index == 0)
    {
        pushFront(l, key);
        return true;
    }
    if (index == l.size)
    {
        pushBack(l, key);
        return true;
    }
    Node* p = l.head;
    for (int i = 0; i < index - 1; i++) p = p->next; // ������ ���������
    Node* tmp = makeNode(key);
    tmp->next = p->next;
    p->next = tmp;
    l.size++;
    return true;
}

bool PopFront(List& l)
{
    if (l.size <= 0) return false;
    Node* p = l.head;
    l.head = l.head->next;
    if (l.size == 1) l.tail = NULL;
    delete p;
    l.size--;
    return true;
}
bool erase(List& l, int index)
{
    if (index < 0 || index >= l.size) return false;
    if (index == 0) return PopFront(l);
    Node* p = l.head;
    for (int i = 0; i < index - 1; i++) p = p->next;// p->next - ��� ��, ��� ����� �������
//	cout<<"!"<<p->value<<endl;
    Node* q = p->next;
    //cout<<"!"<<q->value<<endl;
    //cout<<"!"<<q->next->value<<endl;
    p->next = q->next;
    if (p->next == NULL) l.tail = p;
    delete q;
    l.size--;
    return true;
}
bool PopBack(List& l)
{
    return erase(l, l.size - 1);
}

bool Find(List& l, int index, int& value) // value ������������ �������
{
    if (index < 0 || index >= l.size) return false;
    if (index == 0)
    {
        value = l.head->value;
        return true;
    }
    Node* p = l.head;
    for (int i = 0; i < index; i++) p = p->next;
    value = p->value;
    return true;
}
*/
void PrintList(List& l)
{
    Node* p = l.head;
    while (p != NULL)
    {
        cout << p->value << ' ';
        p = p->next;
    }
    cout << endl;
    return;
}

struct HT
{
    int bucket_count;
    List* buckets;
};

void make_HT(HT& table, int count)
{
    table.bucket_count = count;
    table.buckets = new List[count];
    return;
}


long long Hash(string key, int bucket_count)
{
    long long u = 1;

    for (int i = 0; i < key.length(); i++)
    {
        for (int j = 0; j < i; j++) u *= per;
        num += key[i] * u;

    }
    a = num % bucket_count;

    num = 0;
    return a;
}

void insert_HT(HT& table, string key)
{
    int hash_code = Hash(key, table.bucket_count);
    pushFront(table.buckets[hash_code], key);
    return;
}

bool del_HT(HT& table, string key)
{

    int hash_code = Hash(key, table.bucket_count);
    List* cur = (table.buckets + hash_code);
    if (cur->size == 1 && cur->tail->value == key)
    {
        cur->head = NULL;
        cur->tail = NULL;
        cur->size = 0;
        return true;
    }
    else if (cur->size == 1 && cur->tail->value != key) return false;

    Node* p = cur->head;
    if (p->value == key) {
        cur->head = p->next;
        delete p;
        cur->size--;
        return true;
    }
    while (p != NULL)
    {
        if (p->next == NULL) return false;
        else if (p->next->value == key)
        {
            Node* q = p->next;
            p->next = q->next;
            if (p->next == NULL) cur->tail = p;
            delete q;
            cur->size--;
            return true;
        }
        p = p->next;

    }


    return false;
}
Node* find_HT(HT& table, string key)
{
    int hash_code = Hash(key, table.bucket_count);
    List* cur = (table.buckets + hash_code);
    Node* p = cur->head;
    while (p != NULL)
    {
        if (p->value == key) return p;
        p = p->next;
    }
    return NULL;
}

void PrintHT(HT& table)
{
    for (int i = 0; i < table.bucket_count; i++)
    {
        PrintList(table.buckets[i]);
        //cout<<endl;
    }
}


























