#include<iostream>

void swap(int& a, int& b)
{
    a = a ^ b ; 
    b = a ^ b ; 
    a = a ^ b ; 
}

void InsertionSort(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
        for(int j = i ; j > -1 ; j--)
            if(array[j] < array[j-1]) swap(array[j] , array[j-1]) ; 
            else break ; 
}

int main()
{
    int array[] = {5, 4, 3, 2, 1} ; 
    InsertionSort(array, 5) ; 
    for(auto i : array) std::cout << i << std::endl ; 
    return 0 ;
}
