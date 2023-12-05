#include <stdio.h>

int main(){
  long long a,sum=0,money=1,day=1,ans=0;
  scanf("%lld",&a);
  printf("a の値は %lld\n",a);
  while(sum<a){
    sum+=money; // sum+=money⇔sum(当日の貯金額)=sum(前日の貯金額)+money(当日加算するお金);sum=50,money=32とすると、sum=sum+money=50+32=82
    money*=2;
    day++;
  }
  printf("初めて越える日は%lld日目\n",day);
  day=1;
  money=1;
  sum=0;
  while(day<31){
    sum+=money;
    money*=2;
    day++;
  }
  printf("1ヶ月後の貯金額は%lld円\n",sum);
  return 0;
}
