
/* Two Missing Numbers 
   ● Question : Given an array containing all the numbers from 1 to n except two, ﬁnd  the two missing numbers.  
   ● Eg. missing([4, 2, 3]) = 1, 5 
*/

#include <iostream>

using namespace std;

int one_missing(int arr[], int size)
{
    long total_xor = 0;
    long arr_xor = 0;
    
    for(int i = 1; i <= size+1; i++)
        total_xor ^= i;
        
    for(int i = 0; i < size; i++)
        arr_xor ^= arr[i];
        
    return (total_xor ^ arr_xor);
}

void two_missing(int arr[], int size, int missingElements[])
{
    long totalLeft_xor = 0, totalRight_xor = 0;
    long arrLeft_xor = 0, arrRight_xor = 0;
    int arrSum = 0;
    
    int totalSize = 0;
    totalSize = size + 2;
    
    int totalSum = totalSize * (totalSize + 1) / 2;
    
    for(int i = 0; i < size; i++)
        arrSum += arr[i];
        
    int pivot = (totalSum - arrSum) / 2;
    
    for(int i = 1; i <= pivot; i++)
        totalLeft_xor ^= i;
        
    for(int i = pivot + 1; i <= size; i++)
        totalRight_xor ^= i;
        
    for(int i = 0; i < size; i++ )
    {
        if(arr[i] <= pivot)
            arrLeft_xor ^= arr[i];
        else
            arrRight_xor ^= arr[i];        
    }
    
    missingElements[0] = arrLeft_xor ^ totalLeft_xor;
    missingElements[1] = arrRight_xor ^ totalRight_xor;
    
    cout << endl << "Two missing elements are: "<<missingElements[0] <<" " << missingElements[1];
}


int main()
{
   int arr[] = {1, 3, 4};
   int arr_len = sizeof(arr) / sizeof(arr[0]);
   int missingElements[2];
   
   cout << endl << "Misisng number:: "<<one_missing(arr, arr_len);
   
   two_missing(arr, arr_len, missingElements);
   
    return 0;
}
