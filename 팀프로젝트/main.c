#include "main.h"

int main() {
	init();
	while (1) {
		int menuCode = menuDraw();

		switch (menuCode)
		{
			//새 파일 생성 메뉴 선택
		case 0:
			break;

			//기존에 작성한 파일 목록 보여주고, 선택한 파일 수정하는 기능 제공 
		case 1:
			system("cls");
			OnOff(1);
			//파일목록 제공 

			//제공한 파일 편집하는 함수 
			writeStc(); 
			OnOff(0);
			break;
		case 2:
			break;
		case 3:
			break;


		default:
			break;
		}

	
	}
	return 0;
}
