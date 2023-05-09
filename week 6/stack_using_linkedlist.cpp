#include<iostream>
#include <ctime> 
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head = NULL;
    }
    void push(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    int pop(){
        if(head == NULL){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        int value = temp->data;
        delete temp;
        return value;
    }
    bool isEmpty(){
        return head == NULL;
    }
    
    int stackTop(){
        if(head == NULL){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return head->data;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
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