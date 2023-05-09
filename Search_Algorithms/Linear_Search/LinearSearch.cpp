#include<iostream>

int* LinearSearch(int target, int array[], int size)
{
    for(int i = 0 ; i < size ; i++) if(target == array[i]) return (array+i) ; 
}

int main()
{
    int array[] = {1 , 6 , 4, 3} ; 
    std::cout << LinearSearch(4, array , 4) << std::endl ; 
    return 0 ;
}