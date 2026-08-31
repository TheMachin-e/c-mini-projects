#include<stdio.h>
int white_space(const char ch){
        if(ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
                return 1;
        else
                return 0;
}


double my_atof(const char *s){
        double num=0,c=1;
        int f=0,sign=0,dpf=0,esign=0,exp=0;
        while(*s){
                while(white_space(*s) && !f)
                        s++;
                if(!f && *s=='-'){
                        f = sign = 1;
                        s++;
                        continue;
                }
                else if(!f && *s == '+'){
                        f = 1;
                        s++;
                        continue;
                }
                else if(!dpf && *s=='.'){
                        dpf = 1;
                        s++;
                        continue;
                }
                else if(f && dpf != 2 && (*s =='e' || *s == 'E')){
                        dpf = 2;
                        s++;
                        continue;
                }
                else if(f && dpf == 2 && *s=='-'&& (*(s - 1) == 'e' || *(s - 1) == 'E')){
                        esign = 1;
                        s++;
                        continue;
                }
                else if(f && dpf == 2 && *s =='+' && (*(s-1) == 'e' || *(s - 1) == 'E')){
                        s++;
                        continue;
                }
                else if(*s < '0' || *s > '9')
                        break;
                f=1;
                if(dpf == 0)
                        num = num * 10 + *s - 48;
                else if(dpf == 1){
                        c *= 10;
                        num = num + (*s - 48) / c;
                }
                else if(dpf == 2)
                        exp = exp * 10 + *s - 48;

                s++;
        }
        if(dpf == 2)
                if(esign)
                        while(exp > 0){
                                num /= 10.0;
                                exp--;
                        }
                else
                        while(exp>0){
                                num *= 10.0;
                                exp--;
                        }

        return sign?-num:num;
}


int main(int argc,char **argv){
        char **p=argv+1;
        while(*p)
                printf("%lf\n",my_atof(*p++));
        return 0;
}

