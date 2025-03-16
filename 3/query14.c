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

void courseStudentAmount(Student students[], char courseNames[][30], int courseStudents[], int size) {

	for(int i = 0; i < size; i++){
		Student s = students[i]; // store data for each student in s
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < s.load; k++){
				if(strcmp(s.courses[k], courseNames[j]) == 0){
					courseStudents[j]++;
					break;
				}
			}
		}
	}
}

void coursesWithSingleStudent(char courseNames[][30], int courseStudents[], char singleStudentCourses[][30], int *singleStudentCourseAmount){
	*singleStudentCourseAmount = 0;
	for(int i = 0; i < 10; i++){
		if(courseStudents[i] == 1){
			strcpy(singleStudentCourses[*singleStudentCourseAmount], courseNames[i]);
			(*singleStudentCourseAmount)++;
		}
	}
}

int studentIsAloneInCourse(int singleStudentCourseAmount, char singleStudentCourses[][30], char courses[][30], int load){
	for(int i = 0; i < load; i++){
		for(int j = 0; j < singleStudentCourseAmount; j++){
			if(strcmp(courses[i], singleStudentCourses[j]) == 0)
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
		Student students[1000];
		int size = 0;					// how many students in database

		char courseNames[10][30] = {
		"Algebra", "Computer programming", "Operating systems", "Physics", "Philosophy",
		"Calculus", "Set theory", "Algorithms", "Discrete mathematics", "Computer networks"};
		char singleStudentCourses[10][30];
		int courseStudents[10] = {0};
		int singleStudentCourseAmount;
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students

		courseStudentAmount(students, courseNames, courseStudents, size); // calculates the amount of students in each course
		coursesWithSingleStudent(courseNames, courseStudents, singleStudentCourses, &singleStudentCourseAmount); // figures out which courses have 1 student

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s

			if(studentIsAloneInCourse(singleStudentCourseAmount, singleStudentCourses, s.courses, s.load) != 1){
				printf("%s %s %d\n", s.name, s.surname, s.course);
				++counterDemo;
			}
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}