#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


// ���α׷� ���� �޽���
#define PROGRAM_START "���� ����±�\n"
#define MENU_OPTION "(1) ���� �б�\n(2) ���� ����\n(3) ����\n: "
#define PROGRAM_EXIT "���α׷��� ����"

// ���� �޽���
#define ERROR_INVALID_INPUT "�߸��� �Է�"
#define ERROR_INVALID_FILENAME "�߸��� ���ϸ�"

// ���� �б� ���� �޽���
#define FILE_READER_MODE_OPTION  "�б� ���\n(1) �ؽ�Ʈ ��� (2) ���� ���\n: "
#define FILE_READER_START_READ "-���� ����-\n"

// ���� ���� ���� �޽���
#define FILE_WRITER_FILE_SELECTION_OPTION "���� ����\n(1) ���� ���� ����\n(2) �� ���� ����\n: "
#define FILE_WRITER_WRITE_MODE_OPTION "\n������ ����\n(1) ����� (2) �߰��ϱ�\n: "
#define FILE_WRITER_NEW_FILE_NAME "\n�� ���ϸ� : "

#define FILE_WRITER_FILE_TYPE_PROMPT "���� ����\n(1) �ؽ�Ʈ ���� (2) ���� ����\n: "
#define FILE_WRITER_ENTER_LINE_PROMPT "Enter�� �Է� (Ctrl+Z Enter�� ����):"
#define FILE_WRITER_EOC_INPUT_CONFIRM "EOC �Է� Ȯ��"

// ���� ���� ���� �޽���
#define FILE_MANAGER_READ_GET_FILE_OPTION "\n�о���� ���\n(1) filesystem\n(2) _findfirst\n(3) winapi\n: "
#define FILE_MANAGER_FILE_NAMES "\n���� ������ ����\n"
#define FILE_MANAGER_NO_FILES "���� ������ ������ �����ϴ�."
#define FILE_MANAGER_FILE_SELECT_PROMPT "������ ���� : "
