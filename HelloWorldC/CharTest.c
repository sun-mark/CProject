#include <stdio.h>

int main() {

  char a = '1';
  char b = 'b';
  //C95 unicode
  wchar_t zhong = L'жа';
  wchar_t zhong_unicode = L'\u4e2d';
  printf(" char a %d\n", a);
  printf(" char a %c\n", a);
  printf(" char b %d\n", b);
  printf(" char b %c\n", b);
  printf(" wchar_t zhong %d\n", zhong);
  printf(" wchar_t zhong_unicode %d\n", zhong_unicode);
  return 0;
}
