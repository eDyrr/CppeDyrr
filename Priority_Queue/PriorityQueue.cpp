#include<iostream>

struct Node 
{
    int data ; 
    Node* next ; 
    Node* previous ; 
    Node(int Data):data(Data),next(NULL),previous(NULL) {}
}; 

class PriorityQueue
{
    private : 
    Node* rear ; 
    Node* front ;
    int length ; 

    public : 
    PriorityQueue():rear(NULL),front(NULL),length(0) {}
    bool isEmpty() { return front ? 0 : 1 ; }
    Node* search(int key)
    {
        if(isEmpty() or key == front->data) return front ; 
        Node* tracker = front ; 
        while(tracker->next && key != tracker->data) tracker = tracker->next ;
        return tracker ; 
    }
    int size() { return length ; }
    void push(int Data)
    {
        Node* current = front ;  
        Node* newNode = new Node(Data) ; 
        if(isEmpty()) 
        {
            front = newNode ;
            return ; 
        }
        else rear->next = newNode ; 
        rear = newNode ;
        length++ ; 
        int exchange ;
        int size = this->length ; 
        while(size)
        {
            while(current->next->next)
            {
                if(!(current->data < current->next->data))
                {
                    exchange = current->data ; 
                    current->data = current->next->data ; 
                    current->next->data = exchange ; 
                }
                current = current->next ; 
            }
            --size ; 
        }
    }
    void out(Node* root)
    {
        if(!root) return ; 
        std::cout << root->data << std::endl ; 
        out(root->next) ; 
    }
    Node* Front() { return front ; }

};

int main()
{
    std::cout.setf(std::ios_base::boolalpha) ; 
    PriorityQueue* PQ = new PriorityQueue() ;  
    return 0 ;
}
