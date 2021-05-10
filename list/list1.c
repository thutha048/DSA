// DELETION
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address{
    char name[20];
    int tel;
    char email[30];
}Address;

typedef struct AddressList{
    struct AddressList *next;
    Address addr;
}AddressList;

AddressList *root = NULL;
AddressList *insert_after(AddressList *root, Address ad, AddressList ** cur);
AddressList *delete(AddressList *root, AddressList **cur);
void print_list(AddressList *root);

int main(){
    AddressList *cur = NULL;
    Address a;
    strcpy(a.name, "Nguyen Van A");
    a.tel = 123;
    strcpy(a.email, "a@gmail.com");
    root = insert_after(root, a, &cur);
    Address b;
    strcpy(b.name, "Nguyen Van B");
    b.tel = 234;
    strcpy(b.email, "b@gmail.com");
    root = insert_after(root, b, &cur);
    Address c;
    strcpy(c.name, "Nguyen Van C");
    c.tel = 345;
    strcpy(c.email, "c@gmail.com");
    root = insert_after(root, c, &cur);
    
    print_list(root);
    
    printf("After first deletion:\n");
    root = delete(root, &cur);
    print_list(root);
    printf("After second deletion:\n");
    root = delete(root, &cur);
    print_list(root);
    printf("After third deletion:\n");
    root = delete(root, &cur);
    print_list(root);
}


AddressList *insert_after(AddressList *root, Address ad, AddressList ** cur){
    // create new item
    AddressList * new_item = (AddressList*) malloc(sizeof(AddressList));
    new_item->addr = ad;
    new_item->next = NULL;
    if (root == NULL){  /* if there is no element */
        root = new_item;
        *cur = root;
    } else {
        (*cur)->next = new_item;
        *cur = (*cur)->next;
    }
    return root;
}


void print_list(AddressList *root){
    for (AddressList * cur = root; cur != NULL; cur = cur->next ){
        printf("%s %d %s\n", (cur->addr).name, (cur->addr).tel, (cur->addr).email);
    }
}

AddressList *delete(AddressList *root, AddressList **cur){
    if (*cur == root) {
        root = (*cur)->next;
        free(*cur);
        *cur = root;
        return root;
    }
    AddressList *prev = root;
    while (prev->next != *cur) prev = prev->next;
    prev->next = (*cur)->next;
    free(*cur);
    *cur = prev;
    return root;
}
