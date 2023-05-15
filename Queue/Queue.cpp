#include<iostream>

struct Node
{
    int data ;
    Node* next ; 
    Node(int Data):data(Data),next(NULL) {}
};

class Queue
{
    private :
    Node* front ; 
    Node* rear ; 
    int length ; 

    public : 
    Queue():front(NULL),rear(NULL),length(0) {}
    bool isEmpty() { return rear ? 0 : 1 ; }
    void push(int Data) 
    {
        Node* last = new Node(Data) ; 
        if(isEmpty()) front = last ; 
        else rear->next = last ; 
        rear = last ; 
        length++ ;
    }
    void pop()
    {
        Node* done = front ; 
        front = front->next ; 
        delete(done) ; 
        done = NULL ; 
        length-- ; 
    }
    void out()
    {
        Node* current = front ; 
        while(current)
        {
            std::cout << current->data << std::endl ; 
            current = current->next ; 
        }
    }
    int size() { return length ; }
    Node* last() { return rear ; }
    Node* first() { return front ; } 
};

int main()
{
    Queue* Q = new Queue() ; 
    std::cout << "empty : " << Q->isEmpty() << std::endl ; 
    for(int i = 0 ; i < 3 ; i++) Q->push(i) ; 
    std::cout << "before : " << std::endl ; 
    Q->out() ; 
    std::cout << "size : " << Q->size() << std::endl ; 
    Q->pop() ; 
    std::cout << "after : " << std::endl ; 
    Q->out() ; 
    /*std::cout << "size : " << Q->size() << std::endl ; 
    std::cout << "#######################" << std::endl ; 
    std::cout << Q->first()->data << std::endl ; 
    std::cout << Q->last()->data << std::endl ; */
    return 0 ;
}