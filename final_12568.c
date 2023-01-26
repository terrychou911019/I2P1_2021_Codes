#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//no need to submit
typedef struct _Node{
    int data;
    struct _Node* next;
} Node;

//#include"function.h"
//
void Push(Node** ptr_head, int x) {
    Node *tr = (Node *)malloc(sizeof(Node));
    tr->next = *ptr_head;
    tr->data = x;
    *ptr_head = tr;
}
void Pop(Node** ptr_head) {
    if (*ptr_head == NULL) return;
    Node *tmp = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(tmp);
}
void Reverse_List(Node** ptr_head) {
    if (*ptr_head == NULL) return;
    Node *tmp = NULL, *tail = NULL, *head = *ptr_head;
    while (head->next != NULL) {
        tmp = head->next;
        head->next = tail;
        tail = head;
        head = tmp;
    }
    head->next = tail;
    *ptr_head = head;
}
//

void Print_List(Node* head);
void Delete_List(Node* head);

int main(){
    char op[10];
    Node* head = NULL;
    while( ~scanf("%s", op) ){
        if( strcmp(op, "push") == 0 ){
            int x;
            scanf("%d", &x);
            Push(&head, x);
        }
        if( strcmp(op, "pop") == 0 ){
            Pop(&head);
        }
        if( strcmp(op, "reverse") == 0 ){
            Reverse_List(&head);
        }
        if( strcmp(op, "print") == 0 ){
            Print_List(head);
        }
    }

    Delete_List(head);
    head = NULL;

    return 0;
}
void Print_List(Node* head){
    if( head == NULL ){
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if( head->next != NULL ) printf(" -> ");
    Print_List(head->next);
}

void Delete_List(Node* head){
    if( head == NULL ) return;
    Delete_List(head->next);
    free(head);
}