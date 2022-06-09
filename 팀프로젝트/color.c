#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define THIS_PROGRAM_VERSION "1.0"

char this_program_name[] = "SETCLR";
void setrgb(char* s);
int help(void);

int main(int argc, char* argv[], char* env[]) {
    int a, b = 0;
    int COLOR;

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

int Command(int argc, char* argv[], char* env[])
{
    FILE* fpo;
    FILE* fpi;

    int COLOR;

    printf("���� ��ȣ�� �Է����ּ���.: ");
    scanf("%d", &COLOR);
    
    if (COLOR <= 15)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR);
    }
    else
    {
        printf("�߸��� ��ȣ�Դϴ�.");
    }

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

void setrgb(char* s) {
    WORD attr, previous_background_color;
    char fc, bc;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetConsoleScreenBufferInfo�� �ʿ�
    CONSOLE_SCREEN_BUFFER_INFO csbi;                    // GetConsoleScreenBufferInfo�� �ʿ�

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    // ������� ������ ȥ�յ� wAttributes���� ������ ����
    // 11111000 ��� ���� 4��Ʈ�� �����̹Ƿ� 4��Ʈ�� �������� �̵����״ٰ� ����ġ��Ű��
    // ���� ���ڸ� �� ������� 0000�� ä���� ������ ����.
    previous_background_color = csbi.wAttributes >> 0x4;
    previous_background_color = previous_background_color << 0x4;

    // strupr(s);
    // ���� �� ���� ��� �����Ǿ� ������ ó�� ���ڴ� ����, ���� ���ڴ� �����.
    // �� ���� ������ ������ �����
    // �̰��� MS�� color ����� �ɼ� ������
    // color �����, �� ���� �����ϸ� �����. �� ���� �����ϸ� �ջ��� �������� �ν��� ����.
    if (s[1] != 0) { // ���� �� ���� ��� �����Ǿ� ������
        bc = s[0]; fc = s[1];
    }
    else {         // �� ���� �����ϸ�
        fc = s[0]; bc = 'X';
    }

    /* Foreground Color */
    switch (fc) {
    case '0': // Black
        attr = 0;
        break;
    case '1': // Blue
        attr = FOREGROUND_BLUE;
        break;
    case '2': // Green
        attr = FOREGROUND_GREEN;
        break;
    case '3': // Aqua (Cyan)
        attr = FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
    case '4': // Red
        attr = FOREGROUND_RED;
        break;
    case '5': // Purple (Magenta)
        attr = FOREGROUND_RED | FOREGROUND_BLUE;
        break;
    case '6': // Yellow
        attr = FOREGROUND_RED | FOREGROUND_GREEN;
        break;
    case '7': // White (Gray: System Default)
        attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
    case '8': // Gray (Light Black)
        attr = FOREGROUND_INTENSITY;
        break;
    case '9': // Light Blue
        attr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case 'A': // Light Green
        attr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case 'B': // Light Aqua (Cyan)
        attr = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case 'C': // Light Red
        attr = FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case 'D': // Light Purple (Magenta)
        attr = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case 'E': // Light Yellow
        attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case 'F': // Bright White
        attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    default: help();
        break;
    }

    /* Background Color */
    switch (bc) {
    case 'X': // ������ ������ ���� ������ ������ ������ ���.
              // ������� �����ϸ� ������ �׻� �������� �Ǿ� ����.
        attr = attr | previous_background_color;
        break;
    case '0': // Black
        attr = attr | 0;
        break;
    case '1': // Blue
        attr = attr | BACKGROUND_BLUE;
        break;
    case '2': // Green
        attr = attr | BACKGROUND_GREEN;
        break;
    case '3': // Aqua (Cyan)
        attr = attr | BACKGROUND_GREEN | BACKGROUND_BLUE;
        break;
    case '4': // Red
        attr = attr | BACKGROUND_RED;
        break;
    case '5': // Purple (Magenta)
        attr = attr | BACKGROUND_RED | BACKGROUND_BLUE;
        break;
    case '6': // Yellow
        attr = attr | BACKGROUND_RED | BACKGROUND_GREEN;
        break;
    case '7': // White (Gray: System Default)
        attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
        break;
    case '8': // Gray (Light Black)
        attr = attr | BACKGROUND_INTENSITY;
        break;
    case '9': // Light Blue
        attr = attr | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case 'A': // Light Green
        attr = attr | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
        break;
    case 'B': // Light Aqua (Cyan)
        attr = attr | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case 'C': // Light Red
        attr = attr | BACKGROUND_RED | BACKGROUND_INTENSITY;
        break;
    case 'D': // Light Purple (Magenta)
        attr = attr | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case 'E': // Light Yellow
        attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
        break;
    case 'F': // Bright White
        attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    default: help();
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

int help(void) {
    printf("\n"
        "%s " THIS_PROGRAM_VERSION "\n"
        "(c) 2006 mwultong.blogspot.com\n"
        "\n"
        "Set Console Letter Color (Microsoft COLOR command compatible)\n"
        "\n\n"
        "Usage   : %s < Foreground Color >\n"
        "          %s < Background Color + Foreground Color >\n\n"
        "Example : %s f  :: Bright White\n"
        "          %s 1e :: Bright Yellow on Blue\n"
        "          %s 07 :: White on Black (System Default)\n"
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
        , this_program_name,
        this_program_name, this_program_name,
        this_program_name, this_program_name, this_program_name
    );
    return 0;
}