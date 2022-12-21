/* 
Name : JARPULA BHANU PRASAD
Branch : ARTIFICIAL INTELLIGENCE
Roll no :   AI21BTECH11015

Poblem no : 2
Date : /02/2022  */

#include <stdio.h>
#include <stdlib.h>

//This function will tell the length of the string 
int my_strlen(char *x){
    int y=0;
    for(int i=0;x[i]!='\0';i++){
        y++;
    }
    return y;
}

//This function will add if both the values are positive or both values negative
char* add(char *a,char *b,char *c){
    int l1,l2,s,e=0;
   l1=my_strlen(a);
   l2=my_strlen(b);
   int d=l1>l2?l1:l2;
   c[d]='\0';
   while(l1-1>=0 && l2-1>=0){
       s=a[l1-1]+b[l2-1]+e-96;
       c[d-1]=s%10+48;
       e=s/10;
       l1--,l2--,d--;
       if(a[l1-1]=='-' || b[l2-1]=='-') break;
   }
   if(l1-1>=0){
       for(int i=l1-1;i>=0;i--){
           if(a[i]=='-') c[d-1]='-';
           else {
                s=a[i]+e-48;
                c[d-1]=s%10+48;
                e=s/10;
           }
           d--;
       }
   }
   else if(l2-1>=0){
       for(int i=l2-1;i>=0;i--){
           if(b[i]=='-') c[d-1]='-';
           else {
                s=b[i]+e-48;
                c[d-1]=s%10+48;
                e=s/10;
           }
           d--;
       }
   }
   if(e==0 && (a[0]=='-'|| b[0]=='-')) c[0]='-';
   else if(e>0){
     for(int i=my_strlen(c);i>=0;i--){
            c[i+1]=c[i];
            if(i==0) c[i]=e+48;
        }
        if(a[0]=='-'|| b[0]=='-'){
            c[1]=e+48;
            c[0]='-';
        }
   }
    return c;
}

//This function will add up one negative and positive intrger
char* diff(char *a,char *b,char *c){
    int l1,l2,s,e=0;
   l1=my_strlen(a);
   l2=my_strlen(b);
   int d=l1>l2?l1:l2;
   c[d]='\0';
   while(l1-1>=0 && l2-1>=0){
            s=a[l1-1]-b[l2-1];
            if(s<0) c[d-1]=-s+48;
            else c[d-1]=s+48;
            l1--,l2--,d--;
            if(a[l1-1]=='-' || b[l2-1]=='-') break;
   }
   if(l1-1>=0){
       for(int i=l1-1;i>=0;i--){
           if(a[i]=='-') c[d-1]='-';
           else {
                s=a[i];
                c[d-1]=s;
           }
           d--;
       }
   }
   else if(l2-1>=0){
       for(int i=l2-1;i>=0;i--){
           if(b[i]=='-') c[d-1]='-';
           else {
                s=b[i];
                c[d-1]=s;
           } 
           d--;
       }
   }
   return c;
}

int main(){
    char *a,*b,*c;

    a=(char *)malloc(sizeof(char)*150);
    b=(char *)malloc(sizeof(char)*150);
    c=(char *)malloc(sizeof(char)*150);

    while(scanf("%s",a)!=-1 && scanf("%s",b)!=-1){
        if((a[0]=='-' && b[0]=='-') || (a[0]!='-' && b[0]!='-')){
        printf("%s\n",add(a,b,c));
        }
        else printf("%s\n",diff(a,b,c));
    }

    free(a),free(b),free(c);

    return 0;
}