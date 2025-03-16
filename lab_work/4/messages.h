#ifndef MESSAGES_H
#define MESSAGES_H

const char introduction[] = 
    "This program reads events' participant result data from a .txt file "
    "and saves the data in a linked list.\n"
    "This program allows the user to remove the participant with highest score from the list.\n"
    "An example of the data file has been provided in this program's directory "
    "under the name \"data.txt\".\n"
    "Feel free to use the provided .txt file for testing the functionality "
    "of this program.\n";

const char enterFileName[] = "Enter the data file's name (enter \"data.txt\" to use my prepared data) >> ";
const char fileError[] = "Could not open file!";
const char tryAgain[] = "Please try again...";
const char fileSuccess[] = "The file has been opened successfully!";

const char topFound[] = "The participant with the highest score has been found!";
const char pName[] = "- Participant's name:";
const char pScore[] = "- Participant's score:";
const char question[] = "Do you wish to delete this participant from the list?";
char options[] = "- Enter 1 to delete\n- Enter 0 to keep\n- Your choice >> ";
const char deleting[] = "is being deleted from the list...";

const char participants[] = "This is the complete list of all current participants:";
const char noParticipants[] = "There are no participants on the list!";

#endif