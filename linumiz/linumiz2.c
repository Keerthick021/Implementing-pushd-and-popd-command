/*Name : keerthick vasa M
Date :04/07/2024
description :Implementing push and popd commands
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char dir_stack[100][1024];
int stack_size = 0;

void pushd(const char *dir) {
    if (stack_size >= 100) { //stack size is greater than directory size than mention directory stack is full.
	printf("dir stack is full\n");
	return ;
    }
    chdir(dir);//change new directory
    getcwd(dir_stack[stack_size], 1024);
    printf("Newly Changed directory:%s",dir_stack[stack_size]);//print newly chamged directory
    printf("\n");
    stack_size++; //increase the size of stack.
    
}

void popd() {
    if (stack_size <= 0) {
	printf("dir stack is empty\n");  //if stack_size is less than -1 then stack is empty
	return;
    }
    printf("Poped dir: %s\n", dir_stack[stack_size-1]);
    stack_size--;//reduce the size of stack_size.
}

void print_stack() {
    if (stack_size == 0) {
	printf("Dir empty\n");
	return;
    }
    printf("Stack : ");
    for (int i = stack_size -1; i >= 0; i--) {
	printf("%s ", dir_stack[i]);//print the content of the stack.
    }
    printf("\n");
}

int main() {
                                //current directory
    char Existing_dir[100];
    printf("Existing dir: %s\n", getcwd(Existing_dir, 100));
    getcwd(dir_stack[stack_size], 1024);// svae current directory
    stack_size++;
    pushd("etc");
    pushd("/var/log");//push the new directory   
    print_stack();    //print the stack
    popd();           //popd the last in directory
    print_stack();    //print the stack
    popd();          
    popd();          // if pop every directory it return stack is emmpty.
    print_stack();

    return 0;
}




