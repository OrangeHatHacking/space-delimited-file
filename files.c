#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct date {
	int day, month, year;
};

struct student {
	int studentID;
	char firstName[20];
	char lastName[20];
	char courseID[10];
	int year;
	struct date registrationDate;
	struct date dateOfBirth;
	int averageGrade;
};


int main() {
	struct student students[2];
	FILE *txtFile = fopen("C:\\students.txt", "r");
	if (txtFile == NULL) {
		printf("Error accessing file");
	}

	char fullFile[200];
	int studentNum = 0;
	while (fgets(fullFile, 200, txtFile) != NULL) {
		char temp[20];
		int x = 0;
		for (int i = 0; i < strlen(fullFile); i++) {
			if (fullFile[i] != ' ') {
				temp[x] = fullFile[i];
				x++;
			}
			else {
				temp[x] = '\0';
				strcpy(students[studentNum].firstName, temp);
				strcpy(students[studentNum].lastName, temp);
				strcpy(students[studentNum].courseID, temp);
				students[studentNum].studentID = atoi(temp);
				students[studentNum].year = atoi(temp);
				students[studentNum].registrationDate.day = atoi(temp);
				students[studentNum].registrationDate.month = atoi(temp);
				students[studentNum].registrationDate.year = atoi(temp);
				students[studentNum].dateOfBirth.day = atoi(temp);
				students[studentNum].dateOfBirth.month = atoi(temp);
				students[studentNum].dateOfBirth.year = atoi(temp);
				}
				x = 0;
			}
		
		srand((unsigned)time(NULL));
		students[studentNum].averageGrade = (rand() % 101);
		studentNum++;
		fclose(txtFile);
	}
	txtFile = fopen("C:\\students.txt", "w", txtFile);
	for (int i = 0; i < studentNum; i++) {
		fprintf(txtFile, "%d %s %s %s %d %d %d %d %d %d %d %d\n", students[i].studentID, students[i].firstName, students[i].lastName, students[i].courseID, students[i].year, students[i].registrationDate.day, students[i].registrationDate.month, students[i].registrationDate.year, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, students[i].averageGrade);
	}
	fclose(txtFile);
	return 0;
}
