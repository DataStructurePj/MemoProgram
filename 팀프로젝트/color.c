#include "main.h"
#define THIS_PROGRAM_VERSION "1.0"
int help(void);
void setrgb(int color);

int () {
    int a, b = 0;
    int COLOR = 6;

    FILE* fp = fopen(SETTING_FILE, "rt");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &COLOR);
        fclose(fp);
        setrgb(COLOR);
    }

    while (b < 1)
    {
        printf("1�� ���򺯰�\n2�� ����\n");
        printf("��ȣ�� �Է��ϼ���.: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            help();
            setTextColor();
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
