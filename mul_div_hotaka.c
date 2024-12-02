#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define	LOGIN	"hotaka"

long long count;
int loop;

#define	LOOP_SEC	(2)

static __inline int mul(int x,int y) {
    int ans = 0;

    while (y) {
        // 1. 乗数乗数の最下位ビットが1の場合のみ積レジスタに被乗数を加算
        ans += -(y & 1) & x;
        // 2. 被乗数を左シフト
        x <<= 1;
        // 3. 乗数を右シフト
        y >>= 1;
    }

    return ans;
}

static __inline int div(int x,int y) {
    int q = 0; // 商
    int r = 0; // 剰余

    for (int i = 31; i >= 0; i--) {
        r = (r << 1) | ((x >> i) & 1); // 剰余を1ビット左シフトし、被除数のiビット目を加算
        if (r >= y) {
            r -= y;        // 剰余から除数を引く
            q |= (1 << i); // 商に1を立てる
        }
    }

    return q;
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
