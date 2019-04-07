/*
 Question : Given a stack, sort the elements in the stack using one additional stack. 
 ● Eg. sort([1, 3, 2, 4]) = [1,2,3,4]
*/

#include <iostream>

using namespace std;

#define SIZE  10;
0000
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
  StackOpr sortStack();
  
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

StackOpr StackOpr::sortStack()
{
    StackOpr tempStack;   
    int temp;
    
    while(!isEmpty())
    {
        temp = getTopElement();
        pop();
        
        while(!tempStack.isEmpty() && tempStack.getTopElement() < temp)
        {
           
            int top = tempStack.pop();
            push(top); 
        }
        tempStack.push(temp);
    }
    
    return tempStack;
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
    StackOpr s1(4);
    StackOpr s2;
    
    s1.push(11);
    s1.push(33);
    s1.push(22);
    s1.push(44);

    s2 = s1.sortStack();
    
    while(!s2.isEmpty())
    {
        cout <<"  " << s2.getTopElement();
        s2.pop();
    }
    return 0;
}
