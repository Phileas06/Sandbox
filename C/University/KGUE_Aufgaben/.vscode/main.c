#include <stdio.h>
int i, a;
/* void f1(){
  i = i + 10;
  printf("i in f1=%d\n", i);
} */

void f2() {
  int i = 2;
  i = i + 10;
  printf("i in f2=%d\n", i);
}
void f3(int i) {
  i = i + 30;
  printf("i in f3=%d\n", i);
}
void f4(int* i) {
  *i = *i +10;
  printf("i in f4 zeigt auf den Wert %d\n", *i);
}
int main() {
  int a=5;
  printf("i in main=%d\n", i);
  /* f1(); */
  printf("i in main=%d\n", i);
  f2();
  printf("i in main=%d\n", i);
  f3(i);
  printf("i in main=%d\n", i);
  f4(&i);
  printf("i in main=%d\n", i);
  return 0;
}