/*
A Narcissistic Number is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits), which is narcisstic:

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1652 (4 digits), which isn't:

    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a Narcissistic number in base 10. This may be True and False in your language, e.g. PHP.

Error checking for text strings or other invalid inputs is not required, only valid positive non-zero integers will be passed into the function.
*/

#include <stdbool.h>
#include <math.h>

bool narcissistic(int num)
{
    int n=num, num2=num, mem=0, digit=0;
  
    do { n /= 10; digit++; } while (n != 0);
  
    n=num;
    while(num2 > 0)
    {
        n = num2 % 10;
        mem += pow(n, digit);
        num2 /= 10;
    }
  
    if(mem==num) return true;
  
    return false;
}

/*
Story
The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

But some of the rats are deaf and are going the wrong way!

Kata Task
How many deaf rats are there?

Legend
P = The Pied Piper
O~ = Rat going left
~O = Rat going right
Example
ex1 ~O~O~O~O P has 0 deaf rats

ex2 P O~ O~ ~O O~ has 1 deaf rat

ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
*/

#include <stdlib.h>
#include <string.h>

int countDeafRats(const char *town)
{
    int right=0, left=0, pp=0, il=0, ir=0;
    int *l;
    int *r;
    l = (int*) calloc( (strlen(town)-2), sizeof(int)  );
    r = (int*) calloc( (strlen(town)-2), sizeof(int)  );
    
    for(int i=0; town[i]!=0; i++)
    {
      if(town[i]=='P') pp=i;
      else if(town[i]==' ');
      else if(town[i]=='~') { right++; r[ir]=i; ir++; i++; }
      else { left++; l[il]=i; il++; i++; }
    }
    
    if(pp==0) return right;                         //skt ptknnyl trk vssz
    else if(pp > (strlen(town) - 3) ) return left;  //1 \0, 1 P, 1 fl ptkny
  
    else
    {
      right=left=0;
      
      for(int i=0; i<il; i++)
        {
          if(pp>l[i]) left++;                       //mrt skt ptknyt krsnk
        }
      
      for(int i=0; i<ir; i++)
        {
          if(pp<r[i]) right++;
        }
      
      return ( right+left );
    }
}

/*
For a given string s find the character c (or C) with longest consecutive repetition and return:

c
(assign l to pointer)
where l (or L) is the length of the repetition. If there are two or more characters with the same l return the first in order of appearance.

For empty string return:

'\0'
(assign 0 to pointer)
In JavaScript: If you use Array.sort in your solution, you might experience issues with the random tests as Array.sort is not stable in the Node.js version used by CodeWars. This is not a kata issue.
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char longest_repetition(const char *s, size_t *n) 
{
    char kar=*s, db=1, max=strlen(s), memdb=1, memcar=*s;
    int i=0;
   
    if(*s);
    else {*n=0; return kar; }
    max /= 2;
    if( max==0 || max==1 ) { *n=db; return *s; }
  
    for(s++; *s!=0; s++)
    {
      if(*s==kar) db++;
      if(*s!=kar)
      {
        if(db>memdb) { memdb=db; memcar=kar; }
        db=1; 
        kar=*s; 
      }
      if(db>memdb) { memdb=db; memcar=kar; }
    }
  
  *n=memdb;
  return memcar;
}

/*
Write a function that accepts a string, and returns true if it is in the form of a phone number.
Assume that any integer from 0-9 in any of the spots will produce a valid phone number.

Only worry about the following format:
(123) 456-7890 (don't forget the space after the close parentheses)

Examples:

"(123) 456-7890"  => true
"(1111)555 2345"  => false
"(098) 123 4567"  => false
*/

#include <stdbool.h>

bool valid_phone_number(const char* number) 
{
    int rake=0, cnt=0;
  
    for( ; *number!=0 ; number++)
    {
      if(*number=='(' && rake==0)                     rake=1;
      else if(*number>=48 && *number<=57 && rake==1);
      else if(*number==')' && rake==1)                rake=2;
      else if(*number==' ' && rake==2)                rake=3;
      else if(*number>=48 && *number<=57 && rake==3)  cnt++;
      else if(*number=='-' && cnt==3)                 cnt=0;
      else return false;
    }
  
  if(cnt==4) return true;
  
  return false;
}

