#include "linkedList.h"
#include <stdio.h>

int main(){
    LinkedList* list = newLinkedList();
    pushElementHead(list, 1);
    pushElementHead(list, 2);
    printf("%d", popElementHead(list));
    printf("%d", popElementBack(list));
}
