#define _CRT_SECURE_NO_WARNINGS
#define COMMAND_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void)
{
	int a, b = 0;
	char command[COMMAND_SIZE] = { '\0', };
	int lines, cols;

	FILE* fp = fopen("text.txt", "rt");
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

int Command(int argc, char* argv[], char* env[])
{
	FILE* fpo;
	FILE* fpi;

	char command[COMMAND_SIZE] = { '\0', };
	int lines, cols;

	printf("세로의 크기를 입력해주세요.: ");
	scanf("%d", &lines);
	printf("가로의 크기를 입력해주세요.: ");
	scanf("%d", &cols);

	sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command);

	fpo = fopen("text.txt", "wt");
	if (fpo == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fprintf(fpo, "%d %d", lines, cols);
	fclose(fpo);

	fpi = fopen("text.txt", "rt");
	if (fpi == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fscanf(fpi, "%d %d", &lines, &cols);
	printf("\n세로: %d\n가로: %d\n", lines, cols);
	fclose(fpi);

	return 0;
}
