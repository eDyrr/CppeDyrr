#include<iostream>

struct Node
{
    int data ; 
    Node* next ; 
    Node():data(0),next(NULL) {} ; 
    Node(int Data):data(Data),next(NULL) {} ; 
}; 

class SLL 
{
    public : 
    Node* Head ; 
 
    SLL():Head(NULL) {} ; 
    bool isEmpty() {return Head ? 0 : 1 ; }
    Node* head() { return Head ; }
    Node* last()
    {
        Node* last = Head ;
        while(last->next) last = last->next ; 
        return last ; 
    }
    void first(int Data)
    {
        Node* first = new Node(Data) ; 
        first->next = Head ; 
        Head = first ; 
    }
    void last(int Data)
    {
        Node* last = new Node(Data) ; 
        Node* temp = Head ; 
        if(isEmpty()) 
        {
            first(Data) ; 
            return ; 
        }
        while(temp->next) temp = temp->next ; 
        temp->next =  last ; 
    }
    Node* end(Node* h, int Data)
    {
        if(!h) return new Node(Data) ; 
        else h->next = end(h->next , Data) ; 
        return h ; 
    }
    void output()
    {
        Node* temp = Head ;
        while(temp) 
        {
            std::cout << temp->data << std::endl ; 
            temp = temp->next ; 
        }    
    }
    void RecursiveOutput(Node* temp)
    {
        if(!temp) return ; 
        std::cout << temp->data << std::endl ;
        RecursiveOutput(temp->next) ;
    }
    Node* search(int key)
    {
        if(!exist(key)) return Head ; 
        Node* temp = Head ; 
        while(temp->next and key != temp->data)
            temp = temp->next ; 
        return temp ; 
    }
    bool exist(int key)
    {
        Node* target = Head ; 
        while(target->next and target->data != key)
        target = target->next ; 
        return target->data == key ? 1 : 0 ; 
    }
    void after(int key, int Data)
    {
        if(!Head) return ; 
        Node* target       = search(key) ;
        Node* after        = new Node(Data) ;
              after->next  = target->next ;
              target->next = after ;
    }
    void xlast()
    {
        if(isEmpty()) return ; 
        Node* xlast = Head ; 
        Node* preLast ; 
        while(xlast->next) 
        {
            preLast = xlast ; 
            xlast = xlast->next ; 
        }
        preLast->next = NULL ; 
        delete xlast ; 
        xlast = NULL ; 
    }
    void xfirst()
    {
        if(isEmpty()) return ; 
        Node* xfirst = Head ; 
        Head = Head->next ; 
        delete xfirst ; 
        xfirst = NULL ;
    }
    void xmid(int key)
    {
        Node* xmid = Head ; 
        Node* preXmid ; 
        if(Head->data == key) 
        {
            xfirst() ; 
            return ; 
        }
        else if(last()->data == key) 
        {
            xlast() ; 
            return ; 
        }
        while(xmid->next and xmid->data != key)
        {
            preXmid = xmid ; 
            xmid = xmid->next ; 
        }
        preXmid->next = xmid->next ;
        delete xmid ; 
        xmid = NULL ; 
    }
    void reverse()
    {
        Node* current = Head ; 
        Node* previous = NULL ; 
        Node* next = NULL ; 
        while(current)
        {
            next = current->next ; 
            current->next = previous ; 
            previous = current ; 
            current = next ;
        }
        Head = previous ; 
    }
    int non_recursive_length(Node* head)
    {
        int length = 0 ; 
        while(head)
        {
            ++length ; 
            head = head->next ; 
        } 
        return length ; 
    }
    int recursive_length(Node* head)
    {
        if(!head) return 0 ; 
        return recursive_length(head->next) + 1 ; 
    }
    void destroy()
    {
        Node* target = Head ; 
        while(Head)
        {
            Head = Head->next ; 
            delete(target) ; 
            target = NULL ; 
        }
    }
};

int main()
{
    /*SLL* list1 = new SLL() ; 
    for(int i = 4 ; i > 0 ; i--) list1->first(i) ; 
    list1->last(5) ; 
    list1->end(list1->Head , 7) ; 
    list1->output() ; 
    list1->after(5,6) ; 
    list1->output() ;*/ 
    SLL* list2 = new SLL() ; 
    for(int i = 4 ; i > -1 ; i--) list2->last(i) ; 
    //list2->output() ; 
    list2->end(list2->Head ,10) ; 
    std::cout << "list 2 : " << std::endl ; 
    list2->output() ; 
    std::cout << "after deleting 2 : " << std::endl ; 
    //list2->xmid(2) ; 
    list2->output() ; 
    std::cout << "recursive_length : " << list2->non_recursive_length(list2->head()) << std::endl ; 
    list2->reverse() ; 
    list2->output() ; 
    list2->destroy() ; 
    std::cout << "after destruction : " << list2->isEmpty() << std::endl ; 
    return 0 ;
}