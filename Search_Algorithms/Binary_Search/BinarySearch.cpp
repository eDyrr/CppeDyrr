#include<iostream>

int BinarySearch(int target, int array[], int size) 
{
    int low = 0 ; 
    int high = size-1 ; 
    while (low <= high) 
    {
        int mid = low + (high - low) / 2 ;
        if (array[mid] == target) return mid ;
        if (array[mid] < target) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ; 
    int size = sizeof(array)/sizeof(array[0]) ; 
    std::cout << "size : " << size << std::endl ; 
    std::cout << BinarySearch(1, array, size) << std::endl ; 
    return 0 ; 
}
