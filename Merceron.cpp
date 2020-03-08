#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

struct object {
       int x[100], y[100], instAmount, counter;
};

int GetRand(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    srand(time(NULL));
    Init = 1;
  }
  rc = (rand() % (max - min + 1) + min);
  
  return (rc);
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Output(int x, int y, string Output)
{
     gotoxy(x, y);
     cout << Output;
}

int Pause(int howlong)
{
     clock_t start;
     start = clock();
     while (clock()-start < howlong) ;
}

int game()
{
      system("cls");
      int playerx=30, playery=21, matrix[82][25], score, dcounter;
      long counter;
      for (counter=81; counter>=0; counter--)
      {
          for (score=24; score>=0; score--)
          matrix[counter][score]=0;
      }
      score++;
      object easy;
      easy.instAmount=0, easy.counter=0;
      object asteroid;
      asteroid.instAmount=0, asteroid.counter=0;
      object wave;
      wave.instAmount=0, wave.counter=0;
      object missile;
      missile.instAmount=0, missile.counter=0;
      gotoxy(30, 21);
      cout << (char)127;
      
      while (1)
      {
      counter++;
      if (missile.counter)
      {
                for (missile.counter=missile.instAmount; missile.counter; missile.counter--)
                {
                    if ((missile.y[missile.counter-1] != playery) || (missile.x[missile.counter-1] != playerx))
                    Output(missile.x[missile.counter-1], missile.y[missile.counter-1], " ");
                    missile.y[missile.counter-1]--;
                    gotoxy(missile.x[missile.counter-1], missile.y[missile.counter-1]);
                    if (matrix[missile.x[missile.counter-1]][missile.y[missile.counter-1]])
                    {
                       score += matrix[missile.x[missile.counter-1]][missile.y[missile.counter-1]];
                       matrix[missile.x[missile.counter-1]][missile.y[missile.counter-1]]=0;
                       cout << " ";
                         for (dcounter=missile.counter-1; dcounter < missile.instAmount; dcounter++)
                         {
                             if (dcounter != missile.instAmount-1)
                             {
                                   missile.x[dcounter]=missile.x[dcounter+1];
                                   missile.y[dcounter]=missile.y[dcounter+1]; 
                             }
                         }
                         missile.instAmount--;
                    }
                    else
                    {
                          cout << (char)179;
                    if (!missile.y[missile.counter-1])
                              {
                              Output(missile.x[missile.counter-1], missile.y[missile.counter-1], " ");
                              for (dcounter=missile.counter-1; dcounter < missile.instAmount; dcounter++)
                             {
                                 if (dcounter != missile.instAmount-1)
                                 {
                                       missile.x[dcounter]=missile.x[dcounter+1];
                                       missile.y[dcounter]=missile.y[dcounter+1]; 
                                 }
                             }
                             missile.instAmount--;
                             }
                    }        
                }       
      }
      if (easy.counter == 10)
      {
          for (easy.counter=easy.instAmount; easy.counter; easy.counter--)
          {
              if (!(matrix[easy.x[easy.counter-1]][easy.y[easy.counter-1]]) && (easy.y[easy.counter-1] >= 0))
              {
                             easy.y[easy.counter-1]=-30;
                             easy.x[easy.counter-1]=GetRand(1,78);
              }
              else
              {
              if (easy.y[easy.counter-1] >= 0)
              {
              matrix[easy.x[easy.counter-1]][easy.y[easy.counter-1]]=0;
              Output(easy.x[easy.counter-1], easy.y[easy.counter-1], " ");
              }
              if (easy.y[easy.counter-1] == 24)
              {
              easy.y[easy.counter-1]=-30;
              easy.x[easy.counter-1]=GetRand(1,78);
              }
              easy.y[easy.counter-1]++;
              if (easy.y[easy.counter-1] >= 0)
              {
              matrix[easy.x[easy.counter-1]][easy.y[easy.counter-1]]=1;
              Output(easy.x[easy.counter-1], easy.y[easy.counter-1], "v");
              }
              }
          }
         if (easy.instAmount != 49)
         {
             easy.x[easy.instAmount]=GetRand(1,78);
             easy.y[easy.instAmount]=0;
             matrix[easy.x[easy.instAmount]][0]=1;
             Output(easy.x[easy.instAmount], 0, "v"); 
             easy.instAmount++;
         }
      }   
      /*         */ 
      if (asteroid.counter == 5)
      {
          for (asteroid.counter=asteroid.instAmount; asteroid.counter; asteroid.counter--)
          {
              if (!(matrix[asteroid.x[asteroid.counter-1]][asteroid.y[asteroid.counter-1]]) && (asteroid.y[asteroid.counter-1] >= 0))
              {
                             asteroid.y[asteroid.counter-1]=-5;
                             asteroid.x[asteroid.counter-1]=GetRand(1,78);
              }
              else
              {
              if (asteroid.y[asteroid.counter-1] >= 0)
              {
              matrix[asteroid.x[asteroid.counter-1]][asteroid.y[asteroid.counter-1]]=0;
              Output(asteroid.x[asteroid.counter-1], asteroid.y[asteroid.counter-1], " ");
              }
              if (asteroid.y[asteroid.counter-1] < playery)
              asteroid.y[asteroid.counter-1]++;
              if (asteroid.y[asteroid.counter-1] > playery)
              asteroid.y[asteroid.counter-1]--;
              if (asteroid.x[asteroid.counter-1] < playerx)
              asteroid.x[asteroid.counter-1]++;
              if (asteroid.x[asteroid.counter-1] > playerx)
              asteroid.x[asteroid.counter-1]--;              
              if (asteroid.y[asteroid.counter-1] >= 0)
              {
              matrix[asteroid.x[asteroid.counter-1]][asteroid.y[asteroid.counter-1]]=1;
              Output(asteroid.x[asteroid.counter-1], asteroid.y[asteroid.counter-1], ".");
              }
              }
          }
         if ((asteroid.instAmount < 4 && score > 50) || (score > 100 && asteroid.instAmount < 10))
         {
             asteroid.x[asteroid.instAmount]=GetRand(1,78);
             asteroid.y[asteroid.instAmount]=0;
             matrix[asteroid.x[asteroid.instAmount]][0]=1;
             Output(asteroid.x[asteroid.instAmount], 0, "."); 
             asteroid.instAmount++;
         }
      }
/*         */ 
      if (wave.counter == 5)
      {
          for (wave.counter=wave.instAmount; wave.counter; wave.counter--)
          {
              if (!(matrix[wave.x[wave.counter-1]][wave.y[wave.counter-1]]) && (wave.y[wave.counter-1] >= 0))
              {
                             wave.y[wave.counter-1]=-30;
                             wave.x[wave.counter-1]=GetRand(1,78);
              }
              else
              {
              if (wave.y[wave.counter-1] >= 0)
              {
              matrix[wave.x[wave.counter-1]][wave.y[wave.counter-1]]=0;
              Output(wave.x[wave.counter-1], wave.y[wave.counter-1], " ");
              }
              if (wave.y[wave.counter-1] == 24)
              {
              wave.y[wave.counter-1]=-30;
              wave.x[wave.counter-1]=GetRand(1,78);
              }
              wave.y[wave.counter-1]++;
              if (wave.y[wave.counter-1] >= 0)
              {
              matrix[wave.x[wave.counter-1]][wave.y[wave.counter-1]]=1;
              gotoxy(wave.x[wave.counter-1], wave.y[wave.counter-1]);
              cout << (char)31;
              }
              }
          }
         if (wave.instAmount != 40 && !((score+20) % 45))
         {
             wave.x[wave.instAmount]=GetRand(1,78);
             wave.y[wave.instAmount]=0;
             matrix[wave.x[wave.instAmount]][0]=1;
             gotoxy(wave.x[wave.instAmount], 0);
             cout << (char)31;
             wave.instAmount++;
         }
      }            
      if (counter == 2000000)
      {
      easy.counter++;
      asteroid.counter++;
      wave.counter++;
      missile.counter++;
      if ( GetAsyncKeyState ( VK_LEFT ) && playerx > 1)
          {
                Output(playerx, playery, " ");
                playerx--;
                gotoxy(playerx, playery);
                cout << (char)127;
          }
      if ( GetAsyncKeyState ( VK_RIGHT ) && playerx < 78)
           {
                Output(playerx, playery, " ");
                playerx++;
                gotoxy(playerx, playery);
                cout << (char)127;
           }   
      if ( GetAsyncKeyState ( VK_DOWN ) && playery < 24)
           {
                Output(playerx, playery, " ");
                playery++;
                gotoxy(playerx, playery);
                cout << (char)127;
           }   
      if ( GetAsyncKeyState ( VK_UP ) && playery > 1)
           {
                Output(playerx, playery, " ");
                playery--;
                gotoxy(playerx, playery);
                cout << (char)127;
           }
      if (( GetAsyncKeyState ( VK_SPACE ) & SHRT_MAX ) && missile.instAmount < 99)
           {
                missile.instAmount++;
                missile.y[missile.instAmount-1]=playery;
                missile.x[missile.instAmount-1]=playerx;
           }          
      counter=0;
      if (matrix[playerx][playery])
      return (score);
      } 
      }
}
    
int main()
{
int score, message, counter;
char messageGameOver[]="Game Over", messageYourScore[]="Your Score Was: ";
system ("title Merceron - A Game By Nicram.");
system ("color 70");
while (1)
{
      GetAsyncKeyState ( VK_SPACE );
      score=game();
      for (message=0; message <= 9; message++)
      {
          gotoxy(message+35, 7);
          cout << messageGameOver[message];
          Pause(75);
      }
      for (message=0; message <= 16; message++)
      {
          gotoxy(message+30, 9);
          cout << messageYourScore[message];
          Pause(75);
      }
      cout << score;
      Pause(5000);
}
}
