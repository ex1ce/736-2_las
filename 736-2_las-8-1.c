#include <stdio.h> 
#include <stdlib.h> 
void hoar(int f, int l, int array[]) 
{ 
int i = f; 
int j = l; 
double tmp; 
int x = array[(f+l)/2]; 
while(i <= j) 
{ 
while (array[i] < x) 
i++; 
while (array[j] > x) 
j--; 
if (i <= j) 
{ 
if (i < j) 
{ 
tmp=array[i]; 
array[i]=array[j]; 
array[j]=tmp; 
} 
i++; 
j--; 
} 
} 
if (i < l) 
hoar(i, l, array); 
if (f < j) 
hoar(f, j, array); 
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
hoar(0,n-1, array); 
for (int i = 0; i < n; i++) 
{ printf("%d ", array[i]); 
} 
printf("\n"); 
free(array); 
return 0; 
}
