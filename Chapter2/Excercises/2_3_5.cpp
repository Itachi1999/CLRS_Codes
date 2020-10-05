//using n = 5 as my convenience 
//Binary Search 
#include<iostream>

int binarySearch(int *A, int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if (key < A[mid])
        {
            return binarySearch(A, low, mid - 1, key);
        }
        else if (key > A[mid])
        {
            return binarySearch(A, mid + 1, high, key);
        }
        else
            return mid;
    }

    else 
        return -1;
}

int main()
{
    int A[5] = {0}, key = 0, index = 0;

    std::cout << "The array which to be search: ";
    for(int i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }

    std::cout << "The key to be searched: ";
    std::cin >> key;

    index = binarySearch(A, 0, 4, key);
    (index >= 0) ? std::cout << "It is found at " << index : std::cout << "Not found";
    std::cout << std::endl;

    return 0;
}