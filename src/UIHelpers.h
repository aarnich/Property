/* header file for UIHelpers.c */
typedef void (*methodPtr)();
extern void backButton(methodPtr methodPtr);
extern void goBack(methodPtr ptrPreviousMethod);
extern void displayGreeting();
extern void displayMain();