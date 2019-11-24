#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void siftDown(int *numbers, int root, int bottom)
{
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void heapSort(int *numbers, int array_size) {
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}


int *bubble_sort(int *array, int array_size) {
   for (int i = 0; i < array_size - 1; i++)
   {
     for (int j = (array_size - 1); j > i; j--)
     {
       if (array[j - 1] > array[j])
       {
         int temp = array[j - 1];
         array[j - 1] = array[j];
         array[j] = temp;
       }
     }
   }
   return (array);
}

int main() {
//    struct timespec start, end;
    
    int n;
    
    printf("Введите количество элементов:\n");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
//        printf("Введите %d элемент > ",i+1);
//        scanf("%d",&arr[i]);
        arr[i]=rand()%100000;
    }

    int s;
    printf("Какой сортировкой вы хотите отсортировать элементы?\nЕсли пузырьковой, то введите 1, если пирамидальной, то введите 2\n");
    scanf("%d",&s);
//    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    if (s==1) {
        bubble_sort(arr, n); //пузырьковая
    } else {
        heapSort(arr, n); //пирамидальная
    }
    
//    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
//    printf("\nTime taken: %lf sec.\n",
//    end.tv_sec-start.tv_sec
//    + 0.000000001*(end.tv_nsec-start.tv_nsec));
}
