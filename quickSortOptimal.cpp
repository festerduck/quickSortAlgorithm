#include <cstdlib>
#include <ctime>
#include <iostream>
const int MAX_SIZE = 10;
using namespace std;
template <class dataType>

void swap(dataType array[], int first, int second){
  dataType temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

template <class dataType>
int medianOfThree(dataType array, int left, int right){
    int center = (left + right) / 2;
    if(array[left] > array[right])
      swap(array, left, right);
    if(array[left] > array[center])
      swap(array, left, center);
    if(array[center] > array[right])
      swap(array, center, right);
    swap(array, center, right - 1);
    return center;
}
template <class dataType>

void quickSort(dataType array[], int left, int right){
  if(left < right){
   int pivotIndex =  medianOfThree(array, left, right);
    dataType pivot = array[pivotIndex];
    int i = left;
    int j = right - 1;
    while (1) {
      while (array[++i] < pivot) {}
      while(array[--j] > pivot) {}
      if(i < j){
        swap(array, i, j);
      }
      else {
        break;
      }
    }
    swap(array, i, right - 1);
    quickSort(array, left, i - 1);
    quickSort(array, i + 1, right);
  }
}
template <class dataType>
void printArray(dataType array[]){
  for(int i = 0; i < MAX_SIZE; i++){
    cout << array[i] << endl;
  }
}

int main(){
  srand(time(NULL));
 int array[MAX_SIZE];
 for(int i = 0; i < MAX_SIZE; i++){
  array[i] = rand() % 10001;
 }
 quickSort(array, 0, MAX_SIZE - 1);
 printArray(array);
  return 0;
}
