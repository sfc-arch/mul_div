#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define	LOGIN	"fumi"

long long count;
int loop;

#define	LOOP_SEC	(2)

static __inline int mul(int x,int y) {
//
// 以下を削除してここに乗算のロジックを入れてください。x=32bit , y=32bit, result=64bit
//
	int cnt=0, sum=0;
	while (cnt<y) {
		sum+=x;
		cnt++;
	}
	return sum;
}

static __inline int div(int x,int y) {
//
// 以下を削除してここに除算のロジックを入れてください。x=32bit , y=32bit, result=32bit
//
	int cnt = 0;
	while(x>=y) {
		x-=y;
		cnt++;
	}
	return cnt;
}

void alarm_mul(int signum){
	printf("MUL: %lld K instructions/sec\n", count/LOOP_SEC/1000);
	printf("MUL: %lld  instructions/sec\n", count/LOOP_SEC);
	loop = 0;
}

void alarm_div(int signum){
	printf("DIV: %lld K instructions/sec\n", count/LOOP_SEC/1000);
	printf("DIV: %lld instructions/sec\n", count/LOOP_SEC);
	loop = 0;
}

int main() {
	int x,y;


	printf("Start (%s program)\n", LOGIN);


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
