#include <stdio.h>
#include "functions.h"
int main(void)
{
  int in[2], sch[2], out[1];
  int i, j, k;
  printf("  Введите 1 входной и время срабатывания реле времени через пробел\n");
  j = scanf("%d %d", &in[0], &in[1]);
  printf("  Входной 1 равен %d, а время срабатывания равно %d\n", in[0], in[1]);
  sch[1] = 0;
  sch[0] = and_2(in[0], !sch[1]);
  printf("  Выход схемы 1 равен %d\n", sch[0]);
  return 0;
}
