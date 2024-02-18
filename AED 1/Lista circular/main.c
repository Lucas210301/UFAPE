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

void init(struct list *l){
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}

int isEmpty(struct list *l){
    if(l==NULL || l->first == NULL)
        return 1;
    else
        return 0;
}

void addFirst(struct list *l, int key){
    struct node *n = (struct node *) malloc(sizeof(struct node));
  
    if(n!=NULL){
        n->v = key;
        n->next = l->first;
        l->first = n;
        if(l->last == NULL)
            l->last = n;
    
        l->last->next = l->first;
        l->size++;
    }
    else 
        printf("Memory allocation error!");
}

void addLast(struct list *l, int key){
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n!=NULL){
        if(l->size == 0)
            addFirst(l, key);
        else{
            n->v = key;
            l->last->next = n;
            l->last = n;
            n->next = l->first;
            l->size++;
        }
    }
    else 
        printf("Memory allocation error!");
}

void print(struct list *l){
    struct node *tmp = l->first;
    if(isEmpty(l))
        printf("\nLista vazia!");
    else{
        printf("\nCurrent list: ");
        for(int i=0; i<l->size; i++, tmp= tmp->next)
            printf("%d ",tmp->v);
        printf("\n");
    }
}

struct node* search(struct list *l, int key){
    struct node *current = l->first;
    while(current != NULL){
        if(current->v == key)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeFirst(struct list *l){

    if(isEmpty(l))
        return;
    else{
        l->first = l->first->next;
        l->last->next = l->first;
        l->size--;
    }
}

void removeElement(struct list *l, int key){
    struct node *removed = NULL;
    if(isEmpty(l))
        return;
    else{
        if(l->first == l->last && l->first->v == key){
            l->first = NULL;
            l->last = NULL;
            l->size=0;
        }
        else
            if(l->first->v == key){
                removed = l->first;
                l->first = removed->next;
                l->last->next = l->first;
                l->size--;
                free(removed);
            }else{
                struct node *tmp = l->first;
            
                while(tmp->next!=l->first && tmp->next->v!=key)
                    tmp = tmp->next;
                
                if(tmp->next->v == key){
                    removed = tmp->next;
                    tmp->next = removed->next;
                    if(l->last == tmp->next){ 
                        l->last = tmp;
                    }
                    free(removed);
                    l->size--;
                }
            }
    }
}

void removeLast(struct list *l); //TO DO

void addAtPosition(struct list *l, int pos); //TO DO 

void bubbleSort(struct list *l) {
    if (isEmpty(l) || l->size == 1)
        return;

    struct node *ptr1;
    struct node *ptr2 = NULL;
    int swapped;

    do {
        swapped = 0;
        ptr1 = l->first;

        while (ptr1->next != ptr2) {
            if (ptr1->v > ptr1->next->v) {
                int temp = ptr1->v;
                ptr1->v = ptr1->next->v;
                ptr1->next->v = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
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

int main(void) {
    struct list l;
    init(&l);
    addFirst(&l, 1);
    addLast(&l, 2);
    addFirst(&l, 3);
    addFirst(&l, 4);

    printf("Lista atual: ");
    print(&l);
    printf
("Tamanho atual: %d\n", l.size);

    // Ordenando com Bubble Sort
    bubbleSort(&l);
    printf("\nOrdenado com Bubble Sort:\n");
    print(&l);

    // Reinicializando a lista
    init(&l);
    addFirst(&l, 1);
    addLast(&l, 2);
    addFirst(&l, 3);
    addFirst(&l, 4);

    // Ordenando com Insertion Sort
    insertionSort(&l);
    printf("\nOrdenado com Insertion Sort:\n");
    print(&l);

    // Reinicializando a lista
    init(&l);
    addFirst(&l, 1);
    addLast(&l, 2);
    addFirst(&l, 3);
    addFirst(&l, 4);

    // Ordenando com Selection Sort
    selectionSort(&l);
    printf("\nOrdenado com Selection Sort:\n");
    print(&l);

    return 0;
}
