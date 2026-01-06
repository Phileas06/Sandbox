#include <stdio.h>
#include <string.h>
#define MAX_ZEICHEN 99
#define MAX_STUDENTS 10

typedef struct Student {
    int matrikelnummer;
    char name[MAX_ZEICHEN];
    float note;
} Student;

float durchschnitt_berechnen(Student StudentenArray[], int anzahlStudierende) {
    if (anzahlStudierende < 1) return -1;

    float durchschnitt = 0;
    for (int i = 0; i < anzahlStudierende; ++i) {
        
        durchschnitt += StudentenArray[i].note;
    }

    durchschnitt /= anzahlStudierende;

    return durchschnitt;

}

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Student StudentenArray[MAX_STUDENTS];
    int anzahlStudierende = 0;
    char format_name[20];

    sprintf(format_name, "%%%ds", MAX_ZEICHEN - 1);


    char name[MAX_ZEICHEN];

    for (int i = 0; i < 3; ++i) {
        printf("Gib den Namen des Studenten ein: \n");
        scanf(format_name, name);
        flushStdin();
        strcpy(StudentenArray[i].name, name);

        printf("Gib die Note des Studenten ein: \n");
        scanf("%f", &StudentenArray[i].note);
        flushStdin();

        StudentenArray[i].matrikelnummer = anzahlStudierende++;
    }

    float durchschnitt = durchschnitt_berechnen(StudentenArray, anzahlStudierende);

    printf("%f", durchschnitt);

    return 0;
}