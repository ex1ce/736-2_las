#include <stdio.h>

void main()
{
int n = 0;
int a = 0;
int b = 0;
scanf("%d",&n);
if (n>0) scanf("%d",&a);
n = n - 1;
for (int i = 1; i<=n; i++){
scanf("%d",&b);
if (b < a) a = b;
};
printf("%d\n", a);
}
