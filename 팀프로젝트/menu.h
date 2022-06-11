#pragma once
#include <conio.h>
//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define MENUSIZE 5
char menuList[MENUSIZE][30];

int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
void clear_stdin();
//사용자에게 경고창을 띄워줌 
int showAlert(char msg[],int p);


//각 메뉴별 세부 메뉴 

//새 파일에서 사용할 메뉴
