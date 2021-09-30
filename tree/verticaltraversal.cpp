#include "tree.h"

#include <unordered_map>
#include <queue>

//GFG-100 9

void printVerticalOrder(Node* root)
{
    if(!root)
    {
        return;
    }

    unordered_map<int, vector<int>> um;
    queue<pair<Node*, int>> Q;
    int hd = 0;
    int min = hd, max = 0;

    Q.push(make_pair(root,hd));
    while(!Q.empty())
    {
        auto t = Q.front();
        Q.pop();

        if(max<t.second)
            max = t.second;
        if(min>t.second)
            min = t.second;

        um[t.second].push_back(t.first->data);

        if(t.first->left)
        {
            Q.push(make_pair(t.first->left, t.second-1));
        }
        if(t.first->right)
        {
            Q.push(make_pair(t.first->right, t.second+1));
        }
    }

    for(int i=min;i<=max;i++)
    {
        auto v = um[i];
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->right->right->left->right->right = new Node(12);

    printVerticalOrder(root);

}