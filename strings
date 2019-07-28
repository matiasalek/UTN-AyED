#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// Descripcion: Retorna la longitud de la cadena s
// Paramerto:
//    s - La cadena cuya longitud se desea conocer
// Retorna: la longitud de la cadena s
// Ejemplo: l
int length(string s)
{
   int i = 0;
   while( s[i]!='\0' )
   {
      i++;
   }
   return i;
}

// Retorna la cantidad de veces que la cadena s contiene a c
int charCount(string s, char c)
{
   int i = 0;
   int cont = 0;
   while( s[i]!='\0' )
   {
      if( s[i]==c )
      {
         cont++;
      }
      i++;
   }
   return cont;
}

// Retorna la subcadena de s comprendida entre d (inclusive) y h (no inclusive)
string substring(string s, int d, int h)
{
   int i = 0;
   string n = "";
   while( s[i]!='\0' )
   {
      if( i>=d&&i<h )
      {
         n = n+s[i];
      }
      i++;
   }
   return n;
}

// Retorna la subcadena de s que va desde d (inclusive) hasta el final
string substring(string s, int d) // ok
{

   string n = "";
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( i>=d )
      {
         n = n+s[i];
      }

   }
   return n;
}

// Retorna la posicion de la primer ocurrencia
// de c dentro s, o -1 si s no contiene a c
int indexOf(string s, char c) // ok
{
   int pos = -1;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         pos = i;
         return pos;
      }
   }
   return pos;
}

// Retorna la posicion de la primer ocurrencia de c dentro de s
// considerando la subcadena de s que va desde offset hasta el final.
// Ejemplo: indexOf("ALGORITMOS",'O',7) retorna: 1
int indexOf(string s, char c, int offSet) // ok
{
   string t = substring(s,offSet);
   int pos = indexOf(t,c);
   return pos;
}

// Retorna la posicion de la ultima ocurrencia de c dentro de s
// o -1 si s no contiene a c
int lastIndexOf(string s, char c)
{
   int pos = -1;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         pos = i;
      }
   }
   return pos;

}

// Retorna la posicion de la n-esima ocurrencia de c dentro de s.
// Por ejemplo: indexOfN("pedro|pablo|juan|rolo",'|',2) retorna 11.
int indexOfN(string s, char c, int n)
{
   int pos = -1;
   int cont = 0;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         cont++;
         if( n==cont )
         {
            pos = i;
         }
      }
   }
   return pos;

}

// Retorna el valor numerico de ch.
// Ejemplo: charToInt('4') retorna: 4.
int charToInt(char ch)
{
   //
   return ch-48;
}

// Retorna el valor char de i.
// Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i)
{
   return i+48;
}

// retorna el i-esimo digito de n contando desde la derecha
int getDigit(int n, int i) // ok
{
   //423 2
   int r;
   for( int j = i; j>=0; j-- )
   {
      r = n%10;
      n = n/10;
   }
   return r;
}

int digitCount(int i) // ok
{
   int cont = 0;
   while( i>0 )
   {
      i = i/10;
      cont++;
   }
   return cont;
}

string intToString(int num) // ok
{
   string s = "";
   char c;
   for( int i = digitCount(num)-1; i>=0; i-- )
   {
      c = getDigit(num,i)+48;
      s = s+c;
   }
   return s;
}

int stringToInt(string s) // ok
{
   // 3456
   int x = 0;
   for( int i = 0; s[i]!='\0'; i++ )
   {

      x = x*10+(s[i]-48);

   }
   return x;
}

string charToString(char c)
{
   string s = "";
   s = s+c;
   return s;
}

char stringToChar(string s)
{
   char c;
   c = s[0];
   return c;
}

string doubleToString(double d)
{
   int y = d,z = d;
   string s = intToString(y);
   int t = d*10,cont = 0;
   double w = d*10;

   while( t%10!=0 )
   {
      z = t;
      d = d*10;
      t = w*10;
      w = d*10;
      cont++;
   }
   z = z-(y*pow(10,cont));
   string x = intToString(z);

   return s+"."+x;
}

