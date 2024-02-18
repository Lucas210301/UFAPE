#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(struct list *l) {
    if (isEmpty(l) || l->size == 1)
        return;

    struct node *ptr1;
    struct node *ptr2 = NULL;
    int trocado;

    do {
        trocado = 0;
        ptr1 = l->first;

        while (ptr1->next != ptr2) {
            if (ptr1->v > ptr1->next->v) {
                int temp = ptr1->v;
                ptr1->v = ptr1->next->v;
                ptr1->next->v = temp;
                trocado = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (trocado);
}

void insertionSort(struct list *l) {
    if (isEmpty(l) || l->size == 1)
        return;

    struct node *current = l->first->next;

    while (current != l->first) {
        struct node *temp = current->next;
        struct node *innerCurrent = l->first;

        while (innerCurrent != current && innerCurrent->v <= current->v) {
            innerCurrent = innerCurrent->next;
        }

        if (innerCurrent != current) {
            int tempValue = current->v;
            current->v = innerCurrent->v;
            innerCurrent->v = tempValue;
        }

        current = temp;
    }
}

void selectionSort(struct list *l) {
    if (isEmpty(l) || l->size == 1)
        return;

    struct node *i, *j;
    int min;

    for (i = l->first; i != l->last; i = i->next) {
        min = i->v;
        struct node *minNode = i;

        for (j = i->next; j != l->first; j = j->next) {
            if (j->v < min) {
                min = j->v;
                minNode = j;
            }
        }

        if (minNode != i) {
            int temp = i->v;
            i->v = minNode->v;
            minNode->v = temp;
        }
    }
}

int main() {
    struct list l;
    init(&l);
    addFirst(&l, 5);
    addFirst(&l, 2);
    addFirst(&l, 10);
    addFirst(&l, 3);
    addFirst(&l, 6);

    printf("Antes do Bubble Sort:\n");
    print(&l);

    bubbleSort(&l);

    printf("\nDepois do Bubble Sort:\n");
    print(&l);

    printf("\nAntes do Insertion Sort:\n");
    print(&l);

    insertionSort(&l);

    printf("\nDepois do Insertion Sort:\n");
    print(&l);

    printf("\nAntes do Selection Sort:\n");
    print(&l);

    selectionSort(&l);

    printf("\nDepois do Selection Sort:\n");
    print(&l);

    return 0;
}
