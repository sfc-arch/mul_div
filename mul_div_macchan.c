#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define	LOGIN	"macchan"

long long count;
int loop;

#define	LOOP_SEC	(2)

static __inline int mul(int x, int y) {
//
// 以下を削除してここに乗算のロジックを入れてください。x=32bit , y=32bit, result=64bit
//
#ifdef NO
  	return x*y;
#endif
#ifdef NO
	int ans, i;
	ans = 0;
	for (i=0; i< 16; ++i) {
		if (y & 1)
			ans += x;
		y = y >> 1;
		x = x << 1;
	}
	return ans;
#endif
#ifndef NO
//	return	((x & 32768) ? (y << 15) : 0) +  
//	return	((x & 16384) ? (y << 14) : 0) +  
//	return	((x &  8192) ? (y << 13) : 0) +  
//	return	((x &  4096) ? (y << 12) : 0) +  
  	return	((x &  2048) ? (y << 11) : 0) +  
		((x &  1024) ? (y << 10) : 0) +  
		((x &   512) ? (y <<  9) : 0) +  
		((x &   256) ? (y <<  8) : 0) +  
		((x &   128) ? (y <<  7) : 0) +  
		((x &	64) ? (y <<  6) : 0) +  
		((x &	32) ? (y <<  5) : 0) +  
		((x &	16) ? (y <<  4) : 0) +  
		((x &	 8) ? (y <<  3) : 0) +  
		((x &	 4) ? (y <<  2) : 0) +  
		((x &	 2) ? (y <<  1) : 0) +  
	 	((x &	 1) ?  y		: 0);
#endif
}

static __inline int msb(int a)
{
#ifdef NO
	int c = 0;
	while (a != 0) {
		a >>= 1;
		++c;
	}
	return c;
#endif
#ifndef NO
	return	(a & 0x8000000) ? 27 : 
	        (a & 0x4000000) ? 26 : 
		(a & 0x2000000) ? 25 :
		(a & 0x1000000) ? 24 :
		(a & 0x0800000) ? 23 :
		(a & 0x0400000) ? 22 :
		(a & 0x0200000) ? 21 :
		(a & 0x0100000) ? 20 :
		(a & 0x0080000) ? 19 :
		(a & 0x0040000) ? 18 :
		(a & 0x0020000) ? 17 :
		(a & 0x0010000) ? 16 :
		(a & 0x0008000) ? 15 :
		(a & 0x0004000) ? 14 :
		(a & 0x0002000) ? 13 :
		(a & 0x0001000) ? 12 :
		(a & 0x0000800) ? 11 :
		(a & 0x0000400) ? 10 :
		(a & 0x0000200) ?  9 :
		(a & 0x0000100) ?  8 :
		(a & 0x0000080) ?  7 :
		(a & 0x0000040) ?  6 :
		(a & 0x0000020) ?  5 :
		(a & 0x0000010) ?  4 :
		(a & 0x0000008) ?  3 :
		(a & 0x0000004) ?  2 :
		(a & 0x0000002) ?  1 :
		(a & 0x0000001) ?  0  : 0;
#endif
}



static __inline int div(int x,int y) {
//
// 以下を削除してここに除算のロジックを入れてください。x=32bit , y=32bit, result=32bit
//
#ifdef NO
	return x/y;
#endif
	int ans = 0, d;
	int c = msb(x) - msb(y);
	while ( c >= 0 ) {
		d = x - (y << c);
		if (d >= 0) {
			x = d;
			ans |= (1 << c);
		}
		--c;
	}
	return ans;
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
	//for (x=0x0fffffff; loop ; --x) {
	for (x=0x0ffff; loop ; --x) {
		for (y=1; y<0xffff; ++y) {
			if (div(x,y) != x/y) {
				printf("DIV: %X/%X=Calculation results are incorrect. results=%d, expected=%d\n", x, y, div(x,y), x/y);
//				return(-1);
			}
			++count;
		}
	}

	return 0;

}
