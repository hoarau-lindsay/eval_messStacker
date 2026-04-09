/*messStacker.c*/

#include "messStacker.h"

#define SIZE_STACK 30

//initialisation variables globales 

Message stackMess[SIZE_STACK];  //file de message (tableau circulaire)
int lastPos = -1;               //position du dernier message (le + recent)
int curPos = 0;                 //message courant 
int messCount = 0;              //nombre de message présent 

/* Fonctions disponibles
getMessStackerVersion : version du la librairie
haveMessage : indique si la file contient au moins un message 

*/

char* getMessStackerVersion(){
    return MESS_STACKER_VERSION;
}


bool haveMessage(){
    /*Indique si la file contient au moins un message

    Paramètre : aucun

    Retourne : 
        true : si la file contient un message 
        false : si la file ne contient aucun message (messCount = 0)
    
    */
    return messCount != 0;
}

    