#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"
int tokenCount(string s,char sep) // ok
{
   int ret = 0;

   if (length(s)>0)
   {
      ret = charCount(s,sep)+1;
   }

   return ret;
}

// pablo|juan|pedro|carlos
string getTokenAt(string s,char sep, int p)  // ok
{
   int pos1 = indexOfN(s,sep,p)+1;
   int pos2 = indexOfN(s,sep,p+1);
   string t = "";
   if (charCount(s,sep)==0)
   {
      t  = substring(s,pos1);
   }
   else
   {
      if (pos2==1)
      {
         if (pos1 == 0)
         {
            t="";
         }
         else
         {
            t = substring (s,pos1);
         }
      }
      else
      {
         t = substring(s,pos1,pos2);
      }
   }

   return t;
}

void addToken(string& s,char sep,string t) // ok
{
   if (s==""){
      s = t;
   }
   else {
      s = s+sep+t;
   }
}

string removeTokenAt(string& s,char sep, int p) //  ok
{
   string n = "";
   for (int i = 0; i<tokenCount(s,sep); i++)
   {
      if (p!=i)
      {
         n = n+getTokenAt(s,sep,i)+sep;
      }
   }

   if (n[length(n)-1] ==sep )
   {
      n = substring(n,0,length(n)-1);
   }
   return n;
}

void setTokenAt(string& s,char sep, string t,int p) // ok
{
   string n = "";
   for (int i = 0; i<tokenCount(s,sep); i++)
   {
      if (p==i)
      {
         n = n+t+sep;
      }
      else
      {
         n = n+getTokenAt(s,sep,i)+sep;
      }
   }
   if (n[length(n)-1]==sep)
   {
      n = substring(n,0,length(n)-1);
   }
   s = n;
}

int findToken(string s,char sep, string t)
{
   for (int i = 0; i<tokenCount(s,sep); i++ )
   {
      if (t==getTokenAt(s,sep,i))
      {
         return i;
      }
   }
   return -1;
}

// --[/Funciones Token]--



#endif
