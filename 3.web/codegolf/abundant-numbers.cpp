#include<cstdio>
int main(){for(int i=1;i<201;i++){int s=0;for(int j=2;j<i;j++)i%j?:s+=j;if(s>i)printf("%d\n",i);}}
