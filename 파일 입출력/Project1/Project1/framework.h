#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


// 프로그램 관련 메시지
#define PROGRAM_START "파일 입출력기\n"
#define MENU_OPTION "(1) 파일 읽기\n(2) 파일 쓰기\n(3) 종료\n: "
#define PROGRAM_EXIT "프로그램을 종료"

// 오류 메시지
#define ERROR_INVALID_INPUT "잘못된 입력"
#define ERROR_INVALID_FILENAME "잘못된 파일명"

// 파일 읽기 관련 메시지
#define FILE_READER_MODE_OPTION  "읽기 모드\n(1) 텍스트 모드 (2) 이진 모드\n: "
#define FILE_READER_START_READ "-파일 내용-\n"

// 파일 쓰기 관련 메시지
#define FILE_WRITER_FILE_SELECTION_OPTION "파일 선택\n(1) 기존 파일 선택\n(2) 새 파일 선택\n: "
#define FILE_WRITER_WRITE_MODE_OPTION "\n쓰기모드 선택\n(1) 덮어쓰기 (2) 추가하기\n: "
#define FILE_WRITER_NEW_FILE_NAME "\n새 파일명 : "

#define FILE_WRITER_FILE_TYPE_PROMPT "파일 설정\n(1) 텍스트 파일 (2) 이진 파일\n: "
#define FILE_WRITER_ENTER_LINE_PROMPT "Enter로 입력 (Ctrl+Z Enter로 종료):"
#define FILE_WRITER_EOC_INPUT_CONFIRM "EOC 입력 확인"

// 파일 관리 관련 메시지
#define FILE_MANAGER_READ_GET_FILE_OPTION "\n읽어오기 방법\n(1) filesystem\n(2) _findfirst\n(3) winapi\n: "
#define FILE_MANAGER_FILE_NAMES "\n선택 가능한 파일\n"
#define FILE_MANAGER_NO_FILES "선택 가능한 파일이 없습니다."
#define FILE_MANAGER_FILE_SELECT_PROMPT "가져올 파일 : "
