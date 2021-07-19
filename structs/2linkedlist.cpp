#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
template <typename T> //тип данных, который поступает
class linkedlist// список
{
    private:
        struct Node{//узел спика
            T val;//значение в узле
            Node * p = NULL;// предыдущий элмент
            Node * n = NULL;//следующий элемент
        };
        size_t s = 0;// размер листа
        size_t med = 0;// индекс медианы
        Node  *head = NULL;//указатель на начало списка
        Node  *tail = NULL;//указатель на конец списка
        Node  *makenode(){//функция создания узла
            Node  *ret = new Node ;
            ret->p = NULL;
            ret->n = NULL;
            return ret;
        }
        void medcount(){//функция пересчета медианы
            med = s/2;
            return;
        }
    public:
        linkedlist(){//конструктор
            head = NULL;
            tail = NULL;
        }
        void print(){ // выовд списка с головы
            Node  *cur = head;
            while(cur!=NULL){
                cout << cur->val <<" ";
                cur=cur->n;
            }
            cout << nl;
            return;
        }
        void print(string sep){//перегрузка с пользовательским сепаратором
            Node  *cur = head;
            while(cur!=NULL){
                cout << cur->val <<sep;
                cur=cur->n;
            }
            cout << nl;
            return;
        }
        size_t size(){// возвращение размера листа
            return s;
        }
        T& front(){
            return head->val;// первый элемент листа
        }
        T& back(){
            return tail->val;// последний элемнт листа
        }
        T& operator[] (size_t index) // оператор возврата значения по индексу
        {
            if (index == 0) return front();
            if (index == s) return back();
            assert(index >= 0 && index < s);
            if (index < med){// выяснеям с каого конца нам ближе идти
                Node* cur =  head;
                size_t i = 0;
                while(i != index){
                    i++;
                    cur = cur->n;
                }
                return cur->val;
            }   
            else{
                Node* cur =  tail;
                size_t i = s-1;
                while(i != index){
                    i--;
                    cur = cur->p;
                }
                return cur->val;
            }
        }
        void push_back(T v){// втсавка в конец
            Node  *tmp = makenode();
            tmp->val=v;
            if (s == 0){
                head = tmp;
                tail = tmp;
            }
            else{
                tmp->p = tail;
                tail->n = tmp;
                tail = tmp;
            }
            s++;
            medcount();
            return;
        }
        void push_front(T v){// втсавка в начало
            Node  *tmp = makenode();
            tmp->val = v;
            if (s==0){
                head = tmp;
                tail = tmp;
            }
            else{
                tmp->n = head;
                head->p = tmp;
                head = tmp;
            }
            s++;
            medcount();
            return;
        }
        void pop_back(){
            if (s==0) return;// удаление с конца
            if (s==1){
                delete tail;
                tail = NULL;
                head = NULL;
            }
            else{
                tail->p->n = NULL;
                Node* tmp = tail;
                delete tail;
                tail = tmp->p;
                delete tmp;
            }
            s--;
            medcount();
            return;
        }
        void pop_front(){//удаление с начала
            if (s==0) return;
            if (s==1){
                delete head;
                tail = NULL;
                head = NULL;
            }
            else{
                Node* n_head = head->n;
                head = n_head;
                delete head->p;
            }
            s--;
            medcount();
            return;
        }
        void insert(T v,size_t index){//вставка на позицию по индексу, при которой все остальные сдвигаются в конец
            if (index == 0) return push_front(v);
            if (index == s) return push_back(v);
            assert(index >= 0 && index < s);
            Node  *tmp = makenode();
            tmp->val = v;
            if (index < med){
                Node* cur =  head;
                size_t i = 0;
                while(i != index){
                    i++;
                    cur = cur->p;
                }
                cur->n->p = tmp;
                tmp->n = cur->n;
                tmp->p=cur;
                cur->n = tmp;
                
            }   
            else{
                Node* cur =  tail;
                size_t i = s-1;
                while(i != index){
                    i--;
                    cur = cur->n;
                }
                cur->p->n = tmp;
                tmp->p = cur->p;
                tmp->n = cur;
                cur->p = tmp;
            }
            s++;
            medcount();
            return;
        }
        void erase(size_t index){
            if (index == 0) return pop_front();
            if (index == s-1) return pop_back();
            assert(index >= 0 && index < s);
            if (index < med){
                Node* cur =  head;
                size_t i = 0;
                while(i != index){
                    i++;
                    cur = cur->n;
                }
                cur->p->n = cur->n;
                cur->n->p = cur->p;
                delete cur;
            }   
            else{
                Node* cur =  tail;
                size_t i = s-1;
                while(i != index){
                    i--;
                    cur = cur->p;
                }
                cur->p->n = cur->n;
                cur->n->p = cur->p;
                delete cur;
            }
            s--;
            medcount();
            return;
        }
        size_t find(T v){
            Node *cur = head;
            for(int i = 0; i < s; i++){
                if(cur->val == v) return i;
                cur = cur->n;
            }
            return -1;
        }
};



inline void solve(){
    linkedlist <int> l;
    for (int i = 0; i< 15;i++){
        l.push_back(i);
    }
    l.print();
    l[10]=42;
    l.print();
    cout << l[l.find(43)];
    /*
        .....
    */
   return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    solve();
    return 0;
}