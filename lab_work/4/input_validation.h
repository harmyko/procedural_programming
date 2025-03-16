#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

int isTxtFile(char *fileName);
int getValidInput(int min, int max, char *message);
int isInRange(int number, int min, int max);
int isNumber(char character);
int isDecimal(char character);

#endif