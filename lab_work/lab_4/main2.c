#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "messages.h"
#include "input_validation.h"

#define BUFFER_SIZE 1024
#define MAX_NAME_LENGTH 30
#define MAX_PARTICIPANTS 1000

typedef struct{
    char name[MAX_NAME_LENGTH];
    double score;
} Participant;

int writeToBuffer(FILE *file, char *buffer);
void extractNamesAndScores(char *buffer, List *list, unsigned *numParticipants);
Participant *createParticipant(char *name, double score);
void deleteTopParticipant(List *list);
int chooseToDelete(Participant *maxParticipant);
void printParticipants(List *list);

int main(){
    printf("\n%s\n", introduction);

    FILE *dataFile;
    char fileName[MAX_NAME_LENGTH];

    int fileOpened = 0;
    while(!fileOpened){
        printf("%s", enterFileName);
        scanf("%s", &fileName);

        if(isTxtFile(fileName)){
            dataFile = fopen(fileName, "r");
            if(dataFile != NULL){
                fileOpened = 1;
            }
        }

        if(!fileOpened){
           printf("%s %s\n", fileError, tryAgain); 
        }

        while(getchar() != '\n');
    }
    printf("%s\n", fileSuccess);

    char buffer[BUFFER_SIZE];
    unsigned numParticipants = 0;
    List *participantList = createList();

    while(writeToBuffer(dataFile, buffer)){
        extractNamesAndScores(buffer, participantList, &numParticipants);
    }

    fclose(dataFile);

    printParticipants(participantList);
    deleteTopParticipant(participantList);
    printParticipants(participantList);

    destroyList(participantList);

    return 0;
}

int writeToBuffer(FILE *file, char *buffer){
    unsigned lastPos = ftell(file);
    int bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE - 1, file);

    if(bytesRead == 0){
        return 0;
    }

    // ensuring the buffer ends at '\n' or EOF
    if(bytesRead == BUFFER_SIZE - 1){
        int backtrackIndex = bytesRead - 1;

        while(backtrackIndex >= 0 && buffer[backtrackIndex] != '\n'){
            --backtrackIndex;
        }

        if(backtrackIndex >= 0){
            fseek(file, backtrackIndex - bytesRead + 1, SEEK_CUR);
            buffer[backtrackIndex] = '\0';
        }
    }
    else{
        buffer[bytesRead] = '\0';
    }

    unsigned currentPos = ftell(file);
    if(lastPos == currentPos){
        // participant's name and score is longer than BUFFER_SIZE - 1 characters
        return 0;
    }

    return bytesRead;
}

void extractNamesAndScores(char *buffer, List *list, unsigned *numParticipants){
    char *line = strtok(buffer, "\n");

    while(line != NULL){
        char name[MAX_NAME_LENGTH];
        double score;

        if(sscanf(line, "%s %lf", name, &score) == 2){
            insertElement(list, createParticipant(name, score), *numParticipants);
            ++(*numParticipants);
        }

        if(*numParticipants >= MAX_PARTICIPANTS){
            return;
        }

        line = strtok(NULL, "\n");
    }
}

Participant *createParticipant(char *name, double score){
    Participant *newParticipant = (Participant *)malloc(sizeof(Participant));
    if(newParticipant == NULL){
        return NULL;
    }
    
    strncpy(newParticipant->name, name, MAX_NAME_LENGTH - 1);
    newParticipant->name[MAX_NAME_LENGTH - 1] = '\0';
    newParticipant->score = score;
    
    return newParticipant;
}

void deleteTopParticipant(List *list){
    if(list == NULL || list->head == NULL){
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;
    Node *maxCurrent = list->head;
    Node *maxPrevious = NULL;

    Participant *currentParticipant;
    Participant *maxParticipant;

    while(current != NULL){
        currentParticipant = (Participant *)current->data;
        maxParticipant = (Participant *)maxCurrent->data;

        if(currentParticipant->score > maxParticipant->score){
            maxCurrent = current;
            maxPrevious = previous;
        }

        previous = current;
        current = current->next;
    }

    if(chooseToDelete(maxParticipant)){
        printf("\n%s %s\n", maxParticipant->name, deleting);
        if(maxCurrent == list->head){
            list->head = maxCurrent->next;
        }
        else{
            maxPrevious->next = maxCurrent->next;
        }

        free(maxCurrent->data);
        free(maxCurrent);

        --(list->size);
    }
}

int chooseToDelete(Participant *maxParticipant){
    printf("%s\n%s %s\n%s %.2f\n", topFound, pName, maxParticipant->name, pScore, maxParticipant->score);
    printf("%s\n", question);

    return getValidInput(0, 1, options);
}

void printParticipants(List *list){
    if(list == NULL || list->head == NULL){
        printf("\n%s\n", noParticipants);
        return;
    }

    Node *current = list->head;
    int index = 0;

    printf("\n%s\n", participants);
    while(current != NULL){
        Participant *participant = (Participant *)current->data;
        printf("%d. Name: %s, Score: %.2f\n", index + 1, participant->name, participant->score);
        current = current->next;
        ++index;
    }
    printf("\n");
}