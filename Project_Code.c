#include<stdlib.h>
#include<stdio.h>
#define MAX 100000

// Merge Function

void merge(int arr[], int l, int m, int r, int sum)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
   	 L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
   	 R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
   	 if(L[i] + R[j] == sum)
   	 {
   		 printf("Pair of given sum %d are (%d + %d)\n",sum,L[i],R[j]);
   	 }
   	 if (L[i] <= R[j])
   	 {
   		 arr[k] = L[i];
   		 i++;
   	 }
   	 else
   	 {
   		 arr[k] = R[j];
   		 j++;
   	 }
    k++;
    }
    while (i < n1)
    {
   	 arr[k] = L[i];
   	 i++;
   	 k++;
    }
    while (j < n2)
    {
   	 arr[k] = R[j];
   	 j++;
   	 k++;
    }
}

void mergeSort(int arr[], int l, int r,int sum)
{
    if (l < r)
    {
// Finding mid element
    int m = l+(r-l)/2;
// Recursively sorting both the halves
    mergeSort(arr, l, m, sum);
    mergeSort(arr, m+1, r, sum);
 
// Merge the array
    merge(arr, l, m, r,sum);
    }
}


void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[MAX];
    int arr_size,sum;
    printf("Please enter the size of array:");
    scanf("%d",&arr_size);
    printf("Enter value:\n");
    for(int i=0;i<arr_size;i++)
    {
   	 printf("Array[%d]:",i);
   	 scanf("%d",&arr[i]);
    }
    printf("Enter sum to find the pair:");
    scanf("%d",&sum);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1,sum);

    return 0;
}