#include "linkedlist.h"

void push(Node **stack, int data)
{
    Node *tmp = new Node(data);
    tmp->next = *stack;
    *stack = tmp;
}

int pop(Node **stack)
{
    int ret = (*stack)->data;
    Node *de = (*stack);
    *stack = (*stack)->next;
    delete de;
    return ret;
}

void printStack(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *sortStack(Node *stack)
{
    Node *tmp = nullptr;

    while (stack)
    {
        int x = pop(&stack);

        while (tmp && tmp->data > x)
        {
            push(&stack,pop(&tmp));
        }
        push(&tmp,x);
    }
    return tmp;
}

int main()
{

    Node *stack = new Node(10);
    push(&stack, 5);
    push(&stack, 50);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 8);
    push(&stack, 6);
    push(&stack, 55);

    printStack(stack);

    printStack(sortStack(stack));
}