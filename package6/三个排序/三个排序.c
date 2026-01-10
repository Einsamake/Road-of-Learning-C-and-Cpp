#include <stdio.h>
void bubbleSort(int arr[], int n);

void selectionSort(int arr[], int n);

void insertionSort(int arr[], int n);

int main( ){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
}
/*
6
7 -3 43 0 1 23
*/
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(arr[j]<arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void insertionSort(int arr[], int n) {
    for(int i=1,j;i<n;i++) {
        int temp = arr[i];
        for(j=i-1;j>=0&&temp<arr[j];j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}