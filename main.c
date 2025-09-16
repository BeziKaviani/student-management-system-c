# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// Static variables
# define STUDENT_ID_LEN 11
# define FIRST_NAME_LEN 80
# define LAST_NAME_LEN 80
# define MAX_STUDENT_COUNT 300

// The index that is going to be filled by using add function
int student_counter = 0;

// Student struct
struct student {
    char student_id[STUDENT_ID_LEN];
    char first_name[FIRST_NAME_LEN];
    char last_name[LAST_NAME_LEN];
    float average;
} university_students[MAX_STUDENT_COUNT];
typedef struct student Student;

// Functions
int launcher() {
    int choice;
    puts("\n\nWelcome to student manager. Select between the options : ");
    puts("1-Show all students' details");
    puts("2-Add student");
    puts("3-Remove student");
    puts("4-Search student");
    puts("5-Sort students base on average score");
    puts("6-Save students' list in a file");
    puts("7-Load the students from a file");
    puts("0-Exit");
    puts("-----------------------------------------");
    scanf("%d", &choice);
    return choice;
}

void particulars_initializer(char *std_id, char *std_first_name, char *std_last_name, float *std_average) {
    puts("Enter the student's ID:");
    scanf("%s", std_id);
    puts("Enter the student's first name:");
    scanf("%s", std_first_name);
    puts("Enter the student's last name:");
    scanf("%s", std_last_name);
    puts("Enter the student's average:");
    scanf("%f", &*std_average);
}

void printStudentsList(Student *students) {
    for (int i = 0; i < student_counter; ++i) {
        printf("{%s, %s, %s, %f}\n", students[i].student_id, students[i].first_name, students[i].last_name,
               students[i].average);
    }
}

int findStudentIndex(Student *students, const char *std_id) {
    for (int i = 0; i < student_counter; i++) {
        if (strcmp(students[i].student_id, std_id) == 0) {
            return i;
        }
    }
    return -1;
}

void removeStudent(Student *students, char *std_id) {
    int std_index = findStudentIndex(students, std_id);
    if (std_index != -1) {
        for (int i = std_index; i < student_counter; ++i) {
            students[i] = students[i + 1];
        }
        student_counter--;
    } else {
        puts("ID not found");
    }
}

void add(Student *students, char *std_id, char *std_first_name, char *std_last_name, float std_average) {
    strcpy(students[student_counter].student_id, std_id);
    strcpy(students[student_counter].first_name, std_first_name);
    strcpy(students[student_counter].last_name, std_last_name);
    students[student_counter].average = std_average;
    student_counter++;
}


void sort(Student *students) {
    Student selected_student;
    int j;
    for (int i = 1; i < student_counter; i++) {
        selected_student = students[i];
        j = i - 1;
        while (j >= 0 && selected_student.average < students[j].average) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = selected_student;

    }
}

void saveStudentsList(Student *students) {
    FILE *f_students;
    f_students = fopen("Student's list.txt", "w");
    if (f_students == NULL) {
        puts("Sorry. The file can't be opened");
        return;
    }
    for (int i = 0; i < student_counter; ++i) {
        char *s_average[100];
        gcvt(students[i].average, 4, s_average);
        fprintf(f_students, "{%s, %s, %s, %s}\n", students[i].student_id, students[i].first_name,
                students[i].last_name, s_average);
    }

    fclose(f_students);
}

void loadStudentsList(Student *students) {
    FILE *f_students;
    f_students = fopen("Student's list.txt", "r");
    if (f_students == NULL) {
        puts("Sorry. The file can't be opened");
        return;
    }

    char buffer[300];
    student_counter = 0;

    while (fgets(buffer, sizeof(buffer), f_students) != NULL) {
        char std_id[STUDENT_ID_LEN];
        char std_first_name[FIRST_NAME_LEN];
        char std_last_name[LAST_NAME_LEN];
        float std_average;

        if (sscanf(buffer, "{%10[^,], %79[^,], %79[^,], %f}",
                   std_id, std_first_name, std_last_name, &std_average) == 4) {
            strcpy(students[student_counter].student_id, std_id);
            strcpy(students[student_counter].first_name, std_first_name);
            strcpy(students[student_counter].last_name, std_last_name);
            students[student_counter].average = std_average;
            student_counter++;
        } else {
            puts("Error: Invalid data format");
        }
    }

    fclose(f_students);
    puts("Students successfully loaded from file.");
}


int main() {
    int wantsToContinue = 1;
    while (wantsToContinue) {
        char std_id[STUDENT_ID_LEN];
        char std_first_name[FIRST_NAME_LEN];
        char std_last_name[LAST_NAME_LEN];
        float std_average = 0;
        int std_index;
        switch (launcher()) {
            case 0:
                wantsToContinue = 0;
                break;
            case 1:
                printStudentsList(university_students);
                break;
            case 2:
                particulars_initializer(std_id, std_first_name, std_last_name, &std_average);
                add(university_students, std_id, std_first_name, std_last_name, std_average);
                break;
            case 3:
                puts("Please enter the ID:");
                scanf("%s", std_id);
                removeStudent(university_students, std_id);
            case 4:
                puts("Please Enter the ID");
                scanf("%s", std_id);
                std_index = findStudentIndex(university_students, std_id);
                if (std_index != -1) {
                    printf("{%s, %s, %s, %f}", university_students[std_index].student_id,
                           university_students[std_index].first_name, university_students[std_index].last_name,
                           university_students[std_index].average);
                } else {
                    puts("ID not found");
                }
            case 5:
                sort(university_students);
                break;
            case 6:
                saveStudentsList(university_students);
                break;
            case 7:
                loadStudentsList(university_students);
                break;
            default:
                puts("Something went wrong! Try again.");
        }
    }
    return 0;
}