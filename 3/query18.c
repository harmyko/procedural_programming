#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;

void nameAndSurnameFrequency(int size, char names[][30], char surnames[][30], char studentNames[][30], char studentSurnames[][30], int nameFrequency[], int surnameFrequency[]){
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < size; j++){
			if(strcmp(names[i], studentNames[j]) == 0)
				nameFrequency[i]++;
			if(strcmp(surnames[i], studentSurnames[j]) == 0)
				surnameFrequency[i]++;
		}
	}
}

int isUnique(char names[][30], char surnames[][30], char studentName[], char studentSurname[], int nameFrequency[], int surnameFrequency[]){
	for(int i = 0; i < 30; i++){
		if((nameFrequency[i] == 1) || (surnameFrequency[i] == 1)){
			if((strcmp(names[i], studentName) == 0) || (strcmp(surnames[i], studentSurname) == 0))
			 return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database

	char names[30][30] = { 
		"Alex", "Robert", "Jessie", "Adam", "Sole", 
		"Jamie", "Jenny", "Alice", "Victor", "Charlie", 
		"Matt", "Jerry", "George", "Jim", "Luke", 
		"Debora", "Kim", "Melissa", "Richard", "Julie", 
		"Angelina", "Betty", "Helen", "Jane", "Sarah", 
		"Kylie", "Arnold", "Karl", "Wilhelm", "Eve" 
	};
	char surnames[30][30] = { 
		"Smith", "Doe", "Perry", "Brightman", "Lockwood", 
		"Enderman", "Brighthill", "Sleight", "Note", "Wood", 
		"Sheen", "Hudson", "King", "de Vito", "Norman", 
		"Leben", "Quarry", "Hat", "Damon", "Thornton", 
		"Davison", "Madsen", "Stapleton", "Wozniak", "Darry", 
		"Sadman", "Gibbs", "Gibson", "Druddle", "Kesting"
	};
		
	int nameFrequency[30] = {0};
	int surnameFrequency[30] = {0};
	char studentNames[1000][30];
	char studentSurnames[1000][30];

		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW

		for(int i = 0; i < size; i++){
			strcpy(studentNames[i], students[i].name);
			strcpy(studentSurnames[i], students[i].surname);
		}

		nameAndSurnameFrequency(size, names, surnames, studentNames, studentSurnames, nameFrequency, surnameFrequency);
		
		int counterDemo = 0; // for counting students
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s

			if(isUnique(names, surnames, s.name, s.surname, nameFrequency, surnameFrequency)){
				printf("%s %s %d\n", s.name, s.surname, s.course);
				++counterDemo; // counting studfents
			}
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}