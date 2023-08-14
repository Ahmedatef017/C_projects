#include "student.h"
extern unsigned int counter;
extern student_t school[1000];

static string_status StringCompare(char*str1,char*str2)
{
    int i;
    for(i=0; str1[i]||str2[i]; i++)
    {
        if(str1[i]>str2[i])
        {
            return FIRST_BIGGER;
        }
        else if(str1[i]<str2[i])
        {
            return SECOND_BIGGER;
        }
        else
        {
            continue;
        }
    }
    return EQUAL;
}

static void bubbleSort(student_t*arr,int size)
{
    int i,j,sorted_flag=0;
    student_t temp;
    for(j=0; j<size-1; j++)
    {
        sorted_flag=1;
        for(i=0; i<size-1-j; i++)
        {
            if( StringCompare(arr[i].name,arr[i+1].name) == FIRST_BIGGER )
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted_flag = 0;
            }
            if(sorted_flag==1)
            {
                break;
            }
        }
    }
}
static int LinearSearch(student_t*arr,int size,char*name)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(StringCompare(arr[i].name,name)==EQUAL)
        {
            return i;
        }
    }
    return -1;
}
static int BinarySearch(student_t*arr,int size,char*name)
{
    int first,last,middel;
    first=0;
    last=size-1;
    while(first<=last)
    {
        middel=(first+last)/2;
        if( StringCompare(arr[middel].name,name) == EQUAL )
        {
            return middel;
        }
        else if( StringCompare(arr[middel].name,name) == FIRST_BIGGER )
        {
            last=middel-1;
        }
        else
        {
            first=middel+1;
        }
    }
    return -1;
}
void AddStudent(void)
{
    if(counter>1000)
    {
        printf("There Is No Space In Database TO Add More Students\n");
        return;
    }
    student_t student;
    printf("Enter The Name Of Student No  %d : ",counter+1);
    scanf("%s",student.name);
    printf("Enter The age Of Student No   %d : ",counter+1);
    scanf("%d",&(student.age));
    printf("Enter Mobile No Of Student No %d : ",counter+1);
    scanf("%d",&(student.mobile_no));
    printf("Enter GPA Of Student No       %d : ",counter+1);
    scanf("%f",&(student.gpa));
    school[counter]=student;
    counter++;
}
void EditStudent(unsigned int id)
{
    int i;
    id--;
    /*
    if(id>counter)
    {
        printf("Invalid Student ID\n");
    }*/
    for(i=0; i<=counter; i++)
    {
        if(id==i)
        {
            printf("Select One Option\n\
************************\n\
**1-Edit Name***********\n\
**2-Edit Age ***********\n\
**3-Edit Mobile Number**\n\
**4-Edit Gpa ***********\n\
**5-Edit All ***********\n\
************************\n");
Label:
            printf("Enter Choice\n");
            char ch;
            scanf(" %c",&ch);
            switch(ch)
            {
            case '1':
                printf("Enter The New Name Of Student No:%d\n",id+1);
                scanf("%s",school[i].name);
                break;

            case '2':
                printf("Enter The New age Of Student No:%d\n",id+1);
                scanf("%d",&(school[i].age));
                break;
            case '3':
                printf("Enter The New Mobile Nomber Of Student No:%d\n",id+1);
                scanf("%d",&(school[i].mobile_no));
                break;
            case '4':
                printf("Enter The New GPA Of Student No:%d\n",id+1);
                scanf("%f",&(school[i].gpa));
                break;
            case '5':
                printf("Enter The New Name   Of Student No %d: ",id+1);
                scanf("%s",school[i].name);
                printf("Enter The New age    Of Student No %d: ",id+1);
                scanf("%d",&(school[i].age));
                printf("Enter The New Mobile Of Student No %d: ",id+1);
                scanf("%d",&(school[i].mobile_no));
                printf("Enter The New GPA    Of Student No %d: ",id+1);
                scanf("%f",&(school[i].gpa));
                break;
            default:
                printf("==============\n");
                printf("Invalid Choice\n");
                printf("==============\n");
                goto Label;
            }
        }
        break;
    }
}
void PrintStudent(unsigned int id)
{
    int i;
    id--;
    if(id>=counter)
    {
        printf("==================\n");
        printf("Invalid Student ID\n");
        printf("==================\n");
        return;
    }
    for(i=0; i<counter; i++)
    {
        if(id==i)
        {
            printf("Name   of student %d   : %s\n",id+1,school[i].name);
            printf("Age    of student %d   : %d\n",id+1,school[i].age);
            printf("GPA    of student %d   : %0.2f\n",id+1,school[i].gpa);
            printf("Mobile of student %d   : 0%d\n",id+1,school[i].mobile_no);
        }
        break;
    }
}
void DeleteStudent(unsigned int id)
{
    int i,index;
    id--;
    if(id>=counter)
    {
        printf("Invalid Student ID\n");
        return;
    }
    for(i=0; i<counter-1; i++)
    {
        if(id==i)
        {
            index=i;
            for(i=index; i<counter-1; i++)
            {
                school[i]=school[i+1];
            }
            break;
        }

    }
    counter--;
}
void PrintSchool(void)
{
    int i;
    printf("====================================================\n");
    printf("Name ================ Age ===== Mobile No ====== GPA\n");
    printf("====================================================\n");
    for(i=0; i<counter; i++)
    {
        printf("%-15s     %4d       0%10d      %0.2f \n",school[i].name,school[i].age,school[i].mobile_no,school[i].gpa);
    }
}
void SortSchoolByName(void)
{
    bubbleSort(school,counter);
    printf("=========================\n");
    printf("School Sorted Successfuly\n");
    printf("=========================\n");
}
void CallStudent(unsigned char*name)
{
    bubbleSort(school,counter);
    int index = LinearSearch(school,counter,name);
    if(index!=-1)
    {
        printf("Mobile Number Of Student %d is %d",index+1,school[index].mobile_no);
    }
    else
    {
        printf("=================\n");
        printf("Student Not Found\n");
        printf("=================\n");
    }
}
void NumOfStudent(void)
{
    printf("==================================\n");
    printf("There are %d student in the school\n",counter);
    printf("==================================\n");
}
