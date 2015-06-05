// ICPC 2007 国内予選A
// http://icpc.iisf.or.jp/past-icpc/domestic2007/A_ja.html

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i, j, h, tmp = 0;
  int n[20] = {};
  int sum[20] = {};
  int* s;
  s = &sum[0];

  j = 0;
  while(1){
    scanf("%d",&n[j]);
    if(!n[j]){
      //exit(EXIT_SUCCESS);
      break;
    }else{
      int p[n[j]];
      *s = 0;
      for(i=0; i<n[j]; i++){
	scanf("%d", &p[i]);
	*s += p[i];
      }
      
      // バブルソート
      for(i=1; i<n[j]; i++){
	for(h=1; h<n[j]-i+1; h++){
	  if(p[h-1]<p[h]){
	    tmp = p[h-1];
	    p[h-1] = p[h];
	    p[h] = tmp;
	  }
	}
      }

      /*printf("p: ");
      for(h=0; h<n[j]; h++) 
	printf("%d ",p[h]);
	printf(" \n");*/

      *s = *s - p[0] - p[n[j]-1];
      // printf("sum: %d\n",*s);
      s++;
    }
    j++;
  }

  for(i=0; i<j; i++){
    printf("%d\n",sum[i]/(n[i]-2));
  }  
  return 0;
}
