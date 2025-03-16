#ifndef FILE_H
#define FILE_H

void saveToFile(const char *filename, int *arr, int size);
int *loadFromFile(const char *filename, int *size);

#endif