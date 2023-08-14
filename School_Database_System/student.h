#ifndef __STUDENT_H__
#define __STUDENT_H__

typedef enum{
    FIRST_BIGGER,
    SECOND_BIGGER,
    EQUAL
}string_status;

typedef struct{
    unsigned char name[20];
    unsigned int age;
    unsigned long long mobile_no;
    float gpa;
}student_t;

void AddStudent(void);
void EditStudent(unsigned int id);
void PrintStudent(unsigned int id);
void DeleteStudent(unsigned int id);
void PrintSchool(void);
void CallStudent(unsigned char*name);
void NumOfStudent(void);
void SortSchoolByName(void);



#endif // __STUDENT_H__
