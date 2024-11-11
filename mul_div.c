#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define	LOGIN	"kota"

long long count;
int loop;

#define	LOOP_SEC	(10)

static __inline int mul(int x, int y) {
    int r = 0;
    if (x & 1) r += y;
    if (x & 2) r += (y << 1);
    if (x & 4) r += (y << 2);
    if (x & 8) r += (y << 3);
    if (x & 16) r += (y << 4);
    if (x & 32) r += (y << 5);
    if (x & 64) r += (y << 6);
    if (x & 128) r += (y << 7);
    if (x & 256) r += (y << 8);
    if (x & 512) r += (y << 9);
    if (x & 1024) r += (y << 10);
    if (x & 2048) r += (y << 11);
    if (x & 4096) r += (y << 12);
    if (x & 8192) r += (y << 13);
    if (x & 16384) r += (y << 14);
    if (x & 32768) r += (y << 15);
    if (x & 65536) r += (y << 16);
    if (x & 131072) r += (y << 17);
    if (x & 262144) r += (y << 18);
    if (x & 524288) r += (y << 19);
    if (x & 1048576) r += (y << 20);
    if (x & 2097152) r += (y << 21);
    if (x & 4194304) r += (y << 22);
    if (x & 8388608) r += (y << 23);
    if (x & 16777216) r += (y << 24);
    if (x & 33554432) r += (y << 25);
    if (x & 67108864) r += (y << 26);
    if (x & 134217728) r += (y << 27);
    if (x & 268435456) r += (y << 28);
    if (x & 536870912) r += (y << 29);
    if (x & 1073741824) r += (y << 30);
    if (x & 2147483648) r -= (y << 31);
    return r;
}

static __inline int div(int x, int y) {
    return x/y;
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
