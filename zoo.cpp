#include<iostream>
#include<cstdlib>
#include<time.h>
#include"sloth.hpp"
#include"monkey.hpp"
#include"otter.hpp"

 using namespace std;

int total_food_cost(Monkey mon[], Otter otter[],Sloth sloth[], int n_sloth,  int  n_mon, int n_otter )
{
int total_cost = 0;

 if( n_mon > 0)
      {
             for( int x = 0; x < n_mon; x++)
                 total_cost += mon[x].food_cost();
              }


        if ( n_otter > 0 )
        {
            for(int x = 0; x < n_otter; x++)
                total_cost += otter[x].food_cost();
             }


        if(n_sloth > 0)
        {
        for(int x = 0; x < n_sloth; x++)
        total_cost += sloth[x].food_cost();


        }


return total_cost;


}


void zoo()
{
Monkey*  mon = new Monkey[6];
Otter* otter = new Otter[6];
Sloth* sloth = new Sloth[6];

int stop  = 0, choice = 0,day = 0,money = 1000000,n_mon = 0,n_otter = 0, n_sloth = 0, sick, cost,s,boom = 0;
while( stop == 0)
{

   cout << " you have " << n_mon << " monkeys"  << "   you have " <<  n_otter << " otters" << " you have " << n_sloth << " sloths" <<  endl;

   cout <<  " money " << money << "\n" <<  " 1) buy monkey" << "\n" <<  " 2) buy otter" << "\n" << " 3) buy sloth" <<  "\n" << " 4)next" <<  endl;
cin >> choice;

if ( choice == 1 && money >= 15000 && n_mon < 2 )
{
 money -= 15000;
n_mon += 1;
}

if( choice == 3 && money >= 2000)
{
money -= 2000;
n_sloth += 1;

}


  if ( choice == 2 && money >= 5000 && n_otter < 2)
{
money -= 5000;
n_otter += 1;
}


// Otter Status

srand(time(NULL));
for(int x = 0; x < n_otter; x++)
{
 s = rand() % 45;
money+=250;
if( otter[x].have_babies(s) == 1 && n_otter < 5 && n_otter >= 2)
{
cout << " you had two otter babies" << endl;
n_otter += 2;

}

if( otter[x].status(n_otter,s,money) == 1 )
if(  money >= 2500)
{
   money -= 2500;
cout << " otter cured" << endl;
}
else
{
otter[x].is_dead();
cout << " do to you being poor a otter is dead" << endl;
   }
}


int s2 = rand() %  45;
// Monkey status
for(int x = 0; x < n_mon; x++)
{
if(s2 >= 30 && s2 <= 34)
   boom  = 1;

s = rand() % 45;
   money += mon[x].income_mon(boom);

if(mon[x].have_babies(s) == 1 && n_mon < 5 && n_mon >= 2)
{

n_mon+=1;
cout << " you got a babey monkey" << endl;
}

if(mon[x].status(n_mon,s,money) == 1)
if(money >= 7500)
{
   money -= 7500;
cout << " monkey cured" << endl;
}
else
{
   mon[x].is_dead();
cout <<" due to you being poor a monkey is dead" << endl;
}

}
// Sloth status
for( int x =0; x < n_sloth; x++)
{
money+= 100;
s = rand() % 45;
cost = sloth[x].status(n_sloth,s,money);

if(sloth[x].have_babies(s) == 1 && n_sloth < 5 && n_sloth >= 2)
{
cout << " you have 3 new baby sloths" << endl;
n_sloth+=3;

}

if( sloth[x].status(n_sloth,s,money) == 1)
if( money >= 1000)
{
   money -= 1000;
   cout << " sloth paid for" << endl;
}
   else
{
   sloth[x].is_dead();
 //  cout << " do to you being poor a sloth is dead" << endl;
}


}

money -= total_food_cost(mon,otter,sloth,n_sloth,n_mon,n_otter);

cout << " continue to next day? " << endl;
cin >> stop;

}


delete[] mon;
delete[] otter;
delete[] sloth;


}


int main()
{

zoo();

return 0;
}
