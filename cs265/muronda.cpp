#include <iostream>
//including the necessary libraries 
#include <ctime>

#include <cstdlib>

using namespace std;
//initializing the menu which we will  be used by the user
int menu();
//initialize the operation to double the number
int doubleIt(int);
//initialize the operation to  get a power
int getPower(int,int);
//initialize the operation to reverse
int reverse(int);
//initialize the operation to  return the power
int power(int);

int sum(int);
//initialize the power to raise the two-digit
int twoDigit(int);

int threeDigit(int);
//initialize the prime number
bool prime(int);

int main()

{
    
int n;
//initialize the random generator 
srand(time(0));
//generating a sequence of random numbers
n=rand()%90+10;

do

{
//give an output to the console of the random number
cout<<"The number is: "<<n<<endl<<endl;

/*Switch to the different cases based on the different operations to be carried out.
Exit the menu if all the cases have been performed

*/
switch(menu())

  {case 1: n=doubleIt(n);

           break;

  case 2: n=reverse(n);

          break;

  case 3: n=power(n);

          break;

  case 4: n=sum(n);

          break;

  case 5: n=twoDigit(n);

          break;

  case 6: n=threeDigit(n);

          break;

  case 7: return 0;

  }
// determine if the numer is prime
if(prime(n)){
         cout<<n<<" is prime\n";
}
  

else{
         cout<<n<<" is not prime\n\n";
}

   
//add 10 if the number is less than 10
if(n<10){
 n+=10;
}
 
}
//keep the program running as long as condition holds
while(true);

}
// calling the operation to double the number
int doubleIt(int n)

{return n*2;

}

int power(int n)

{int p;

cout<<"Enter 2, 3 or 4th power: ";

cin>>p;
//check that the power raised is only 2,3 or 4 otherwise prompt the user to correct the mistake
while(p<2||p>4)

   {cout<<"invalid entry\n";

    cout<<"Enter 2, 3 or 4th power: ";

    cin>>p;

    }

return getPower(n,p);

}

int reverse(int n)

{int newnum=0;
//after performing an operaton ensure that th
while(n>0){
   newnum=newnum*10+n%10;

      n=n/10;

}

return newnum;  

}

int sum(int n)

{int sum=0;

while(n>0)

     {sum=sum+n%10;

      n=n/10;

     }

return sum;

}

int twoDigit(int n)

{int d1,d2;
// if we are working with a two digit number,raise the first digit to  the power of the second digit
   if(n<100)
       //this represents the ones  digit
      {d1=n%10;
      // the second digit represents the tens 
       d2=n/10;

       return getPower(d1,d2);

       }

return n;

}
//if we are working with a three digit number 
int threeDigit(int n)

{int d1,n2;

if(n>99)

  {d1=n%10;
   // raise the first two digits  to the power of the last digit if ones digiti is less than or equals to 4
   if(d1<=4)

       {n2=n/10;

        return getPower(n2,d1);

        }

}

return n;

}
// continously check if the number is prime
bool prime(int n)

{int i;

for(i=2;i<n-1;i++)

  if(n%i==0)              

     return false;

return true;                

}
//get the power of the first two digits and raise it to the last digit
int getPower(int x,int y)

{int ans,i;

if(y==0)

     return 1;

  else

     {ans=x;

      for(i=2;i<=y;i++)

          ans=ans*x;

      return ans;

      }

      }

int menu()

{int choice=8;
// print to the console the different output which is menu driven
while(choice<1||choice>7)

  {
  cout<<"1.   double the number\n";

  cout<<"2.   reverse the digit of the number\n";

  cout<<"3.   raise the number to the power of 2,3, or 4\n";

  cout<<"4.   sum the digits of the number.\n";

  cout<<"5.   if the number is a two digit number\n     then raise the first digit to the power of the second digit\n";

  cout<<"6.   If the number is a three digit number\n";

  cout<<"     and the last digit is less than or equal to 4\n     then raise the first two digits to the power of the last digit.\n";

  cout<<"7.   exit\n";

  cin>>choice;

}

return choice;
}