#include <stdio.h>
#include <stdlib.h>


//we will a buffer to store keystroke

int nbBuff; // Nb char currently in the buffer
int maxBuff; // nb max of items in the buffer
char * tabBuff;

void clearBuff(void)
{
  nbBuff = 0;
}

void initBuff (int maxSize)
{
  maxBuff = maxSize;
  tabBuff = (char *) malloc(maxBuff+1); // +1 to have enough space for the '\0' ending  character
  clearBuff();
}

void addBuff(char c)
{
  if (nbBuff < maxBuff)
  {
    tabBuff[nbBuff] = c;
    nbBuff++;
    tabBuff[nbBuff] = '\0';
  }
  //TODO: what to do in else case
}

void showBuff()
{
  for (int i=0; i<nbBuff; i++)
  {
    printf("%c",tabBuff[i]);
  }
}

void processBuff(char specialKey)
{
  if (nbBuff > 0 && nbBuff < maxBuff && tabBuff[0] == specialKey && tabBuff[nbBuff-1] == specialKey)
    printf("Admin command detected");
  else
    printf("%i caracters long entry code detected", nbBuff);
}

int main() {
  initBuff(12);
  char s[80];
  sprintf(s,"Hello, world! How are you today?");

  for (int i=0;i<sizeof(s);i++) 
    {
      addBuff(s[i]);
    }

  showBuff();
  printf("\n");
  processBuff('#');
  printf("\n");
  return 0;
}
