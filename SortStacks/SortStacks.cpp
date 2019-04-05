/*
 Question : Given a stack, sort the elements in the stack using one additional stack. 
 ● Eg. sort([1, 3, 2, 4]) = [1,2,3,4]
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
  StackOpr() { size = SIZE;}
  StackOpr(int);
  
  void push(int data);
  int pop();
  
  bool isEmpty();
  bool isFull();
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

void StackOpr::push(int data)
{
    if(isFull())
        cout << endl << "Stack is full";
    else
        arr[++top] = data;
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
    StackOpr s(4);
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    while(!s.isEmpty())
    {
        cout << endl << s.pop();
    }

    if(s.isEmpty())
        cout << endl << "Stack is empty";
        
    return 0;
}
