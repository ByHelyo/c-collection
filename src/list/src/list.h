#ifndef C_COLLECTION_LIST_H
#define C_COLLECTION_LIST_H

struct List {
    void* data;

    struct List* next;
};

#endif // C_COLLECTION_LIST_H
