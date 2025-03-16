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

int duplicateCourse(int load, char courses[][30]){
	int courseRepeat = 0;
	for(int j = 0; j < load - 1; j++){
		for(int k = j + 1; k < load; k++){
			if(strcmp(courses[j], courses[k]) == 0)
			courseRepeat++;
		}
		if(courseRepeat > 0)
			return 1;
	}
	return 0;
}

int duplicateLanguage(char languages[]){
	// "English", "Russian", "Spanish", "French", "Lithuanian"
	int repeatEnglish = 0;
	int repeatRussian = 0;
	int repeatSpanish = 0;
	int repeatFrench = 0;
	int repeatLithuanian = 0;
	int repeatMax = 0;

	int length = strlen(languages);
	for(int i = 0; i < length; i++){
		switch(languages[i]){
			case 'E':
				repeatEnglish++;
				repeatMax = repeatEnglish;
				break;
			case 'R':
				repeatRussian++;
				repeatMax = repeatRussian;
				break;
			case 'S':
				repeatSpanish++;
				repeatMax = repeatSpanish;
				break;
			case 'F':
				repeatFrench++;
				repeatMax = repeatFrench;
				break;
			case 'L':
				repeatLithuanian++;
				repeatMax = repeatLithuanian;
				break;
		}
		if(repeatMax > 1)
			return 1;
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
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s

			if((duplicateCourse(s.load, s.courses) == 1) || (duplicateLanguage(s.languages) == 1)){
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