#include <stdio.h> 
#include <stdlib.h> 
void sortirovkashell(int array[], int num) 
{ 
int i, j, k, tmp; 
for (i = num / 2; i > 0; i = i / 2) 
{ 
for (j = i; j < num; j++) 
{ 
for(k = j - i; k >= 0; k = k - i) 
{ 
if (array[k+i] >= array[k]) 
break; 
else 
{ 
tmp = array[k]; 
array[k] = array[k+i]; 
array[k+i] = tmp; 
} 
} 
} 
} 
} 
int main() 
{ 
int array[30]; 
int k, num; 
scanf("%d", &num); 
printf("%d ", num); 

for (k = 0 ; k < num; k++) 
{ 
scanf("%d", &array[k]); 
} 
sortirovkashell(array, num); 
for (k = 0; k < num; k++) 
printf("%d ", array[k]); 
return 0; 
}
