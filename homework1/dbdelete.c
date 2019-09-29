#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include <string.h>

int main(int argc,char *argv[])
{
	int fd,id;
	char c;
	struct student record;
	if(argc < 2){
		fprintf(stderr,"use : %s file\n",argv[0]);
		exit(1);
	}
	if((fd = open(argv[1],O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do{
		printf("delete student number:");
		if(scanf("%d",&id) ==1){
			lseek(fd,(id-START_ID)*sizeof(record),SEEK_SET);
			if((read(fd,(char *)&record,sizeof(record))>0)&&(record.id!=0)){
		printf("name:%s\t number:%d\t score:%d\n",record.name,record.id,record.score);
		char name[24]="null";
		strcpy(record.name,name);
		id = -1;
		record.id = -1;
		record.score = -1;
		lseek(fd,-sizeof(record),SEEK_CUR);
		write(fd,(char *)&record,sizeof(record));
			}
		else printf("record %d no \n",id);
			}
			else printf("error");
		printf("continue?(Y/N)");
		scanf(" %c",&c);
		}while(c=='Y');
	close(fd);
	exit(0);
}	
