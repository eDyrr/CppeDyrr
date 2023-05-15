#include<iostream>
#include<vector>

class PQ 
{
    private :
    std::vector<int> data ; 

    public :
    bool isEmpty() { return data.empty() ? 1 : 0 ; } 
    int front() { return data.front() ; }
    int rear() { return data.back() ; }
    int size() { return data.size() ; }
    void pop() { data.erase(data.begin()) ; }
    void add(int Data) 
    {
        data.push_back(Data) ; 
        int exchange ; 
        for(int i = 0 ; i < data.size() ; i++)
            for(int j = 0 ; j < data.size() ; j++)
                if(data[i] < data[j])
                {
                         exchange = data[i] ;
                    data[i]       = data[j] ;
                    data[j]       = exchange ;
                }
    }
    
    void output() 
    {
        for(int i = 0 ; i < data.size() ; i++)
            std::cout << data[i] << std::endl ; 
    }
};


int main()
{
    PQ* pq = new PQ() ; 
    std::cout << "empty ? : " << pq->isEmpty() << std::endl ; 
    pq->add(3) ;
    pq->add(1) ; 
    pq->add(2) ; 
    std::cout << "after adding 1, 2, 3 : " << std::endl ; 
    pq->output() ; 
    pq->pop() ; 
    std::cout << "after our first pop : " << std::endl ; 
    pq->output() ; 
    pq->add(4) ; 
    std::cout << "after adding a 4 : " << std::endl ; 
    pq->output() ; 
    std::cout << "empty ? : " << pq->isEmpty() << std::endl ; 
    //pq->front() = 5 ;
    std::cout << "data @ @0 : " << pq->front() << std::endl ; 
    std::cout << "data @ @last : " << pq->rear() << std::endl ; 
    std::cout << "after modifying : " << std::endl ; 
    pq->output() ; 
    return 0 ;
}