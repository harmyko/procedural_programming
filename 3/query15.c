#include <stdio.h>
#include <stdlib.h>

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

double highestGrade(double average[], int size){
	double highestGrade = 0;
	for(int i = 0; i < size; i++){
		if(average[i] > highestGrade)
		highestGrade = average[i];
	}
	return highestGrade;
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

		double averages[size];
		for(int i = 0; i < size; i++){
			averages[i] = students[i].average;
		}
		
		int counterDemo = 0; // for counting students
		double maxGrade = highestGrade(averages, size);

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if((s.average >= maxGrade - 1) && (s.average < maxGrade)){
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