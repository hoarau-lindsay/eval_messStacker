#ifndef MESS_STACKER
#define MESS_STACKER


/* Définition des constantes */

#define MESS_STACKER_VERSION "v0.0.01"
#define SIZE_MAX_DATA 57

#include <stdbool.h>

char* getMessStackerVersion();

typedef struct message{
    uint8_t cmd;                 //commande (un nombre)
    char data[SIZE_MAX_DATA];    //tableau d'octet de taille SIZE_MAX_DATA
    uint8_t size;                //nombre d'octets 
    uint8_t checksum;            //checksum 
} Message;

/*API de la librairie */ 
/* Fonctions disponibles

haveMessage : indique si la file contient au moins un message 
checksumMessage : somme (cmd + data) définissant code de contrôle pour garantir l'intégrité de l'information
sendMessage : ajout d'un message dans la file de messages (stackMess)
curMessageCmd : valeur de la commande du message courant dans la file
curMessageSize : valeur de la taille du message courant
curMessagechecksum : code contrôle garantissant l'intégrité du message 
*/

bool sendMessage(uint8_t cmd, char* data, uint8_t size);

bool haveMessage();
bool nextMessage();

uint8_t curMessageCmd();
uint8_t curMessageSize();
uint8_t curMessageChecksum(); 

bool curMessageData(char* buff, int lengthMax);

uint8_t checksumMessage(uint8_t cmd, char* data, uint8_t size);


#endif