/*
A man has a rather old car being worth $2000. He saw a secondhand car being worth $8000. He wants to keep his old car until he can buy the secondhand one.

He thinks he can save $1000 each month but the prices of his old car and of the new one decrease of 1.5 percent per month. Furthermore this percent of loss increases of 0.5 percent at the end of every two months. Our man finds it difficult to make all these calculations.

Can you help him?

How many months will it take him to save up enough money to buy the car he wants, and how much money will he have left over?

Parameters and return of function:

parameter (positive int or float, guaranteed) start_price_old (Old car price)
parameter (positive int or float, guaranteed) start_price_new (New car price)
parameter (positive int or float, guaranteed) saving_per_month 
parameter (positive float or int, guaranteed) percent_loss_by_month

nbMonths(2000, 8000, 1000, 1.5) should return [6, 766] or (6, 766)
Detail of the above example:
end month 1: percent_loss 1.5 available -4910.0
end month 2: percent_loss 2.0 available -3791.7999...
end month 3: percent_loss 2.0 available -2675.964
end month 4: percent_loss 2.5 available -1534.06489...
end month 5: percent_loss 2.5 available -395.71327...
end month 6: percent_loss 3.0 available 766.158120825...
return [6, 766] or (6, 766)
where 6 is the number of months at the end of which he can buy the new car and 766 is the nearest integer to 766.158... (rounding 766.158 gives 766).

Note:

Selling, buying and saving are normally done at end of month. Calculations are processed at the end of each considered month but if, by chance from the start, the value of the old car is bigger than the value of the new one or equal there is no saving to be made, no need to wait so he can at the beginning of the month buy the new car:

nbMonths(12000, 8000, 1000, 1.5) should return [0, 4000]
nbMonths(8000, 8000, 1000, 1.5) should return [0, 0]
*/

#include <math.h>

int* nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
  int month=0;
  int *p;
  double price=startPriceOld, oldPrice=startPriceOld, newPrice=startPriceNew, amort=0;
  
  p = (int*)calloc(2,sizeof(int));
  
  amort = ( 100 - percentLossByMonth ) / 100;
  printf("\n\n");
  while(price<newPrice)
  {
    month += 1;
    
    if(month%2 == 0) amort -= 0.005;
    
    oldPrice *= amort;
    price = oldPrice + (month * savingperMonth);
    
    newPrice *= amort;
  }
  
  price = round( price - newPrice );
  
  p[0]=month;
  p[1]=price;
  
  return p;
}

/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *rot13(const char *src)
{
    char puff=0;
    unsigned char *p;
    p = (unsigned char*) calloc( (strlen(src)+1), sizeof(unsigned char) );
    
    for(int i=0; *src!=0; src++)
    {
      if(*src>=65 && *src<=90)
      {
        p[i] = *src + 13;
        if(p[i] > 90) { puff=p[i]-90; p[i]=64+puff; }
      }
      
      else if(*src>=97 && *src<=122)
      {
        p[i] = *src + 13;
        if(p[i] > 122) { puff=p[i]-122; p[i]=96+puff; }
      }
      
      else p[i] = (unsigned char)*src;
      
      i++;
    }
  
    return p;
}

/*
Trolls are attacking your comment section!

A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.

Your task is to write a function that takes a string and return a new string with all vowels removed.

For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".

Note: for this kata y isn't considered a vowel.
*/

#include <stdlib.h>

char *disemvowel(const char *str)
{
  char t[5]={'A','E','I','O','U'};
  int db=0, i=0;
  char *p;
  
  for(p=str ; *p!=0 ; p++)
  {
    for(i=0; i<5; i++ )
    {
      if( *p==t[i] || *p==(t[i]+32) ) { p++; i=-1; }
    }
    
    db++;
  }
  
  p = (char*) malloc( (db+1) * sizeof(char));
  
  for(db=0 ; *str!=0 ; str++)
  {
    for(i=0; i<5; i++ )
    {
      if(*str==t[i] || *str==(t[i]+32)) { str++; i=-1; }
    }
    p[db]=*str;
    db++;
  }
  p[db]=*str;
  
  return p;
}

