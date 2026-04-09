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
checksumMessage : somme (cmd + data) définissant code de contrôle pour garantir l'intégrité de l'information
curMessageCmd : valeur de la commande du message courant dans la file
curMessageSize : valeur de la taille du message courant
curMessagechecksum : code contrôle garantissant l'intégrité du message 
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

uint8_t checksumMessage(uint8_t cmd, char* data, uint8_t size){
    /*Code de contrôle pour garantir l'intégrité de l'information
    Calcul la somme de l'ensemble commande + un bloc d'octet data

    Paramètres : 
        cmd : commande (un nombre)
        data : tableau d'octet 
        size : nombre d'octet à considérer pour le contenu dans le tableau data 

    Retourne : 
        somme : somme de l'ensemble cmd + data 
    */

    uint8_t somme = cmd; 
    for(int i = 0; i < size; i++){
        somme += (uint8_t)data[i];
    }

    return somme;
}

bool sendMessage(uint8_t cmd, char* data, uint8_t size){
    /* Ajout d'un message dans la file de messages (stackMess)

    Paramètres : 
        cmd : commande (un nombre)
        data : tableau d'octet 
        size : nombre d'octet à considérer pour le contenu dans le tableau data 

    Retourne : 
        - true : si le message a été ajouté 
        - false : si la file est pleine (message non ajouté)
    */

    if (messCount >= SIZE_STACK){
        printf("La file est pleine");
        return false; 
    }

    lastPos = (lastPos + 1) % SIZE_STACK;

    stackMess[lastPos].cmd = cmd; 
    for (uint8_t i = 0; i < size; i++) {
        stackMess[lastPos].data[i] = data[i];
    }
    stackMess[lastPos].size = size;
    stackMess[lastPos].checksum = checksumMessage(cmd, data, size);

    messCount += 1;

    return true;
}

uint8_t curMessageCmd(){
    /* Valeur de la commande du message courant dans la file 

    Paramètre : aucun 

    Retourne : 
        - stackMess[curPos].cmd : la valeur de cmd du mesage courant
        - 0 si la file est vide 

    */
    if (messCount == 0){ 
        printf("Il n'y a pas de message");
        return 0;
    }
    return stackMess[curPos].cmd;
}

uint8_t curMessageSize(){
    /* Valeur de la taille du message courant
    
    Paramètre : aucun 

    Retourne : 
        - stackMess[curPos].size : valeur size du message courant 
        - 0 si la file est vide 
    */
    if (messCount == 0){ 
        printf("Il n'y a pas de message");
        return 0;
    }
    return stackMess[curPos].size;
}

uint8_t curMessageChecksum(){
    /* code contrôle garantissant l'intégrité du message 
    
    Paramètre : aucun 
    
    Retourne:
        - stackMess[curPos].checksum : valeur checksum du message courant 
        - 0 si la file est vide 
    */

    if (messCount == 0){ 
        printf("Il n'y a pas de message");
        return 0;
    }
    return stackMess[curPos].checksum; 
}

