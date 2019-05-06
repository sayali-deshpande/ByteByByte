// Write a program to Print Reverse link list

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

class LinkList{
    
    private:
        node *head, *currNode;
        node* getRootNode() {return head;}
    public:
        LinkList()
        {
            head = NULL;
            currNode = NULL;
        }
        
        void addNode(int data);
        void displayList();
        void reversePrint(node *temp);
};

void LinkList::addNode(int data)
{
    node *tempNode = new node;
    tempNode->data = data;
    tempNode->next = NULL;
    
    if(head == NULL)
    {
        head = tempNode;
        currNode = tempNode;
    }
    else
    {
        currNode->next = tempNode;
        currNode = currNode->next;
    }
}

void LinkList::displayList()
{
    node *currNode = getRootNode();
    
    while(currNode->next != NULL)
    {
        cout << "\t" << currNode->data;
        currNode = currNode->next;
    }
    cout << "\t" << currNode->data;
    
    cout << endl << "Reverse link list :" <<endl;
    reversePrint(getRootNode());
}

void LinkList::reversePrint(node *temp)
{
    if(temp == NULL)
        return;
    reversePrint(temp->next);
    cout << "\t" << temp->data;
}

int main()
{
    LinkList *l = new LinkList();
    l->addNode(1);
    l->addNode(2);
    l->addNode(3);

    l->displayList();
    
    return 0;
}
