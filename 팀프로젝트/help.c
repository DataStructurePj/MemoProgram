#include "main.h"


int PIVOTX, PIVOTY;
void helpSentence(char msg[]) {
	gotoxy(PIVOTX, PIVOTY++); //Ŀ�� ��ġ �̵� 
	printf("|                                                                  |");
	gotoxy(PIVOTX, PIVOTY++); //Ŀ�� ��ġ �̵� 
	printf("%s", msg);
}






void showHelp()
{
	
	PIVOTX = 6;
	PIVOTY = 3;

	//�� �� ��
	gotoxy(PIVOTX, PIVOTY++); //Ŀ�� ��ġ �̵� 
	printf("|------------------------------------------------------------------|\n");

	//���� ����
	helpSentence("|  1. �� ���α׷��� �޸��� ���α׷��Դϴ�                          |");
	helpSentence("|  2. ����Ű�� ����Ű �� i(����), p(����), r(���� �����),         |");
	helpSentence("|     escŰ(����ȭ�� �̵�) Ű ������ ���α׷��� ����� �� �ֽ��ϴ� |");
	helpSentence("|  3. i Ű�� ������ �޸� ������ �����մϴ�.                        |");
	helpSentence("|  4. p Ű�� ������ �����ϱⰡ �����մϴ�.                         |");
	helpSentence("|  5. r Ű�� ������ ���� ����Ⱑ �����մϴ�.                      |");
	helpSentence("|  6. escŰ�� ������ ����ȭ������ �̵��մϴ�.                      |");
	helpSentence("|  7. �����ϱ⸦ ������ ������ �̸��� �Է½� ���������� ����˴ϴ�.|");
	helpSentence("|  8. �޸𿭱� ����� ���� ���� �־��� �޸� ������� �޸� ��   |");
	helpSentence("|     �� �ֽ��ϴ�.                                                 |");
	helpSentence("|  9. �ɼǱ���� ���� ���� ����� ��� ������ ����� ������� ���� |");
	helpSentence("|     �� �� �ֽ��ϴ�.                                              |");
	helpSentence("|  10. �����ϱ� ����� ���� �޸��� ���α׷� ���ᰡ �����մϴ�.     |");

	//�� ������ ��
	gotoxy(PIVOTX, PIVOTY++);
	printf("|------------------------------------------------------------------|\n");
	PIVOTY++;
	gotoxy(PIVOTX + 15, PIVOTY);
	printf("ESCŰ�� ���θ޴��� ���ư��� >> \n");

}