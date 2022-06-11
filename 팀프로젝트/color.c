#include "main.h"
#define THIS_PROGRAM_VERSION "1.0"
int help(void);
void setrgb(int color);

int main() {
    int a, b = 0;
    int COLOR = 7;

    FILE* fp = fopen("text1.txt", "rt");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &COLOR);
        fclose(fp);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR);
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

int Command()
{
    FILE* fpo;
    FILE* fpi;

    int COLOR = 0;

    printf("���� ��ȣ�� �Է����ּ���.: ");
    scanf("%d", &COLOR);
    
	setrgb(COLOR);

    fpo = fopen("text1.txt", "wt");
    if (fpo == NULL) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    fprintf(fpo, "%d", COLOR);
    fclose(fpo);

    fpi = fopen("text1.txt", "rt");
    if (fpi == NULL) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    fscanf(fpi, "%d", &COLOR);
    printf("\n%d���� ���̽��ϴ�.\n", COLOR);
    fclose(fpi);

    return 0;
}

void setrgb(int color) {
	WORD attr = 7;
   
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetConsoleScreenBufferInfo�� �ʿ�
    CONSOLE_SCREEN_BUFFER_INFO csbi;                    // GetConsoleScreenBufferInfo�� �ʿ�

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    /* Foreground Color */
    switch (color) {
    case 1: // Blue !
        attr = FOREGROUND_BLUE;
        break;
    case 2: // Green ! 
        attr = FOREGROUND_GREEN;
        break;
    case 4: // Red ! 
        attr = FOREGROUND_RED;
        break;
 
    case 6: // Yellow ! 
        attr = FOREGROUND_RED | FOREGROUND_GREEN;
        break; 
    case 7: // White (Gray: System Default) ! 
        attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
 
    default:
		printf("�߸��� ��ȣ�Դϴ�.");
		help();
        break;
    }

    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

int help(void) {
    printf("\n"
        
        "\n\n"
        "\t0 = Black (Invisible)               8 = Gray (Dark Gray)\n"
        "\t1 = Blue                            9 = Light Blue\n"
        "\t2 = Green                           10 = Light Green\n"
        "\t3 = Aqua (Cyan)                     11 = Light Aqua (Light Cyan)\n"
        "\t4 = Red                             12 = Light Red\n"
        "\t5 = Purple (Magenta)                13 = Light Purple (Light Magenta)\n"
        "\t6 = Yellow                          14 = Light Yellow\n"
        "\t7 = White (Gray: System Default)    15 = Bright White\n"
        "\n"
    
    );
    return 0;
}