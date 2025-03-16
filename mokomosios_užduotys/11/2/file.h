#ifndef FILE_H
#define FILE_H

extern unsigned int readCount;
extern unsigned int writeCount;
void saveToFile(const char *filename, int *arr, int size);
int *loadFromFile(const char *filename, int *size);

#endif