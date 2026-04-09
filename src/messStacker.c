/*messStacker.c*/

#include "messStacker.h"

#define SIZE_STACK 30

//initialisation variables globales 

Message stackMess[SIZE_STACK];  //file de message (tableau circulaire)
int lastPos = -1;               //position du dernier message (le + recent)
int curPos = 0;                 //message courant 
int messCount = 0;              //nombre de message présent 


char* getMessStackerVersion(){
    return MESS_STACKER_VERSION;
}
    

