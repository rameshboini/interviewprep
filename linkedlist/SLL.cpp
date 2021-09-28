#include "linkedlist.h"

//GFG-100 5

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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    printSLL(head);

    printMiddleOfSLL(head);

}