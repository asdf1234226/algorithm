#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010;
int e[N], ne[N], idx;
int head =-1;

void add(int a){
    e[idx]=a;
    ne[idx]=head;
    head=idx;
    idx++;
}

void reverse() {
    int prev = -1, current = head, next;
    while (current != -1) {
        next = ne[current];  // 记录当前节点的下一个节点
        ne[current] = prev;  // 将当前节点的下一个节点指向前一个节点
        prev = current;  // 将前一个节点更新为当前节点
        current = next;  // 将当前节点更新为原来的下一个节点
    }
    head = prev;  // 最后，将头节点更新为原链表的最后一个节点
}


void print(){
    for(int i =head; i!=-1; i=ne[i]){
        cout << e[i] << " ";
    }
}


int main(){
    idx=0;
    add(1);
    add(2);
    add(3);
    reverse();
    print();
    return 0;
}