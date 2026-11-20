void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here

    size_t n1 = (mSize+1)/2, n2 = mSize/2;

    iterator mid = mHeader->next;
    for(int i=0;i<n1;i++) mid= mid.ptr->next;

    node* first = mHeader->next;
    node* last = mHeader->prev;

    if(n1 > 0){
        node* h = list1.mHeader;

        h->prev->next = first;
        first->prev = h->prev;

        mid.ptr->prev->next = h;
        h->prev = mid.ptr->prev;

        list1.mSize += n1;
    }
    if(n2 > 0){
        node* h = list2.mHeader;

        h->prev->next = mid.ptr;
        mid.ptr->prev = h->prev;

        last->next = h;
        h->prev = last;
    
        list2.mSize += n2;
    }

    // reset header to none
    mHeader->prev = mHeader;
    mHeader->next = mHeader;
    mSize = 0;
}
