
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {

    if(ls.size() == 0) return ;

    iterator it = mHeader->next;
    iterator ir = ls.mHeader->next;
    for(int i=0;it!=mHeader && ir!=ls.mHeader;i++){
        // std::cout<<it.ptr->data<<' ';
        node* itNext = it.ptr->next;
        node* irNext = ir.ptr->next;

        itNext->prev = ir.ptr;
        ir.ptr->next = itNext;
        
        ir.ptr->prev = it.ptr;
        it.ptr->next = ir.ptr;

        ir = irNext;
        it = itNext;
    }

    if(ir!=mHeader){
        node* end = mHeader->prev;

        end->next = ir.ptr;
        ir.ptr->prev = end;

        ir = ls.mHeader->prev;
        ir.ptr->next = mHeader;
        mHeader->prev = ir.ptr;
    }

    mSize += ls.size();
    ls.mSize = 0;
    ls.mHeader->next = ls.mHeader->prev = ls.mHeader;
}

#endif