double stringToDouble(string s)
{
   double x = 0;
   int i = 0,pos = indexOf(s,'.');
   int w = pos+1;

   while( s[i]!='.' )
   {
      x = x+(charToInt(s[i])*pow(10,pos-1));
      pos--;
      i++;
   }
   string z = substring(s,w);
   int q = length(z);
   int j = 0;
   double m,g = 0;
   long double l;
   x = x*(pow(10,length(z)));

   while( z[j]!='\0' )
   {
      g = g+(charToInt(z[j])*pow(10,q-1));
      q--;
      j++;
   }
   m = x+g;
   l = m/(pow(10,length(z)));

   return l;
}

// --[/Funciones Basicas]--
bool isEmpty(string s)
{
   return length(s)==0?true:false;
}
bool contains(string s, char c)
{
   return indexOf(s,c)!=-1?true:false;
}
string replace(string s, char oldChar, char newChar)
{
   int i = 0;
   while( s[i]!='\0' )
   {
      if( s[i]==oldChar )
      {
         s[i] = newChar;
      }
      i++;
   }
   return s;
}

string insertAt(string s, int pos, char c)
{
   string x = substring(s,0,pos)+c+substring(s,pos);

   return x;
}

string removeAt(string s, int pos)
{
   string x = substring(s,0,pos)+substring(s,pos+1);

   return x;
}

string ltrim(string s)
{
   string x;
   int i = 0;
   while( s[i]==' ' )
   {
      i++;
   }
   x = substring(s,i);

   return x;
}

string rtrim(string s)
{

   int i = 0;
   while( s[i]!='\0' )
   {

      if(s[lastIndexOf(s,' ')-(i+1)]!=' ' && s[lastIndexOf(s,' ')+1]=='\0'){
         return substring(s,0,lastIndexOf(s,' ')-i);
      }

      i++;
   }

   return substring(s,0,i);

}

string trim(string s)
{
   return rtrim(ltrim(s));
}

// --[/Funciones Adicionales]--
string replicate(char c, int n)
{
   string s = "";

   for( int i = 0; i<n; i++ )
   {
      s += c;
   }

   return s;
}
string spaces(int n)
{
   return replicate('_',n);
}

string lpad(string s, int n, char c)
{
   int x;
   string r = "";
   if( length(s)!=n )
   {
      x = n-length(s);
      r = replicate(c,x);

      return r+s;
   }
   else
   {
      return s;
   }
}

string rpad(string s, int n, char c)
{
   int x;
   string r = "";
   if( length(s)!=n )
   {
      x = n-length(s);
      r = replicate(c,x);

      return s+r;
   }
   else
   {
      return s;
   }
}

string cpad(string s, int n, char c)
{
   int y;
   string r,t,u = "";
   if( length(s)!=n )
   {
      if( (n-length(s))%2!=0 )
      {
         y = n-(((n-length(s))-1)/2);
         r = lpad(s,y,c);
         u = rpad(u,(((n-length(s))-1)/2),c);

         return r+u;
      }
      else
      {
         y = n-((n-length(s))/2);
         r = lpad(s,y,c);
         u = rpad(u,((n-length(s))/2),c);

         return r+u;

      }
   }
   else
   {
      return s;
   }
}

bool isDigit(char c)
{
   return (c>='0'&&c<='9')?true:false;
}

bool isLetter(char c)
{
   return ((c>='a'&&c<='z') or (c>='A'&&c<='Z'))?true:false;
}

bool isUpperCase(char c)
{
   return (c>='A'&&c<='Z')?true:false;
}

bool isLowerCase(char c)
{
   return (c>='a'&&c<='z')?true:false;
}

char toUpperCase(char c)
{
   if( c>='a'&&c<='z' )
   {
      return c-32;
   }
   else
   {
      return c;
   }
}

char toLowerCase(char c)
{
   if( c>='A'&&c<='Z' )
   {
      return c+32;
   }
   else
   {
      return c;
   }
}

#endif
