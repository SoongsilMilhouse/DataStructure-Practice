#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int whoisprecede(Point * d1, Point * d2) 
{
	if(d1->xpos < d2->xpos)
	{
		return 0;
	}
	else if(d1->xpos == d2->xpos)
	{
		if(d1->ypos < d2->ypos)
			return 0;
		else 
			return 1;
	}
	else 
		return 1;
}

int main()
{
	List list;
	Point comppos;
	Point* ppos;
	ListInit(&list);

	SetSortRule(&list, whoisprecede);


	//4개의 데이터 저장
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 1);
	LInsert(&list, ppos);
	//저장된 데이터의 출력
	printf("현재 데이터의 수:%d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	//xpos가 2인 모든 데이터 삭제
	comppos.xpos = 2;
	comppos.ypos = 0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &comppos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &comppos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}

	}

	//삭제 후 남은 데이터 전체 출력
	printf("현재 데이터 수 : %d\n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}

			
