#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define	LOGIN	"junpei"

long long count;
int loop;

#define	LOOP_SEC	(2)

static __inline int mul(int x,int y) {
//
// 以下を削除してここに乗算のロジックを入れてください。x=32bit , y=32bit, result=64bit
//
	uint64_t result=0;

	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;
	if(y&1)result+=x;y>>=1;x<<=1;if(y==0)return result;

	return result;
}

static __inline int div(int x,int y) {
//
// 以下を削除してここに除算のロジックを入れてください。x=32bit , y=32bit, result=32bit
	
	int32_t result = 0;
	int32_t n = 1;

	while (y<=x) {//yがxより大きくなるまでyを左シフト
		y <<= 1;
		n <<= 1;
	}
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	y>>=1;n>>=1; if(x>=y){x-=y;result|=n;} if(1>=n)return result;
	return result;
}

void alarm_mul(int signum){
	printf("MUL: %lld K instructions/sec\n", count/LOOP_SEC/1000);
	loop = 0;
}

void alarm_div(int signum){
	printf("DIV: %lld K instructions/sec\n", count/LOOP_SEC/1000);
	loop = 0;
}

int main() {
	int x,y;


	printf("Start (%s program)\n", LOGIN);
	printf("LOOP_SEC = %d \n",LOOP_SEC);

	// Benchmark MUL
	count = 0;
	loop = 1;
	signal(SIGALRM, alarm_mul);
	alarm(LOOP_SEC);
	for (x=1; loop ; ++x) {
		for (y=1; y<0xffff; ++y) {
			if (mul(x,y) != x*y) {
				printf("MUL: Calculation results are incorrect. results=%d, expected=%d\n", mul(x,y), x*y);
				return(-1);
			}
			++count;
		}
	}

	// Benchmark DIV
	count = 0;
	loop = 1;
	signal(SIGALRM, alarm_div);
	alarm(LOOP_SEC);
	for (x=0x0fffffff; loop ; --x) {
		for (y=1; y<0xffff; ++y) {
			if (div(x,y) != x/y) {
				printf("DIV: Calculation results are incorrect. results=%d, expected=%d\n", div(x,y), x/y);
				return(-1);
			}
			++count;
		}
	}

	return 0;

}
