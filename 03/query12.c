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

int languageAmount(char *languages){
	int length = strlen(languages);
	int languageNum = 1;
	for(int i = 0; i < length; i++){
		if(languages[i] == ' ')
			languageNum++;
	}
	return languageNum;
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
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		int languageMax = 0; // for counting the maximum amount of languages
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
				int languageNum = languageAmount(s.languages);
				
				if(languageNum > languageMax){
					languageMax = languageNum;
					counterDemo = 0;
				}

				if(languageNum == languageMax){
					counterDemo++;
				}
		}

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i];

			if(languageAmount(s.languages) == languageMax)
				printf("%s %s %d\n", s.name, s.surname, s.course);
		}

		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}