#include <stdio.h>

int main(int argc, char *argv[]){

    printf("Number of arguments is %d\n",argc);

    for(int i=0;i<argc;i++){
        printf("arg[%d] is \'%s\' \n",i,argv[i]);
    }
    return 0;
}