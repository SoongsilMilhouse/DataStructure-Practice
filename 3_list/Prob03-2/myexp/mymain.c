#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
	List list;
	NameCard * namecard = (NameCard*)malloc(sizeof(NameCard));
	NameCard * tempcard= (NameCard*)malloc(sizeof(NameCard));
	
	
	ListInit(&list);

	namecard = MakeNameCard("jiyongkim", "010-5542-2512");
	LInsert(&list, namecard);

	namecard = MakeNameCard("sooanchoi", "010-4190-4668");
	LInsert(&list, namecard);

	namecard = MakeNameCard("gunwoopark", "010-7289-5540");
	LInsert(&list, namecard);

	printf("리스트 명단 모두 출력:\n");
	if(LFirst(&list, &namecard)) 
	{
		ShowNameCardInfo(namecard);

		while(LNext(&list,&namecard))
			ShowNameCardInfo(namecard);
	}
	printf("\n");
	
	tempcard= MakeNameCard("sooanchoi", "010-4190-4668");


	printf("sooanchoi 탐색 후 정보 출력\n");
	if(LFirst(&list,&namecard)) 
	{
		if(!NameCompare(namecard, tempcard->name))
			ShowNameCardInfo(namecard);
		
		while(LNext(&list, &namecard))
		{
			if(!NameCompare(namecard, tempcard->name))
				ShowNameCardInfo(namecard);
		}
	}
	printf("\n");

	printf("sooanchoi 탐색 후 전화번호 변경\n");
	if(LFirst(&list,&namecard)) 
	{
		if(!NameCompare(namecard, tempcard->name)){
			ChangePhoneNum(namecard, "010-0308-0308");
			ShowNameCardInfo(namecard);
		}
		
		while(LNext(&list, &namecard))
		{
			if(!NameCompare(namecard, tempcard->name)){
				ChangePhoneNum(namecard, "010-0308-0308");
				ShowNameCardInfo(namecard);
			}
		}
	}
	printf("\n");


	printf("sooanchoi 탐색 후 정보 삭제\n");	
	if(LFirst(&list,&namecard)) 
	{
		if(!NameCompare(namecard, tempcard->name)){
			namecard = LRemove(&list);
			free(namecard);
		}
		
		while(LNext(&list, &namecard))
		{
			if(!NameCompare(namecard, tempcard->name))
				namecard = LRemove(&list);
				free(namecard);
				break;
		}
	}
	printf("\n");
	
	printf("리스트 명단 재출력\n");
	if(LFirst(&list, &namecard)) 
	{
		ShowNameCardInfo(namecard);

		while(LNext(&list,&namecard))
			ShowNameCardInfo(namecard);
	}
	
	free(tempcard);
	return 0;
}
