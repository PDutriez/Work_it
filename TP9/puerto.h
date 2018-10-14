#ifndef PUERTO_H
#define PUERTO_H

void maskToggle(char registro,int mask);
void maskOff(char registro,int mask);
void maskOn(char registro,int mask);
void bitGet(char registro,int bit);
void bitToggle(char registro,int bit);
void bitClr(char registro,int bit);
void bitSet(char registro,int bit);
#endif
