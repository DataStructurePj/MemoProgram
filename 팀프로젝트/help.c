#include "main.h"


int PIVOTX, PIVOTY;
void helpSentence(char msg[]) {
	gotoxy(PIVOTX, PIVOTY++); //커서 위치 이동 
	printf("|                                                                  |");
	gotoxy(PIVOTX, PIVOTY++); //커서 위치 이동 
	printf("%s", msg);
}






void showHelp()
{
	
	PIVOTX = 6;
	PIVOTY = 3;

	//맨 윗 줄
	gotoxy(PIVOTX, PIVOTY++); //커서 위치 이동 
	printf("|------------------------------------------------------------------|\n");

	//도움말 내용
	helpSentence("|  1. 본 프로그램은 메모장 프로그램입니다                          |");
	helpSentence("|  2. 방향키와 엔터키 및 i(편집), p(저장), r(새로 만들기),         |");
	helpSentence("|     esc키(메인화면 이동) 키 등으로 프로그램을 사용할 수 있습니다 |");
	helpSentence("|  3. i 키를 누르면 메모 편집이 가능합니다.                        |");
	helpSentence("|  4. p 키를 누르면 저장하기가 가능합니다.                         |");
	helpSentence("|  5. r 키를 누르면 새로 만들기가 가능합니다.                      |");
	helpSentence("|  6. esc키를 누르면 메인화면으로 이동합니다.                      |");
	helpSentence("|  7. 저장하기를 누르고 파일의 이름을 입력시 정상적으로 저장됩니다.|");
	helpSentence("|  8. 메모열기 기능을 통해 원래 있었던 메모나 만들었던 메모를 볼   |");
	helpSentence("|     수 있습니다.                                                 |");
	helpSentence("|  9. 옵션기능을 통해 글자 색깔과 배경 색깔을 사용자 마음대로 변경 |");
	helpSentence("|     할 수 있습니다.                                              |");
	helpSentence("|  10. 종료하기 기능을 통해 메모장 프로그램 종료가 가능합니다.     |");

	//맨 마지막 줄
	gotoxy(PIVOTX, PIVOTY++);
	printf("|------------------------------------------------------------------|\n");
	PIVOTY++;
	gotoxy(PIVOTX + 15, PIVOTY);
	printf("ESC키로 메인메뉴로 돌아가기 >> \n");

}