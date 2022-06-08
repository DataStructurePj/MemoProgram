#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ARRAY_SIZE 100 
#define LINKEDLIST_FILE_NAME "memolist.txt"
#define DATA_DIR "file/"
// 상수 정의 끝 

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


//Custom Header File

#ifndef __KEY_H_
#define __KEY_H_
#include "key.h"
#endif // ! __KEY_H_

#ifndef __UTIL_H_
#define __UTIL_H_
#include "util.h"
#endif // ! __UTIL_H_

#ifndef __LIST_H__
#define __LIST_H__
#include "list.h"
#endif // !__LIST_H__

#ifndef __FM_H_
#define __FM_H_
#include "fileManager.h"
#endif // ! __FM_H_     

//#ifndef __DR_H_
//#define __DR_H_
//#include <direct.h>
//#endif // ! __DR_H_     

#ifndef __ERRNO_H_
#define __ERRNO_H_
#include <errno.h>
#endif // ! __ERRNO_H_     // 헤더파일 정의 끝






//매 프로그램 로딩시(while문 내), 링크드 리스트를 새로 불러옴으로, 
//데이터를 갱신한다. 