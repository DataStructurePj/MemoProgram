#pragma once
#define COMMAND_SIZE 256

void setTitle(char *title);
void OnOff(int bool);
void initConsole();
void gotoxy(int x, int y);
void setPasswd();
void setTheme();
void selectTheme(int rgb[]);
void loadTheme();