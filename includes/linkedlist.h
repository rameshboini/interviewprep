#include "basic.h"

class Node{
    public:
    Node(int d){
        data = d;
        next = nullptr;
    }
    
    int data;
    Node* next;
};

void printSLL(Node* head)
{
    while(head)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
    cout<<endl;
}
