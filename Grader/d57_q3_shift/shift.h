#include<iostream>

void shift(int k) {
	// TODO: Add your code here
	while(k<0) k+=mSize;
	k%=mSize;
	if(k==0) return ;

	iterator it = mHeader;
	for(int i=0;i<k;i++) it++;
	// std::cout<<it.ptr->data<<'\n';
	
	// make a connection between first and last node first
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	// THEN connect it to mHeader
	iterator tmp = it.ptr->next;
	it.ptr->next = mHeader;
	mHeader->prev = it.ptr;
	// THEN connect it->next to mHeader
	tmp.ptr->prev = mHeader;
	mHeader->next = tmp.ptr;

}

