#include<iostream>

void exchange(int& a, int& b)
{
    int c = a ; 
    a = b ; 
    b = c  ;
}

void InsertionSort(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
        for(int j = i ; j > -1 ; j--)
            if(array[j] < array[j-1]) exchange(array[j] , array[j-1]) ; 
            else break ; 
}

int main()
{
    int array[] = {5, 4, 3, 2, 1} ; 
    InsertionSort(array, 5) ; 
    for(auto i : array) std::cout << i << std::endl ; 
    return 0 ;
}