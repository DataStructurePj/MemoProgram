#define COMMAND_SIZE 256
#include "main.h"

int main(void)
{
	int a, b = 0;
	char command[COMMAND_SIZE] = { '\0', };
	int lines, cols;

	FILE* fp = fopen(SETTING_FILE, "rt");
	if (fp != NULL)
	{
		fscanf(fp, "%d %d", &lines, &cols);
		sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
		system(command);
		fclose(fp);
	}

	while (b < 1) {
		printf("1번 해상도 크기 조절\n2번 종료\n");
		printf("번호를 입력하세요.: ");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Command();
			printf("\n");
			break;
		case 2:
			b = 1;
			break;
		default:
			printf("잘못된 번호입니다.\n");
			break;
		}
	}
	return 0;
}

