#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LENGTH 10
#define NAME_LENGTH 40
typedef struct Student_t {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;
    struct Student_t *next;
} Student;

Student *add_student(Student *root, Student *to_add);
void print_list(Student *root);
int main(){
    Student *root = NULL;
    Student s1, s2, s3, s4;
    strcpy(s1.id, "1");
    strcpy(s2.id, "2");
    strcpy(s3.id, "3");
    strcpy(s4.id, "4");
    strcpy(s1.name, "Nguyen Van A");
    strcpy(s2.name, "Nguyen Van B");
    strcpy(s3.name, "Nguyen Van C");
    strcpy(s4.name, "Nguyen Van D");
    s1.grade = 7;
    s2.grade = 8;
    s3.grade = 9;
    s4.grade = 10;
    root = add_student(root, &s1);
    root = add_student(root, &s2);
    root = add_student(root, &s3);
    root = add_student(root, &s4);
    print_list(root);
    
    return 0;
}
void print_list(Student *root){
    for(Student *p = root; p != NULL; p = p->next){
        printf("ID: %s\tName: %s\tGrade: %d\n", p->id, p->name, p->grade);
    }
}
Student *add_student(Student *root, Student *to_add){
    Student *curr_std, *prev_std = NULL;
    if (root == NULL) return to_add;
    if (to_add->grade > root->grade) {
        to_add->next = root;
        return to_add;
    }
    curr_std = root;
    while (curr_std != NULL && to_add->grade < curr_std->grade) {
        prev_std = curr_std;
        curr_std = curr_std->next;
    }
    prev_std->next = to_add;
    to_add->next = curr_std;
    return root;
}
