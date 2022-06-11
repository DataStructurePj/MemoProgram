#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ARRAY_SIZE 100
#define LINKEDLIST_FILE_NAME "memolist.txt"
#define DATA_DIR "file/"
#define SETTING_FILE "setting.txt"

#define true 1
#define false 0
// ��� ���� �� 

#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>
#endif // !__STDIO_H__

#ifndef __WINDOWS_H__
#define __WINDOWS_H__
#include <windows.h>
#endif // !__WINDOWS_H__

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif // ! __STDLIB_H__

#ifndef __STRING_H__
#define __STRING_H__
#include <string.h>
#endif // !__STRING_H__

////Custom Header File
#ifndef __LIST_H__
#define __LIST_H__
#include "list.h"
#endif // !__LIST_H__

#ifndef __FM_H_
#define __FM_H_
#include "fileManager.h"
#endif // ! __FM_H_   

#ifndef __MENU_H_
#define __MENU_H_
#include "menu.h"
#endif // ! __MENU_H_

#ifndef __UTIL_H_
#define __UTIL_H_
#include "util.h"
#endif // ! __UTIL_H_
   

// ������� ���� ��

void editNewFile(int size);
void loadFiles(char data[][MAX_ARRAY_SIZE]);
void showOptionMenu();

void finish();


//�� ���α׷� �ε���(while�� ��), ��ũ�� ����Ʈ�� ���� �ҷ�������, 
//�����͸� �����Ѵ�. 