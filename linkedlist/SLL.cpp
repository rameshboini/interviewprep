#include "linkedlist.h"

//GFG-100 5

Node* createNode(int a)
{
    Node* n = new Node();
    n->data=a;
    n->next=nullptr;
    return n;
}

void printMiddleOfSLL(Node* head)
{
    if(!head){
        cout<<"Empty list, No middle"<<endl;
        return;
    }
    Node* s = head;
    Node* d = head;
    
    while(d && d->next)
    {
        s=s->next;
        d=d->next->next;
    }
    cout<<"Middle: "<<s->data<<endl;
}

int main(){
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printSLL(head);

    printMiddleOfSLL(head);

}