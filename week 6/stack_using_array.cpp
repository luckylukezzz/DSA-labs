#include <iostream>
#include <ctime> 
using namespace std;

const int maxVal = 30;

class Stack {
    
    private:
        int top;
        int arr[maxVal];
    public:
        
        Stack() {
            top = -1;
        }
        void push(int data) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            arr[top] = data;
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int value = arr[top];
            top--;
            return value;
        }
        bool isEmpty() {
            return top == -1;
        }
        bool isFull() {
            return top == maxVal - 1;
        }
        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    clock_t start;
    clock_t end;
    start = clock();

    Stack stack1;
    stack1.push(8);
    stack1.push(10);
    stack1.push(5);
    stack1.push(11);
    stack1.push(15);
    stack1.push(23);
    stack1.push(6);
    stack1.push(18);
    stack1.push(20);
    stack1.push(17);
    stack1.display();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.push(1);
    stack1.display();

    end = clock();
    double timetaken = (end - start) / (double)CLOCKS_PER_SEC;
    cout << "time taken is: " << fixed << timetaken*1000<<"ms" << endl<<endl;
}