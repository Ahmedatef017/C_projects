#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
unsigned int counter=0;
student_t school[1000];

int main()
{
    char choice;
    int id;
    char string[20];

    while(1)
    {
        printf("\n\nselect one option from menu:\n\
===============================+\n\
1] Add Student                 |\n\
2] Edit Student                |\n\
3] Print Student               |\n\
4] Delete Student              |\n\
5] Print School                |\n\
6] Call Student                |\n\
7] Print Number Of Students    |\n\
8] Sort School Based On name   |\n\
9] Exit                        |\n\
===============================+\n\n");
        printf("Enter Choice\n");
        scanf(" %c",&choice);
        switch(choice)
        {
        case '1':
            AddStudent();
            break;
        case '2':
            printf("Enter ID: ");
            scanf("%d",&id);
            EditStudent(id);
            break;
        case '3':
            printf("Enter ID: ");
            scanf("%d",&id);
            PrintStudent(id);
            break;
        case '4':
            printf("Enter ID\n");
            scanf("%d",&id);
            DeleteStudent(id);
            break;
        case '5':
            PrintSchool();
            break;
        case '6':
            printf("Enter Student Name To Get Its Mobile Number\n");
            scanf("%s",string);
            CallStudent(string);
            break;
        case '7':
            NumOfStudent();
            break;
        case '8':
            SortSchoolByName();
            break;
        case '9':
            exit(0);
        default :
            printf("Invalid Choice\n");
        }
    }
    return 0;

}
