#include <stdio.h>
#include <stdlib.h>

typedef struct
 {
  int nbBuff; // Nb char currently in the buffer
  int maxBuff; // nb max of items in the buffer
  char * tabBuff;
} Buffer;

void clearBuff(Buffer * thisBuff)
{
  thisBuff->nbBuff = 0;
}

void initBuff (Buffer * thisBuff, int maxSize)
{
  thisBuff->maxBuff = maxSize;
  thisBuff->tabBuff = (char *) malloc(thisBuff->maxBuff+1); // +1 to have enough space for the '\0' ending  character
  clearBuff(thisBuff);
}

void addBuff(Buffer * thisBuff, char c)
{
  if (thisBuff->nbBuff < thisBuff->maxBuff)
  {
    (thisBuff->tabBuff) [thisBuff->nbBuff] = c;
    thisBuff->nbBuff ++;
    (thisBuff->tabBuff) [thisBuff->nbBuff] = '\0';
  }
}

void showBuff(Buffer * thisBuff)
{
  for (int i=0; i<thisBuff->nbBuff; i++)
  {
    printf("%c",(thisBuff->tabBuff)[i]);
  }
}

void processBuff(Buffer * thisBuff, char specialKey)
{
  if (thisBuff->nbBuff > 0 && thisBuff->nbBuff < thisBuff->maxBuff && thisBuff->tabBuff[0] == specialKey && thisBuff->tabBuff[thisBuff->nbBuff-1] == specialKey)
    printf("Admin command detected");
  else
    printf("%i caracters long entry code detected", thisBuff->nbBuff);
}

int main() {

  Buffer b[2]; 
  Buffer * pFirstBuff = b;
  Buffer * pSecondBuff = &(b[1]);  //recalling &(b[0]) = b, then &(b[1]) corresponds to the pointer on the second element of the array
  
  initBuff(pFirstBuff,12);
  initBuff(pSecondBuff,32);
  
  char s[80];
  sprintf(s,"Hello, world! How are you today?");

  for (int i=0;i<sizeof(s);i++) 
    {
      addBuff(pFirstBuff,s[i]);
      addBuff(pSecondBuff,s[i]);
    }


  showBuff(pFirstBuff);
  printf("\n");

  showBuff(pSecondBuff);
  printf("\n");
  
  processBuff(pSecondBuff,'#');

  printf("\n");
  return 0;
}
  
