// ICPC 2014 国内予選A
// http://icpc.iisf.or.jp/past-icpc/domestic2014/#section_A

#include <stdio.h>

int main(void){
  int x, y, s;
  int p1, p2; //税抜
  int s1 = 0, s2 = 0; //税込
  int max = 0;        //税込価格の最大値

  while(1){
    scanf("%d %d %d",&x,&y,&s);
    p1 = 0;

    // 0 0 0 のとき抜ける
    if(!x && !y && !s){
      break;
    }

    // 税抜価格ごとに調べる
    while(p1<=p2){
      p1++;
      p2 = s - p1;
      s1 = p1 * (100+x) / 100;
      s2 = p2 * (100+x) / 100;
     
      // p2確定
      while(s - s1 - s2 && p1<p2){
	p2--;
	s2 = p2 * (100+x) / 100;
      }

      // 変更前の税込価格の合計が一致してるとき
      if(s == s1 + s2){
      
	// 変更後の税込価格
	s1 = p1 * (100+y) / 100;
	s2 = p2 * (100+y) / 100;
      
	// 最大値更新
	if(max < s1+s2){
	  max = s1+s2;
	}
      }
    }

    printf("%d\n",max);
    max = 0;

  }

  return 0;

}
