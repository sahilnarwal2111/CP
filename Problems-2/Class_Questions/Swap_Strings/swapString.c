#include<stdio.h>
#include <string.h>
void swap(char s1[], char s2[]);

void swap1(char *s1, char *s2){
    char * t ;
    t = s1;
    s1 = s2;
    s2 = t;
}

int main()
{
    // For swap function : Un comment below code
    // char str1[] = "Sahil";
    // char str2[] = "Narwal";

    // printf("%s %s",str1,str2);
    // swap(str1,str2);
    // printf("\n");
    // printf("%s %s",str1,str2);

    // For swap1 function : Un commnet below code
    char * s1 = "Sahil";
    char * s2 = "Narwal";

    printf("%s %s", s1,s2);
    printf("\n");
    swap1(s1,s2);
    printf("%s %s",s1, s2);


    return 0;
}

void swap(char s1[], char s2[]){
    char t[strlen(s1) + 1];
    
    // strcpy(destination, source);
    strcpy(t,s1);

    strcpy(s1,s2);

    strcpy(s2,t);

}