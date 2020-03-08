#include <windows.h>
#include <ctime>

using namespace std;

int Pause(int howlong)
{
     clock_t start;
     start = clock();
     while (clock()-start < howlong) ;
}

int abs(int x)
{
    if (x < 0)
    x += 2*(0-x);
    return (x);
}

double GetInt(int low, int high)
{
    double entry;
    cin >> entry;
    while (entry < low || entry > high)
    {
          cout << "Invalid value. Please re-enter.\n";
          cin >> entry;
    }
    return (entry);
}

int sum(int n)
{
      if ( n <= 9) return n;
      return sum(n / 10) + n % 10;
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

long IntPower(long x, int n)
{
     if (n == 0)
     return (1);
     else 
     return(x * IntPower(x, n-1));
}

int GetRand(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    /*
     *  As Init is static, it will remember it's value between
     *  function calls.  We only want srand() run once, so this
     *  is a simple way to ensure that happens.
     */
    srand(time(NULL));
    Init = 1;
  }

  /*
   * Formula:  
   *    rand() % N   <- To get a number between 0 - N-1
   *    Then add the result to min, giving you 
   *    a random number between min - max.
   */  
  rc = (rand() % (max - min + 1) + min);
  
  return (rc);
}

int IsPrime(int x)
{
    int y;
    if (x == 0 || x < -1)
    return (0);
    for (y = 2; y <= .5 * x; y++)
    {
        if (x % y == 0)
        return (0);
        }
return (1);
}

int Smaller(int a, int b)
{
    if (a < b)
    return (a);
    if (a > b)
    return (b);
    return (1);
}
