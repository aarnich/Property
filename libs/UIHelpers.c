/* a set of UI methods that help wtih displaying the UI of Property, written by Aaron Gumapac */
#include <stdio.h>
typedef void (*methodPtr)();
void backButton(methodPtr ptrMethod){
    printf("/n [B] Back /n");
    char c;
    scanf("%c",&c);
    if(c == 'B'){

        ptrMethod();

    }
}
void displayGreeting(){
    printf("Welcome to Monopoly!\n");
}
void displayMain(){
    printf(
        "[G] Start game\n"
        "[E] Exit \n"
    );
}
