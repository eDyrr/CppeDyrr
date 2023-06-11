#include<iostream>

void swap(int& a, int& b)
{
    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ; 
}

void ShellSort(int table[], int size) 
{
    int h = 1 ;  
    while(h < size / 3) h = 3*h + 1 ; 
    while(h >= 1)
    {
        for(int i = h ; i < size ; i++)
        {
            for(int j = i ; j >= h && table[j] < table[j-h] ; j-= h) swap(table[j],table[j-h]) ; 
        }
        h /= 3 ; 
    }
}

int main()
{
    int table[] = {5, 4, 3, 2, 1, 0} ; 
    int size = sizeof(table)/sizeof(table[0]) ; 
    shellSort(table, size) ; 
    for(int i = 0 ; i < size ; i++)std::cout << table[i] << "\t" ; 
    return 0 ; 
}