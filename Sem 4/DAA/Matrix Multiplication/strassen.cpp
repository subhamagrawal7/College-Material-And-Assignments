#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start, end;
double cpu_time_used;
int main(){
  clock_t start, end;
  double t;
  int a[400][400], b[400][400], c[400][400], i, j,k,m,n;
  printf("Enter number of rows\n");
  scanf("%d",&m);
  printf("Enter number of colums\n");
  scanf("%d",&n);
  printf("\nEnter elements of first matrix: ");
  for(i = 0;i < m; i++){
      for(j = 0;j < n; j++){
           scanf("%d", &a[i][j]);
    }
}
  printf("Enter elements of second matrix: ");
  for(i = 0; i < m; i++){
      for(j = 0;j < n; j++){
           scanf("%d", &b[i][j]);
    }
}
  start = clock();
  for(i=0;i<m;i++)    
 {    
 for(j=0;j<n;j++)    
 {    
  c[i][j]=0;    
  for(k=0;k<n;k++)    
  {    
  c[i][j]+=a[i][k]*b[k][j];    
  }    
 }    
}    
  end = clock();
 t = ((double)(end - start)) / CLOCKS_PER_SEC; 
  printf("Time Taken: %.9f",t);
  return 0;
}
