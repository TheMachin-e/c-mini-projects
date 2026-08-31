#include<stdio.h>
int white_space(const char ch){
	if(ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
		return 1;
	else
		return 0;
}


int my_atoi(const char *s){
	int num=0,f=0,sign=0;

	while(*s){
		while(white_space(*s)&&!f)
			s++;
		if(!f && *s=='-'){
			f=sign=1;
			s++;
			continue;
		}
		else if(!f && *s=='+'){
			f=1;
			s++;
			continue;
		}
		else if(*s < '0' || *s > '9')
			break;
		f=1;
		num=num*10+*s-48;
		s++;
	}
	return sign?-num:num;
}
int main(int argc,char **argv){
	char **p=argv+1;
	while(*p)
		printf("%d\n",my_atoi(*p++));
	return 0;
}

