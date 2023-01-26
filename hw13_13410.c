#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "function.h"

//
typedef struct {
    char from[10];
    char to[10];
    int val;
}transaction;

typedef struct {
    transaction t[2];
    int link;
}block;

typedef struct {
    block* block_data[1010];
    int tail;
}block_chain;

// TODO: return the hash value of the given block
int hash(block* b) {
    int sum = (b->t[0].val + b->t[1].val);
    return (((sum * sum) ^ b->link) + (b->link) * (b->link)) % 1000 + 1;
}

// TODO: create a block with the given information and return its address
block* create_block(int currentTail, transaction t[2]) {
    block* a = (block *)malloc(sizeof(block));
    for (int i = 0 ; i < 2 ; i++) {
        a->t[i] = t[i];
    }
    a->link = currentTail;
    return a;
}

// TODO: query someone's balance
int query(block_chain *bc, char name[10], int initial_saving) {
    int p = bc->tail;
    while (p != 0) {
        for (int i = 0 ; i < 2 ; i++) {
            if (bc->block_data[p]->t[i].from[0] == name[0]) initial_saving -= bc->block_data[p]->t[i].val;
            else if (bc->block_data[p]->t[i].to[0] == name[0]) initial_saving += bc->block_data[p]->t[i].val;
        }
        p = bc->block_data[p]->link;
    }
    return initial_saving;
}
//

void traverse_block_chain(block_chain *bc) {
    int ptr = bc->tail;
    while (ptr != 0) {
        printf("<-%d", ptr);
        ptr = bc->block_data[ptr]->link;
    }
    printf("\n");
}

int main() {
    int command;
    char name1[10], name2[10];
    int tmp, i, hash_value;
    block_chain chain;
    block* new_block;
    chain.tail = 0;
    chain.block_data[0] = NULL;
    int count;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &command);
        if (command == 1) {                     // CREATE BLOCK
            transaction t[2];
            for (i = 0; i < 2; i++) {
                scanf("%s %s %d", name1, name2, &tmp);
                strcpy(t[i].from, name1);
                strcpy(t[i].to, name2);
                t[i].val = tmp;
            }
            new_block = create_block(chain.tail, t);
            hash_value = hash(new_block);
            chain.block_data[hash_value] = new_block;
            chain.tail = hash_value;
        }else if (command == 2) {               // QUERY
            scanf("%s %d", name1, &tmp);
            printf("%d\n", query(&chain, name1, tmp));
        }else if (command == 0) {               // EXIT
            traverse_block_chain(&chain);
        }else {
            return 1;
        }
    }
    return 0;
}
