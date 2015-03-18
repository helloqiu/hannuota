/*
    Date : 2015-3-18 11:36
    Author : 张宇阳(heheda || helloqiu)
    Description : c language class homework -- solving hannuota problem

    Date : 2015-3-18 12:21
    Author : 张宇阳(heheda || helloqiu)
    Description : ocuur problems.There seem to be an error in finction checkout().I step into it and find out that the two numbers a and b are not right(a = 32767 , b = -140394056)
                                That puzzled me! I try to use f and t.
    Date : 2015-3-18 12:21
    Author : 张宇阳(heheda || helloqiu)
    Description : problem solved! It shoud be end - 1instead of end + 1!
*/
#include <stdio.h>
#include <stdlib.h>
int move (int start , int end , int from , int to);
int checkout(int a , int b);
int main(void)
{
    int height;
    printf("please enter the hannuota's height : ");
    scanf("%d" , &height);
    printf("total stepnum : %d\n" , move(1 , height , 1 , 3));
    return 0;
}
int move (int start , int end , int from , int to){
//move start to end from from to to
    if (end - start == 0){
        printf("move %d from %d to %d\n" , start , from , to);
        return 1;
    }
    int stepnum = 0;

    stepnum += move(start , end -1 , from , checkout(from , to));
    stepnum += move (end , end , from , to);
    stepnum += move(start , end - 1 , checkout(from , to) , to);
    return stepnum;

}
int checkout(int a , int b){
//find out the number without a and b from 1 , 2 , 3
    int num[3];
    for (int i = 0 ; i < 3 ; i ++){
        num[i] = 1;
    }
    num[a - 1] = 0;
    num[b - 1] = 0;
    for (int i = 0 ; i < 3 ; i ++){
        if (num[i]){
            return i + 1;
        }
    }
    printf("error in function check!\n");
    return 0;
}
