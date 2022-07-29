//
// Created by Administrator on 2022/6/29 0029.
//
#include "head/head.h"
#include <stdio.h>
unsigned int Factorial(unsigned int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * Factorial(n - 1);
  }
}
unsigned int FactorialByIteration(unsigned int n) {
  unsigned int result = 1;
  for (unsigned int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}
int main() {
  unsigned int i = Factorial(14);
  printf("%d\n", i);
  unsigned int result = FactorialByIteration(14);
  printf("%d", result);
}
