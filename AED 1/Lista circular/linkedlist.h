#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node *next;
};

struct list {
    int size;
    struct node *first;
    struct node *last;
};

void init(struct list *l);
int isEmpty(struct list *l);
void addFirst(struct list *l, int key);
void addLast(struct list *l, int key);
void addAtPosition(struct list *l, int pos);
void print(struct list *l);
struct node* search(struct list *l, int key);
void removeFirst(struct list *l);
void removeElement(struct list *l, int key);
void removeLast(struct list *l);

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

    return 0;
}
