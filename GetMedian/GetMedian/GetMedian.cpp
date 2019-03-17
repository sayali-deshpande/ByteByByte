// GetMedian.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

double getMedian(int a[], int start_a, int size)
{
	// if array is of even length
	if(size % 2 == 0)
		return ((double)a[start_a + size/2 - 1] + (double)a[start_a + size / 2]) / 2.0f;
	return ((double)a[start_a + size / 2]); //if array is of odd length
}

double median(int a[], int start_a, int end_a, int b[], int start_b, int end_b)
{
	int size_a = end_a - start_a + 1;
	int size_b = end_b - start_b + 1;

	if(size_a == 1)
		return (a[start_a] + b[start_b] / 2.0f);
	if(size_a == 2)
		return ((MAX(a[start_a], b[start_b]) + MIN(a[end_a] , b[end_b])) / 2.0f);

	double med1 = getMedian(a, start_a, size_a);
	double med2 = getMedian(b, start_b, size_b);

	if(med1 > med2)
		return median(a, start_a, start_a + size_a /2,
		       b, start_b + (size_b -1) / 2, end_b);
	return median(a, start_a + (size_a -1) / 2, end_a,
		    b, start_b, start_b + size_b /2 );
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {0, 0, 0, 0, 10, 10};

	int len_a = sizeof(arr1) / sizeof(arr1[0]);
	int len_b = sizeof(arr2) / sizeof(arr2[0]);

	if(len_a == 0 || len_b == 0)
		return -1;
	if(len_a != len_b)
		return -1;

	double med = median(arr1, 0, len_a - 1,
						   arr2, 0, len_b - 1);

	cout<<endl<<"Median :: "<< med;
	return 0;

}
