
#include <ctime>
#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
   
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main(){

    clock_t start;
    clock_t end;

    int arrLen[]={5000,7000,9000,15000,20000};
    for (int len:arrLen) {
        start = clock();

        int my_array[len];
        srand(time(0)); 

        for (int i = 0; i < len; i++) {
            my_array[i] = rand() % 100 + 1; 
        }



        quickSort(my_array,0,len-1);
        end = clock();

        double timetakenSort = (end - start) / (double) CLOCKS_PER_SEC;
        cout << "total elements in array: " << len << endl;
        cout << "time taken is: " << fixed << timetakenSort*1000  << "ms" << endl << endl;
    }
}