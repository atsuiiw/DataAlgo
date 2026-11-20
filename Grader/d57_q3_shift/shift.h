void shift(int k) {
	// TODO: Add your code here
	while(k<0) k+=mSize;
	k %= mSize;

	if(k==0) return ;

	iterator it = mHeader->next;
	for(int i=0;i<k;i++) it = it.ptr->next;

	iterator a = it.ptr->prev;
	iterator end = mHeader->prev;
	iterator begin = mHeader->next;

	mHeader->next = it.ptr;
	it.ptr->prev = mHeader;

	mHeader->prev = a.ptr;
	a.ptr->next = mHeader;

	end.ptr->next = begin.ptr;
	begin.ptr->prev = end.ptr;

}