/*
In this Kata, you will be given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:

make as few changes as possible.
if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
For example:

solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
*/

#include <stdlib.h>

char *solve(const char *str) 
{
    int dbn=0, dbk=0, i=0;
    char *p, *p1;
  
    p=str;
  
    while(*p>0)
    {
      if(*p>=97) dbk++;
      else dbn++;
      
      p++;
    }
    
    p1 = (char*) malloc( (dbk + dbn + 1) * sizeof(char) );
    
    while(*str>0)
    {
      if(dbk>=dbn)
      {
        if(*str<=90) p1[i] = *str + 32;
        else p1[i]=*str;
      }
      
      if(dbk<dbn)
      {
        if(*str>=96) p1[i] = *str -32;
        else p1[i]=*str;
      }
      
      i++;
      str++;
    }
  
    p1[i]=*str;
  
    return p1;
}

/*
Define a function that takes an integer argument and returns a logical value true or false depending on if the integer is a prime.

Per Wikipedia, a prime number ( or a prime ) is a natural number greater than 1 that has no positive divisors other than 1 and itself.

Requirements
You can assume you will be given an integer input.
You can not assume that the integer will be only positive. You may be given negative numbers as well ( or 0 ).
NOTE on performance: There are no fancy optimizations required, but still the most trivial solutions might time out. Numbers go up to 2^31 ( or similar, depending on language ). Looping all the way up to n, or n/2, will be too slow.
Example
is_prime(1)  // false 
is_prime(2)  // true  
is_prime(-1) // false 
*/

#include <stdbool.h>
#include<math.h>

bool is_prime(int num)
{
    if(num<=1) return false;
  
    int n=0, db=0;
    
    for(n=1; n<=sqrt(num); n++)
    {
        if(num%n==0) db++;
        if(db>1) return false;
    }
    
  return true;
}

/*
In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. For example: 5! = 5 * 4 * 3 * 2 * 1 = 120. By convention the value of 0! is 1.

Write a function to calculate factorial for a given input. If input is below 0 or above 12 throw an exception of type ArgumentOutOfRangeException (C#) or IllegalArgumentException (Java) or RangeException (PHP) or throw a RangeError (JavaScript) or ValueError (Python) or return -1 (C).

More details about factorial can be found here.
*/

int factorial(int n) 
{
    int number=1;
  
    if(n<0 || n>12) return -1;
    if(n==0) return 1;
  
    for(; n>0; n--) number=number*n;
  
    return number;
}

/*
Your task is to split the chocolate bar of given dimension n x m into small squares. Each square is of size 1x1 and unbreakable. Implement a function that will return minimum number of breaks needed.

For example if you are given a chocolate bar of size 2 x 1 you can split it to single squares in just one break, but for size 3 x 1 you must do two breaks.

If input data is invalid you should return 0 (as in no breaks are needed if we do not have any chocolate to split). Input will always be a non-negative integer.
*/

#include <stdint.h>

uint32_t breaking_chocolate(uint32_t n, uint32_t m)
{
  long int check=0;
  if(n<=0 || m<=0) return 0;
  check=(n*m)-1;
  if(check<=0) return 0;
  return ((n*m)-1); 
}

/*
Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.

You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at least 2.
The array will always contain letters in only one case.

Example:

['a','b','c','d','f'] -> 'e' ['O','Q','R','S'] -> 'P'

["a","b","c","d","f"] -> "e"
["O","Q","R","S"] -> "P"
(Use the English alphabet with 26 letters!)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have also created other katas. Take a look if you enjoyed this kata!
*/

char findMissingLetter(char array[], int arrayLength)
{
  char check=0; 
  
  for(int i=0; i<=arrayLength; i++)
  {
    check=array[i+1]-array[i];
    if(check!=1) return array[i]+1;
  }
}