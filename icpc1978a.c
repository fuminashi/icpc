#include <stdio.h>
#include <stdlib.h>

// http://www.deqnotes.net/acmicpc/1978/ja
// このプログラムはうごきません

int main(){
  int n = 0;
  int j, r, p = 0, c;
  int* a, b;
  scanf("%d %d",&n,&r);

  scanf("%d %d",&p,&c);
  while(p && c){

    a = (int*)calloc(n,sizeof(int));

    for(j = 0; j<n; j++)
      a+j = j;
  
    for(r; r>0; r--){
      
      b = (int*)calloc(p,sizeof(int));
      for(j = 0; j<p; j++){
	b[j] = a[j];
      }
      c++;
      for(j = 0; j<c; j++){
	a[j] = a[p+j];
      }
      c--;
      for(j = c; j<c+p; j++){
	a[j] = b[j];
      }
     
      scanf("%d %d",&p,&c); 
    }

  scanf("%d %d",&n,&r);
  }

  printf("%d\n",r);
  return 0;
}
