# polynomial_complexity
### This repository is to note down some problems (especially algorithm related) and implementations in C/C++, say, learning notes. And I noted down the first problem here. Use Circular Queue to solve Josephus problem.

## Problem:
People are standing in a circle waiting to be executed. Counting begins at a specified point in the circle and proceeds around the circle in a specified direction. After a specified number of people are skipped, the next person is executed. 
The procedure is repeated with the remaining people, starting with the next person, going in the same direction and skipping the same number of people, until only one person remains, and is freed. 
Given the amount of people, starting point, direction, and number to be skipped, determine the person's index in the initial circle who will avoid execution.
In the following, **n** denotes the number of people in the initial circle, and **k** denotes the count for each step, that is, **k-1** people are skipped and the **k-th** is executed. The people in the circle are numbered from **1** to **n**.


## Input:
Let **n** be a variable.
**k=2**, which means every **2nd** person will be killed.
From the **1st** person, in the direction of **ascending number**.


## Output:
The number of freed person.

## Example:
Starting from the **first** person, the **second** will be **killed**, then the **forth**, then the **sixth**...
![diagram](http://i.v2ex.co/Pg57IJQ4l.png)


## Implementation:
```C
#include <stdio.h>
int Q[100];
int Head, Tail, Number_of_Items = 0;

//Head is to record the first one
//Tail is to record the last one
//Number_of_Items is to recode the real-time amount of people

void Enqueue(int x){
    if(Number_of_Items == 0){
        Head = Tail = 0;
        Q[Tail] = x;
    }
    else{
        Tail = (Tail+1)%100;
        Q[Tail] = x;
    }
    Number_of_Items ++;
}

int Dequeue(void){
    int z;
    z  =  Q[Head];
    Head = (Head+1)%100;
    Number_of_Items --;
    
    return z;
}


int main(int argc, const char * argv[]) {
    int n, answer, i, j;
    printf("Enter a number (1-99): ");
    scanf("%d",&n);
    
    //step 1: Put all the numbers between 1-n into Queue
    for(i = 1; i<= n; i++)
        Enqueue(i);
    
    //step 2: Start killing for n-1 rounds
    for(i = 1; i<= n-1; i++){
        j = Dequeue();
        Dequeue();
        Enqueue(j);
    }
    
    answer = Q[Head];
    printf("The value of J(%d) is: %d\n", n, answer);
    
    return 0;
}
```
