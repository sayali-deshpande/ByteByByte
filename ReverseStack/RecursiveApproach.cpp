/*
  Reverse Stack
  ● Question : Given a stack, reverse the items without creating any additional data structures. 
  ● Eg. reverse(1‑>2‑>3) = 3‑>2‑>1
  
  Time complexity = o(n^2)
  Space complexity = 0(2n)
*/

#include <iostream>

using namespace std;

#define SIZE  10;

class StackOpr
{
  private:
  int *arr;
  int top;
  int size;
  
  public:
  
  StackOpr(): top(-1), size(10) 
  { 
    arr = new int[size];
  }
  
  StackOpr(int);
  
  void push(int data);
  int pop();
  void printStack();
  
  static StackOpr* reverseStack(StackOpr *s);
  void insertAtBottom(StackOpr *, int);
  
  bool isEmpty();
  bool isFull();
  
  int getTopElement();
};

StackOpr::StackOpr(int Size)
: size(Size)
{
    arr = new int[size];
    top = -1;
}

bool StackOpr::isEmpty()
{
    return top == -1;
}

bool StackOpr::isFull()
{
    return top == size -1;
}

int StackOpr::getTopElement()
{
    return arr[top];    
}

void StackOpr::push(int data)
{
    if(isFull())
        cout << endl << "Stack is full";
    else
        arr[++top] = data;
}

StackOpr* StackOpr::reverseStack(StackOpr *s)
{
	if(s->isEmpty())
	    return s;
	int temp = s->pop();
    reverseStack(s);
    s->insertAtBottom(s, temp);
    return s;
}

void StackOpr::insertAtBottom(StackOpr *s, int x)
{
    if(s->isEmpty())
    {
        s->push(x);
        return;
    }
    
    int temp = s->pop();
    insertAtBottom(s,x);
    s->push(temp);
}

int StackOpr::pop()
{
    if(isEmpty())
        return -1;
    else
        return arr[top--];
}

int main()
{
    StackOpr *s1 = new StackOpr(5);
    StackOpr s2;
    
    s1->push(5);
    s1->push(4);
    s1->push(3);
    s1->push(2);
    s1->push(1);

    StackOpr::reverseStack(s1);
    
    while(!s1->isEmpty())
    {
        cout << "  " << s1->getTopElement();
        s1->pop();
    }

    return 0;
}