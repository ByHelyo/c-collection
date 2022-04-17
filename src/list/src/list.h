#ifndef C_COLLECTIONS_LIST_H
#define C_COLLECTIONS_LIST_H

struct List {
    void* data;

    struct List* next;
};

#endif // C_COLLECTIONS_LIST_H
