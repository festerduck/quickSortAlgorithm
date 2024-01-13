#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
int array[MAX_SIZE];


template <class dataType>
void swap(dataType array[], int first, int second){
  dataType temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

template <class dataType>
int partition(dataType array[], int first, int last){
  dataType pivot;

  int smallIndex, index;
  swap(array, first, (first + last) / 2); //Choosing the middle of the array to be the pivot and Swapping the pivot with the first
  
  pivot = array[first]; //Setting the first element of the array to be the pivot since it has been swapped with the first element
  smallIndex = first; //Small Index will be selected the first index
  for(index = first + 1; index <= last; index++)//Iterating the array starting from the second element as the first element is pivot
  {
    if(array[index] < pivot){ //Checking whether the element is smaller than pivot
      smallIndex++;
      swap(array, smallIndex, index);
    }
  }
  swap(array, first, smallIndex); //Setting the pivot to the original position of it
  return smallIndex;
}

template <class dataType>
void quickSort(dataType array[], int first, int last){
  if(first < last){
    int pivot = partition(array, first, last);
    quickSort(array, first, pivot - 1);
    quickSort(array, pivot + 1, last);
  }
}
template <class dataType>
void printArray(dataType array[], int size){
  for(int i = 0; i < size; i++){
    if(i < size - 1)
    cout << array[i] << ",";
    else
      cout << array[i] << endl;
  }
}

int main(){
  for(int i = 0; i < MAX_SIZE; i++){
    array[i] = (rand() % 500);
  }
  quickSort(array, 0, MAX_SIZE - 1);
  printArray(array, MAX_SIZE);
  return 0;
}
