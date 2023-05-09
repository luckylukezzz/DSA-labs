#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int l= 2*root +1;
   int r= 2*root +2;
   int largest;
   if (l < n && arr[l]>arr[root]){
      largest = l;
   }else{
      largest = root;
   }
   if (r < n && arr[r]>arr[largest]){
      largest = r;
   }
   if(largest != root){
      int temp= arr[root];
      arr[root]=arr[largest];
      arr[largest]=temp;
      heapify (arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for(int i = (n/ 2)-1 ; i>=0; i--){
        heapify(arr,n,i);
    }
    for(int i = n-1 ; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
   
}
  
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   cout<<"enter array length :";
   int n;
   cin >> n;
   int heap_arr[n];
   cout << "Enter array \n";
   for (int i=0; i<n; i++){
      cin >> heap_arr[i]; 
   }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   return 0;
}