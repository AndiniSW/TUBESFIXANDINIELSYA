//andini salimah 1301164080

#include "child.h"


void createListC(ListC &L) {
    firstC(L)=NULL;
    lastC(L)=NULL;
}

addressC alokasi(infotypeC x) {
    addressC P;
      P = new elmListC;
      infoC(P)=x;
      nextC(P)=NULL;
      prevC(P)=NULL;
    return P;
}

void dealokasiC(addressC &P) {
    delete P;
}

void insertFirstC(ListC &L, addressC P) {
    if (firstC(L)==NULL){
        firstC(L)=P;
        lastC(L)=P;
    }
    else{
        nextC(P)=firstC(L);
        firstC(L)->prev=P;
        firstC(L)=P;
    }
}

void insertLastC(ListC &L, addressC P) {
    if (firstC(L)==NULL)
        insertFirstC(L,P);
    else{
        lastC(L)->next=P;
        prevC(P)=lastC(L);
        lastC(L)=P;
    }
}

void deleteFirstC(ListC &L, addressC &P) {
    if (firstC(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if (firstC(L)== lastC(L)){
        P = firstC(L);
        firstC(L)=NULL;
        lastC(L) = NULL;
    }
    else{
      P = firstC(L);
      firstC(L)=nextC(P);
      firstC(L)->prev=NULL;
      nextC(P)=NULL;
    }
}

void deleteLastC(ListC &L, addressC &P) {
    if (firstC(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if(firstC(L)==lastC(L)){
            P = firstC(L);
            firstC(L)=NULL;
            lastC(L) = NULL;
    }
    else{
        P = lastC(L);
        lastC(L)=prevC(P);
        lastC(L)->next=NULL;
        prevC(P)=NULL;
    }
}

void printInfoC(ListC L) {
    cout<<"print info: ";
    if (firstC(L)==NULL)
        cout<<"List Kosong"<<endl;
    else{
         addressC P = firstC(L);
         while(P!=NULL) {
           cout<<infoC(P).id<<" ";
           cout<<infoC(P).nama<<" ";
           cout<<infoC(P).nim<<" ";
           cout<<infoC(P).email<<" ";
           cout<<infoC(P).alamat<<" ";
           cout<<infoC(P).nomorhape<<" ";
           P=nextC(P);
         }
         cout<<endl;
    }
}

addressC findElm(ListC L, infotypeC x) {
    addressC P = NULL;
    P = firstC(L);
    while(P!=NULL && infoC(P).id!=x.id) {
        P = nextC(P);
    }
    return P;
}

void insertAfterC(ListC &L, addressC Prec, addressC P) {
    if(Prec!=NULL) {
        if(nextC(Prec)==NULL) {
            insertLastC(L, P);
        } else {
            nextC(P) = nextC(Prec);
            prevC(P) = Prec;
            prevC(nextC(Prec)) = P;
            nextC(Prec) = P;
        }
    } else {
        cout<<"gagal insert after, prec null"<<endl;
    }
}

void deleteAfterC(ListC &L, addressC Prec, addressC &P) {
    if(firstC(L)!=NULL) {
        if(Prec!=NULL&&Prec!=lastC(L)) {
            if(nextC(Prec)==lastC(L)) {
                deleteLastC(L,P);
            } else {
                P = nextC(Prec);
                nextC(Prec) = nextC(P);
                prevC(nextC(P)) = Prec;
                prevC(P) = NULL;
                nextC(P) = NULL;
            }
        } else {
            cout<<"gagal delete after"<<endl;
        }
    } else {
        cout<<"gagal delete after, list kosong"<<endl;
    }
}
