#include <stdio.h>
void out(int a,int b){
  int mid;
  int array[b][a];
  for(int i=b;i>=1;i--){
    for(int j=a;j>=1;j--){
      mid=1;
      for(int k=i;k>=1;k--){
        mid*=j;
      }
      array[i-1][j-1]=mid;
    }
  }
  for(int i=b-1;i>=0;i--){
    for(int j=a-1;j>=0;j--){
      printf("%4d  ",array[i][j]);
    }
    printf("\n");
  }
};


int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  printf("a の値は %d\n",a);
  printf("b の値は %d\n",b);
  out(a,b);
  return 0;
}
