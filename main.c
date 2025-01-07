#include <stdio.h>
#include "functions.h"
#define RESP_TIME 5
int main(void)
{
  int in[1], sch[2], out[1]; // массив входных сигналов, массив выходов схем, массив итоговых выходных сигналов
  double time[1], t;
  int i, j, k;
  char l;
  printf("  Введите 1 входной и время действия входного сигнала через пробел\n");
  for (i=0; i < 1; i++)
    {
      printf("  Введите 1 входной\n");
      j = scanf("%d", &in[i]);
      while (j != 1)
          {
            scanf("%c", &l);
            printf("  %c - неверный ввод, введите число\n", l);
            j = scanf("%d", &in[i]);
          }
      printf("  Введите время действия входного сигнала\n");
      j = scanf("%lf", &time[i]);
      while (j != 1)
          {
            scanf("%c", &l);
            printf("  %c - неверный ввод, введите число\n", l);
            j = scanf("%lf", &time[i]);
          }
    }
  printf("  Входной 1 равен %d, а время действия входного сигнала равно %.1f сек\n", in[0], time[0]);
  sch[1] = 0; // начальное значение выхода реле времени
  sch[0] = and_2(in[0], !sch[1]);
  out[0] = sch[0];
  sch[1] = timer(sch[0], 0, RESP_TIME);
  sch[0] = and_2(in[0], !sch[1]);
  k = 0;
  t = 0;
  while (time[0] >= RESP_TIME)
      {
        if (sch[0] == 1)
         {
	   printf("  Выход схемы 1 в момент в момент времени t=%.1f+ сек равен %d\n", t, sch[0]);
	   printf("  Итоговый выходной сигнал в момент времени t=%.1f+ сек равен %d\n", t, out[0]);	
         }        	
        sch[1] = timer(sch[0], RESP_TIME, RESP_TIME);
        sch[0] = and_2(in[0], !sch[1]);
	out[0] = sch[0];
        if (sch[0] == 0)
         {
	   k += 1;
           time[0] -= RESP_TIME;
	   t = k*RESP_TIME;
	   printf("  Выход схемы 1 в момент в момент времени t=%.1f сек равен %d\n", t, sch[0]);
	   printf("  Итоговый выходной сигнал в момент времени t=%.1f сек равен %d\n", t, out[0]);
         }        
      }
  if (time[0] == 0)
   {
     out[0] = sch[0];
     printf("  Выход схемы 1 равен %d\n", sch[0]);
     printf("  Итоговый выходной сигнал равен %d\n", out[0]);
     return 0;
   }
  sch[1] = timer(sch[0], time[0], RESP_TIME);
  sch[0] = and_2(in[0], !sch[1]);
  out[0] = sch[0];
  printf("  Выход схемы 1 в момент в момент времени t=%.1f+ сек равен %d\n", t, sch[0]);
  printf("  Итоговый выходной сигнал в момент времени t=%.1f+ сек равен %d\n", t, out[0]);
  return 0;
}
