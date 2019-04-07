/*
  Reverse Stack
  ● Question : Given a stack, reverse the items without creating any additional data structures. 
  ● Eg. reverse(1‑>2‑>3) = 3‑>2‑>1
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
  void reverseStack();
  
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

void StackOpr::reverseStack()
{
	int bottomPtr = 0;
	int topPtr = top;
	int mid = top % 2;
	
	while(topPtr > bottomPtr)
	{
		arr[topPtr] 	= arr[topPtr] ^ arr[bottomPtr];
		arr[bottomPtr] 	= arr[topPtr] ^ arr[bottomPtr];
		arr[topPtr]		= arr[topPtr] ^ arr[bottomPtr];
		topPtr--;
		bottomPtr++;
	}
	
	while(!isEmpty())
	{
	    cout << " " << getTopElement();
	    pop();
	}
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
    StackOpr s1(5);
    StackOpr s2;
    
    s1.push(1);
    s1.push(6);
    s1.push(3);
    s1.push(4);
    s1.push(10);

    s1.reverseStack();

    return 0;
}
