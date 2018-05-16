#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * namecard = (NameCard*)malloc(sizeof(NameCard));
	strncpy(namecard->name, name, NAME_LEN);
	strncpy(namecard->phone, phone, PHONE_LEN);
	return namecard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("name: %s\n", pcard->name);
	printf("phone:%s\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name) {
	if(!strcmp(pcard->name, name))
		return 0;
	else 
		return 1;	
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strncpy(pcard->phone, phone, PHONE_LEN);
}
