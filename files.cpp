#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f)
{
   T x;
   fread(&x,sizeof(T),1,f);
   return x;
}

template<typename T> void write(FILE* f, T v)
{
   fwrite(&v,sizeof(T),1,f);
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> long fileSize(FILE* f)
{
   long act = ftell(f);
     // muevo el puntero al final del archivo

     fseek(f,0,SEEK_END);  // SEEK_END hace referencia al final del archivo

     // tomo la posicion actual (ubicado al final)
     long ult = ftell(f);

     // vuelvo a donde estaba al principio
     fseek(f,act,SEEK_SET);

     return ult/sizeof(T);
}

template<typename T> long filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

template <typename T, typename K>
int fileBinarySearch(FILE*f, K k, int cmpTK(T, K))
{
   long act = ftell(f);
   int ult = -1;
   T x;
   fseek(f,0,SEEK_SET);
   fread(&x,sizeof(T),1,f);
   while( !feof(f) )
   {

      if( cmpTK(x,k)==0 )
      {
         ult = ftell(f);
         fseek(f,act,SEEK_SET);
      }
      fread(&x,sizeof(T),1,f);
   }
   return ult/sizeof(T);
}
#endif
