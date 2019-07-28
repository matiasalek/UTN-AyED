#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int& len, T v)
{
    arr[len] = v;
    return len++;
}

template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T, K))
{
    int i = 0;
    while( i<len&&cmpTK(arr[i],v)!=0 )
    {
        i++;
    }
    return i<len?i:-1;
}

template <typename T>
void remove(T arr[], int& len, int pos)
{

    for( int i = pos; i<len; i++ )
    {
        arr[i] = arr[i+1];

    }
    len--;
}

template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
    for( int i = len-1; i>=pos; i-- )
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = v;
    len++;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
    bool ordenado = true;
    while( ordenado )
    {
        ordenado = false;
        for( int i = 0; i<len-1; i++ )
        {
            if( cmpTT(arr[i],arr[i+1])>0 )
            {
                T aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                ordenado = true;

            }
        }
    }
}

template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T, T))
{
//   int i = 0;
//   while( i<len&&cmpTT(arr[i],v)>=0 )
//   {
//      i++;
//   }
//   insert<T>(arr,len,v,i);
//   sort(arr, len, cmpTT);
//   return i;

    int r = -1;
    for( int i = 0; i<len; i++ )
    {
        if( cmpTT(arr[i],v)>=0 )
        {
            r = i;
            insert<T>(arr,len,v,r);
            break;
        }
    }
    if( r==-1 )
    {
        r = len;
        insert<T>(arr,len,v,r);
    }
    return r;
}

template <typename T>
int searchAndInsert(T arr[], int& len, T v, bool& enc, int cmpTT(T, T))
{
    // busco el valor
    int pos = find<T, T>(arr,len,v,cmpTT);

    // determino si lo encontre o no
    enc = pos>=0;

//   if(pos>=0){
//      enc=true;
//   }else{
//      enc= false;
//   }

    // si no lo encontre entonces lo inserto ordenado
    if( !enc )
    {
        pos = orderedInsert<T>(arr,len,v,cmpTT);
    }

    return pos;
}

template <typename T, typename K>
int binarySearch(T a[], int len, K v, int cmpTK(T, K), bool& enc)
{
    int i = 0;
    int j = len-1;
    int k = (i+j)/2;

    enc = false;
    while( !enc&&i<=j )
    {
        if( cmpTK(a[k],v)>0 )
        {
            j = k-1;
        }
        else
        {
            if( cmpTK(a[k],v)<0 )
            {
                i = k+1;
            }
            else
            {
                enc = true;
            }
        }
        k = (i+j)/2;
    }
    return cmpTK(a[k],v)>=0?k:k+1;
}

#endif
