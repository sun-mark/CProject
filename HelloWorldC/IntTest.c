#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main() {
  char command = 'y';
  command = getchar();
  printf("%c\n", command);
  _Bool boolean = true;
  bool b = false;
  short s = 32767 + 1;
  short int si = 1;
  int i = 1;
  int long il = 1;
  long l = 1;
  long long ll = 32767;
  int x = 2;
  x = x * 2, x = x + 3;
  unsigned short us = 32767 + 1;
  printf("short %d\n", sizeof(s));
  printf("short int %d\n", sizeof(si));
  printf("int  %d\n", sizeof(i));
  printf("int long %d\n", sizeof(il));
  printf("long  %d\n", sizeof(l));
  printf("long long %d\n", sizeof(ll));
  printf("unsigned short %d\n", us);
  printf(" short %d\n", s);
  printf(" short min  %d\n max %d\n", SHRT_MIN, SHRT_MAX);
  printf(" short min  %d\n max %d\n", SHRT_MIN, SHRT_MAX);
  printf("%d\n", x);
  return 0;
}
