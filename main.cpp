//elsya putri sutomo 1301164201
#include <iostream>
#include "aplikasi.h"
// #include <conio.h>

using namespace std;

ListC L;
ListP Lp;
ListR Lr;

int main()
{
	createListC(L);
    createListP(Lp);
    createListR(Lr);
    menu(Lp, L, Lr);
    return 0;
}
