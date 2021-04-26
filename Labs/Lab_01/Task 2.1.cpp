#include <bits/stdc++.h>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* create temp arrays */
    int leftTemp[n1], rightTemp[n2];

    /* Copy data to temp arrays */
    for (i = 0; i < n1; i++)
        leftTemp[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightTemp[j] = arr[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..right]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (leftTemp[i] <= rightTemp[j]) {
            arr[k] = leftTemp[i];
            i++;
        }
        else {
            arr[k] = rightTemp[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of leftTemp[], if there
       are any */
    while (i < n1) {
        arr[k] = leftTemp[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of rightTemp[], if there
       are any */
    while (j < n2) {
        arr[k] = rightTemp[j];
        j++;
        k++;
    }
}

/* left is for left index and right is for right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        //calculates mid
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void printMedian(int *arr, int size) {

    int median;
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    //printf("\n%d",size);
    if(size % 2 != 0)
    {
        median = arr[size / 2];
    }
    else
    {
        median = (arr[size / 2] + arr[size / 2 - 1]) / 2;
    }
    printf("%d\n", median);
}

int main() {
    int arr[1000];
    int i = 0;
    while (1) {
        scanf("%d", &arr[i++]);
        mergeSort(arr, 0, i);   //i = size of current array
        printMedian(arr, i);
    }
}
