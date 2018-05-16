#include <stdio.h>

int RBSearch(int ar[], int first, int last, int target) 
{
	int mid;

	if(first>last)
		return -1;
	mid = (first+last)/2;

	if(ar[mid] == target)
		return mid;
	else if(target < ar[mid])
		return RBSearch(ar,first,mid-1,target);
	else
		return RBSearch(ar,mid+1,last,target);
}
 
int main(void)
{
	int arr[] = {1,3,5,7,9};
	int idx;
	int length = sizeof(arr)/sizeof(int);

	idx = RBSearch(arr,0, length-1,7);
	if(idx == -1) 
		printf("탐색 실패\n");
	else 
		printf("타겟 저장 인덱스:%d\n",idx);

	idx = RBSearch(arr,0,length-1,4);
	if(idx == -1)
		printf("탐색 실패\n");
	else 
		printf("타겟 저장 인덱스:%d\n",idx);
	

	return 0;
}

