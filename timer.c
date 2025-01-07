int timer(int a, double b, double c)
{
  if (a == 0)
    return 0;
  if ((a != 0) && (b < c))
    return 0;
  else //((a != 0) && (b >= 5))
    return 1;
}
