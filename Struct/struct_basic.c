#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

struct student {
    int rollno;
    char name[100];
    int marks;
    float percent;
    char grade;
};


struct student students[COUNT];

void ask_data(void);
void calculate_grade(void);
void show_result(void);
void fill_data(void);
void show_menu(void);
void sort_data(void);

int choice = 1;

int main (void) {
    // ask_data();
    fill_data();
    calculate_grade();
    while( choice < 4) {
        show_result();
        show_menu();
        sort_data();
    }

    return 0;
}

void ask_data(void) {
    for (int i = 0; i < COUNT; i++) {
        students[i].rollno = i+1;
        printf("Roll no.: %d\n", students[i].rollno);

        printf("Name: ");
        scanf("%s",students[i].name);

        printf("Marks:");
        scanf("%d",&students[i].marks);
    }
}

void calculate_grade(void) {
    for (int i = 0; i < COUNT; i++) {
        students[i].percent = students[i].marks / 7.00;
        if (students[i].percent > 75) students[i].grade = 'A';
        else if (students[i].percent > 60) students[i].grade = 'B';
        else if (students[i].percent > 50) students[i].grade = 'C';
        else if (students[i].percent >= 40) students[i].grade = 'D';
        else students[i].grade = 'F';
    }
}

void show_result(void) {
    
    printf("R.No\tName\t\tMarks\tPercent\tGrade\n");
    for (int i = 0; i < COUNT; i++) {
        printf("%d\t", students[i].rollno);
        printf("%s\t\t", students[i].name);
        printf("%d\t", students[i].marks);
        printf("%.2f\t", students[i].percent);
        printf("%c\t\n", students[i].grade);
    }

}

void fill_data(void) {
    int i = 0;
    students[0].rollno = i+1;
    strcpy(students[0].name, "Ghi");
    students[0].marks = 600;
    i += 1;
    students[1].rollno = i+1;
    strcpy(students[1].name, "Jkl");
    students[1].marks = 410;
    i += 1;
    students[2].rollno = i+1;
    strcpy(students[2].name, "Abc");
    students[2].marks = 500;
    i += 1;
    students[3].rollno = i+1;
    strcpy(students[3].name, "Def");
    students[3].marks = 300;        
}

void show_menu(void) {
    printf("Sort by:");
    printf("\n1. Roll No");
    printf("\n2. Name");
    printf("\n3. Marks");
    printf("\n4. Exit");
    printf("\nEnter the choice: ");
    scanf("%d", &choice);    
}

void sort_data(void) {
    struct student temp;
    switch(choice) {
        case 2: 
            for (int i = 0; i < COUNT-1; i++) {
                for (int j = i; j < COUNT-1; j++) {
                    if (students[i].name[0] > students[j].name[0]) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        case 3: 
            for (int i = 0; i < COUNT-1; i++) {
                for (int j = 0; j < COUNT-i-1; j++) {
                    if (students[i].marks < students[j].marks) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        default: 
            for (int i = 0; i < COUNT-1; i++) {
                for (int j = i; j < COUNT-1; j++) {
                    if (students[i].rollno > students[j].rollno) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;

    }
}