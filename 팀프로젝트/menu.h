#include <conio.h>
//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
void clear_stdin();
//사용자에게 경고창을 띄워줌 
int showAlert(char msg[]);

