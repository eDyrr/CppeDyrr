#include<iostream>
#include<vector>

void exchange(int& a, int& b)
{
    int exchange = a ;
    a = b ; 
    b = exchange ; 
}

void InsertionSort(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
        for(int j = i ; j > -1 ; j--)
            if(array[j] < array[j-1]) exchange(array[j], array[j-1]) ; 
            else break ; 
}

void SelectionSort(int array[], int size)
{
    for(int i = 0 ; i < size ; i ++)
        for(int j = i+1 ; j < size ; j++)
        if(array[j] < array[i]) exchange(array[i], array[j]) ; 
}

bool check_sort(std::vector<int> t)
{
    for(int i = 0 ; i < t.size()-1 ; i++) if(t[i+1] < t[i]) return false ; 
    return true ; 
}
int max_out(std::vector<int> v)
{
    int max = v[0] ; 
    for(int i = 1 ; i < v.size() ; i++)
    if(max < v[i]) max = v[i] ; 
    return max ;
}
int longest_sequence(int array[], int size)
{
    int counter = 1 ; 
    std::vector<int> max ; 
    for(int i = 0 ; i < size-1 ; i++)
    {
        if(array[i+1] > array[i]) ++counter ; 
        else 
        {
            max.push_back(counter) ; 
            counter = 1 ; 
        }
    }
    return max_out(max) ; 
}
int main()
{
    std::cout.setf(std::ios_base::boolalpha) ; 
    int arr[5] ; 
    int j = 5 ; 
    for(int i = 0 ; i < 5 ; i++)
        arr[i] = j-- ; 
    std::cout << "before : " << std::endl ; 
    for(int i = 0 ; i < 5 ; i++) std::cout << arr[i] << " " ; 
    std::cout << "\nafter : " << std::endl ; 
    InsertionSort(arr, 5) ; 
    for(int i = 0 ; i < 5 ; i++) std::cout << arr[i] << " " ;

    std::cout << std::endl ; 

    std::vector<int> t ; 
    j = 9 ; 
    bool one = true ; 
    for(int i = 0 ; i < 10 ; i++) 
    {
        one = !one ; 
        if(one) t.push_back(i) ; 
        else t.push_back(j--) ; 
    }
    for(int i = 0 ; i < 10 ; i++) std::cout << t[i] << std::endl ; 
    std::cout << check_sort(t) << std::endl ; 
    int array[11] = { 25 , 11 , 41 , 55 , 66 , 77 , 88 , -5 , 0 , 25 , 36 } ; 
    std::cout << longest_sequence(array, 11) << std::endl ; 
    return 0 ; 
}