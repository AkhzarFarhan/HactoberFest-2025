#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char *name,*pwd,c;int count,n=0;
	name=(char *)malloc(10);
	pwd=(char *)malloc(10);
	do{
	count=0;
	printf("ENTER USER NAME :  ");
	scanf("%s",name);
	printf("\nENTER PASSWORD :  ");
	while(1){
		c=getch();
		if(c=='\r')
		break;
		pwd[count++]=c;
		printf("*");
	}
	if(!strcmp(name,pwd)){
		printf("\nhello sir.... WELCOME");
		break;
	} 
	else{
		printf("\noops there is error in user name or password pls try again...by clicking 1....\n");
		n=getch();
		if(n!='1')
		break;
	}
}while(1);
	return 0;
}
