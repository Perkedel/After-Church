//
// Created by Hanry Ham on 2020-05-24.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Employee{
    char name[20];
    char jobPos[15];
    int grade;
    int age;
    Employee *next;
}*head = NULL, *tail = NULL;

bool isValid(char *name, char *jobPos, int grade, int age){
    // [15%] (1) INSERT YOUR CODE HERE
    struct Employee *curr = (struct Employee *) malloc(sizeof(Employee));
    curr = head;
    while(curr != NULL){
        if((strcmp(name,curr->name))&&(strcmp(jobPos,curr->jobPos))&&(grade==curr->grade)&&(age==curr->age))
            return 0;
        curr = curr->next;
    }
    
    return 1;
}

void push(char *name, char *jobPos, int grade, int age){
    struct Employee *curr = (struct Employee *) malloc(sizeof(Employee));
    // [10%] (2) INSERT YOUR CODE HERE
    // struct Employee *last = (struct Employee *) malloc(sizeof(Employee));
    if( isValid(name,jobPos,grade,age)){
        strcpy(curr->name,name);
        strcpy(curr->jobPos,jobPos);
        curr->grade=grade;
        curr->age=age;
        curr->next=head;
        head=curr;
        // head->next=curr;
        
        // tail = last
        while(curr!=NULL && curr->next!=NULL){
            
            curr=curr->next;
        }
        tail=curr;
    }else{
        printf(" The inputted data is duplicated!");
    }
}

void pop(){
    struct Employee * curr = head;
    // [15%] (3) INSERT YOUR CODE HERE
    int empCtr = 0;
    if(!curr){
        printf("the list is empty!");
    } else {
        while(curr != NULL && curr->next != NULL){
            tail=curr;
            curr=curr->next;
        }
        // curr = NULL;
        tail->next=NULL;
    }
}

void printAll(){
    printf("\n\n");
    struct Employee * curr = head;
    int empCtr = 0;
    if(!curr){
        printf("the list is empty!");
    }else{
        // [10%] (4) INSERT YOUR CODE HERE
        printf("=======================================================\n");
        printf("%20s| %15s| %6s| %7s|\n", "Name", "Job Position", "Grade", "Age");
        printf("=======================================================\n");
        while(curr != NULL){
            printf("%20s| %15s| %6d| %7d|\n", curr->name,curr->jobPos,curr->grade,curr->age);
            empCtr++;
            curr = curr->next;
        }
        printf("=======================================================\n");
        printf("Total Employee : %d\n", empCtr);
        printf("=======================================================\n");
    }
}

int main(){
    pop();
    printAll();
    push("Hanry", "Supervisor", 12, 27);
    push("Yen", "Manager", 13, 40);
    pop();
    push("Derwin", "Manager", 15, 31);
    push("Andry", "Manager", 15, 30);
    pop();
    push("Saka", "Manager", 15, 32);
    pop();
    push("Afan", "Manager", 16, 35);
    push("Fredy", "Senior Manager", 18, 45);
    pop();
    printAll();
    return 0;
}
