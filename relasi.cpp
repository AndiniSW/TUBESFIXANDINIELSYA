//andini salimah 1301164080
#include "relasi.h"
#include <iostream>
using namespace std;

void createListR(ListR &L)
{
    firstR(L)=NULL;
    lastR(L)=NULL;
}

addressR alokasi(addressP P, addressC C)
{
    addressR R;
    R = new elmListR;
    R->P =P;
    R->Q = C;
    nextR(R)=NULL;
    prevR(R)=NULL;
    return R;
}

void dealokasiR(addressR &P)
{
    delete P;
}

void insertFirstR(ListR &L, addressR P)
{
    if (firstR(L)==NULL)
    {
        firstR(L)=P;
        lastR(L)=P;
    }
    else
    {
        nextR(P)=firstR(L);
        firstR(L)->prevR=P;
        firstR(L)=P;
    }
}

void insertLastR(ListR &L, addressR P)
{
    if (firstR(L)==NULL)
        insertFirstR(L,P);
    else
    {
        lastR(L)->nextR=P;
        prevR(P)=lastR(L);
        lastR(L)=P;
    }
}

void deleteFirstR(ListR &L, addressR &P)
{
    if (firstR(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if (firstR(L)== lastR(L))
    {
        P = firstR(L);
        firstR(L)=NULL;
        lastR(L) = NULL;
    }
    else
    {
        P = firstR(L);
        firstR(L)=nextR(P);
        firstR(L)->prevR=NULL;
        nextR(P)=NULL;
    }
}

void deleteLastR(ListR &L, addressR &P)
{
    if (firstR(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if(firstR(L)==lastR(L))
    {
        P = firstR(L);
        firstR(L)=NULL;
        lastR(L) = NULL;
    }
    else
    {
        P = lastR(L);
        lastR(L)=prevR(P);
        lastR(L)->nextR=NULL;
        prevR(P)=NULL;
    }
}

void printInfoR(ListR L)
{
    addressR W = firstR(L);
    while(W!=NULL)
    {
        cout<<infoP(W->P).id<<endl;
        cout<<infoC(W->Q).id<<endl;
        W = nextR(W);
    }

}


addressR findElmSosialdanMahasiswa(ListR L, addressP P, addressC C)
{
    addressR W=firstR(L);
    while(W!=NULL)
    {
        if((infoP(W->P).namaweb==infoP(P).namaweb) && (infoC(W->Q).nama==infoC(C).nama))
        {
            return W;
            W = nextR(W);
        }
    }
    return NULL;
}

void insertAfterR(ListR &L, addressR Prec, addressR P)
{
    if(Prec!=NULL)
    {
        if(nextR(Prec)==NULL)
        {
            insertLastR(L, P);
        }
        else
        {
            nextR(P) = nextR(Prec);
            prevR(P) = Prec;
            prevR(nextR(Prec)) = P;
            nextR(Prec) = P;
        }
    }
    else
    {
        cout<<"gagal insert after, prec null"<<endl;
    }
}

void deleteAfterR(ListR &L, addressR &Prec, addressR &P)
{
    if(firstR(L)!=NULL)
    {
        if(Prec!=NULL&&Prec!=lastR(L))
        {
            if(nextR(Prec)==lastR(L))
            {
                deleteLastR(L,P);
            }
            else
            {
                P = nextR(Prec);
                nextR(Prec) = nextR(P);
                prevR(nextR(P)) = Prec;
                prevR(P) = NULL;
                nextR(P) = NULL;
            }
        }
        else
        {
            cout<<"gagal delete after"<<endl;
        }
    }
    else
    {
        cout<<"gagal delete after, list kosong"<<endl;
    }
}
