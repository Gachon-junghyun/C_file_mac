//linked_list_1/Code2.png
//  Linked_list_lab2.c
//  문제해결기법
//
//  Created by 한정현 on 2023/11/21.
//

#include <stdio.h>

struct node{
    int key;
    struct node *next;
} node_list[10], new_list[10];

void insert_list(struct node *new, struct node *pre, struct node *next){
    
    struct node temp;
    
    if(next == NULL){
        pre -> next = new;
        new -> next = NULL;
    }
    else{
        temp.next = next;
        pre -> next = new;
        new -> next = temp.next;
    }
    
}

void list_link(struct node *pre, struct node *next){
    pre -> next = next;
}

void show_node(struct node start){
    struct node *show = &start;
    int i = 0;
    while(1){
        if(i != 0){
            printf("node : %d\n", show -> key);
        }
        if(i == 0){
            i = 1;
        }
        if(show -> next == NULL){
            break;
        }
        show = show -> next;
    }
}

int main(){
    
    node_list[0].key = 100;
    node_list[1].key = 250;
    node_list[2].key = 467;
    
    node_list[0].next = &node_list[1];
    node_list[1].next = &node_list[2];
    node_list[2].next = NULL;
    
    new_list[0].key = 250; // 300 50 500
    new_list[1].key = 300;
    new_list[2].key = 50;
    new_list[3].key = 500;
    new_list[4].key = 100000;
    
    struct node start;
    start.next = &node_list[0];
    struct node *Then;
    struct node *pre = &start;
    
    for(int i = 0; i < 5; i++){
        pre = &start;
        Then = &node_list[0];
        
        while(1){
            
            if(Then -> key == new_list[i].key){
                break;
            }
            if(Then -> key > new_list[i].key){
                insert_list(&new_list[i], pre , Then);
                break;
            }
            if(Then -> next == NULL){
                insert_list(&new_list[i], Then , NULL);
                break;
            }
            pre = Then;
            Then = Then -> next;
            
        }
    }
    
    show_node(start);
    
}
/*
 for(int i = 0; i < 4; i++){
     
     Then = &node_list[0];
     printf("----------\n");
     while(1){
         show_node();
         //printf("%d, %d\n", Then -> key, new_list[i]);
         if(Then -> key == new_list[i].key){
             break;
         }
         if(Then -> key > new_list[i].key){
             insert_list(&new_list[i], pre , Then);
             break;
         }
         if(Then -> next == NULL){
             break;
         }
         pre = Then;
         Then = Then -> next;
         
     }
 }
 */
