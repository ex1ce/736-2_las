#include <stdio.h> 
#include <stdlib.h> 
void siftDown(int *numbers, int root, int bottom) 
{ 
int maxChild; 
int done = 0; 
while ((root * 2 <= bottom) && (!done)) 
{ 
if (root * 2 == bottom) 
maxChild = root * 2; 
else if(numbers[root * 2] > numbers[root * 2 + 1]) 
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
void heapSort(int *numbers, int array_size) 
{ 
for (int i = (array_size / 2) - 1; i >= 0; i--) 
siftDown(numbers, i, array_size); 
for (int i = array_size - 1; i >= 1; i--) 
{ 
int temp = numbers[0]; 
numbers[0] = numbers[i]; 
numbers[i] = temp; 
siftDown(numbers, 0, i - 1); 
} 
} 
int main() 
{ 
int n; 
int* array; 
scanf("%d", &n); 
array = (int *)malloc(n * sizeof(int)); 
for (int i = 0; i < n; i++) 
scanf("%d", &array[i]); 
printf("\n"); 
heapSort(array,n); 
for (int i = 0; i < n; i++) 
{ 
printf("%d ", array[i]); 
} 
printf("\n"); 
free(array); 
return 0; 
}
