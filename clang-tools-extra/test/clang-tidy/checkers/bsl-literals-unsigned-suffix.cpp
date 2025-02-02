
int a = 0x42;
int b = 0X43U;
int c = 0x44L;

int d = 0x44Lu;

int e = 0x44LU;
int f = 0x44LLU;

int g = 0X44UL;

int h = 0;
int i = 0U;
int j = 0u;

int k = 0b1u;

int l = 0b1U;

int m = 1lu;

int n = 1LU;

unsigned int o = 0xffffffff;
// CHECK-MESSAGES: :[[@LINE-1]]:18: warning: unsigned hex literal does not end with 'U' [bsl-literals-unsigned-suffix]

unsigned long p = 0xffffffffffffffffL;
// CHECK-MESSAGES: :[[@LINE-1]]:19: warning: unsigned hex literal does not end with 'U' [bsl-literals-unsigned-suffix]

unsigned long long q = 0xffffffffffffffffLL;
// CHECK-MESSAGES: :[[@LINE-1]]:24: warning: unsigned hex literal does not end with 'U' [bsl-literals-unsigned-suffix]

template<typename T>
void bar(T);

template<>
void bar<unsigned long long>(unsigned long long);

template<>
void bar<long long>(long long);

static void foo()
{
  bar(0xFFFFFFFFFFFFFFFF);
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: unsigned hex literal does not end with 'U' [bsl-literals-unsigned-suffix]
}

template<unsigned short N>
struct buffer final
{
  char data0[N];
  long data1[3u];
};
