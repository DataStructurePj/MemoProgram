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
		printf("1�� �ػ� ũ�� ����\n2�� ����\n");
		printf("��ȣ�� �Է��ϼ���.: ");
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
			printf("�߸��� ��ȣ�Դϴ�.\n");
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

	printf("������ ũ�⸦ �Է����ּ���.: ");
	scanf("%d", &lines);
	printf("������ ũ�⸦ �Է����ּ���.: ");
	scanf("%d", &cols);

	sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command);

	fpo = fopen("text.txt", "wt");
	if (fpo == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fprintf(fpo, "%d %d", lines, cols);
	fclose(fpo);

	fpi = fopen("text.txt", "rt");
	if (fpi == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fscanf(fpi, "%d %d", &lines, &cols);
	printf("\n����: %d\n����: %d\n", lines, cols);
	fclose(fpi);

	return 0;
}
