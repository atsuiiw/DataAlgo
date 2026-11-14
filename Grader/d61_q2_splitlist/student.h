#include<iostream>

void splitList(list<T>& list1, list<T>& list2) {
    size_t n1 = (mSize + 1) / 2, n2 = mSize - n1;
    node *first = mHeader->next;
    node *mid = first;
    for (size_t i = 0; i < n1; i++) mid = mid->next; // first node of second half
    node *last = mHeader->prev;

    // append [first, mid->prev] to list1
    if (n1 > 0) {
        node *a = mid->prev, *h = list1.mHeader;
        h->prev->next = first;
        first->prev = h->prev;
        a->next = h;
        h->prev = a;
        list1.mSize += n1;
    }
    // append [mid, last] to list2
    if (n2 > 0) {
        node *h = list2.mHeader;
        h->prev->next = mid;
        mid->prev = h->prev;
        last->next = h;
        h->prev = last;
        list2.mSize += n2;
    }
    mHeader->next = mHeader->prev = mHeader;
    mSize = 0;
}
