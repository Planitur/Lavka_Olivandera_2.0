#include "MyForm.h" //���� � ��� ������ �������� ������������� �����, �� ������ ���

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;

// �������� ������� ���������
[STAThreadAttribute] // ������� ��� ��������� ��������� ������ ����������
void main() {
	// ��������� �������� ���������� � ������ ��� Windows Forms
	Application::SetCompatibleTextRenderingDefault(false); // ���������� ������������ ���������� ����������
	Application::EnableVisualStyles(); // ��������� ������ Windows Forms

	LavkaOlivandera::MyForm form; // �������� ���������� ������ MyForm (��������������, ��� ����� ����� ���������� � �������)
	Application::Run(% form); // ������ ���������� � ��������� ����� � �������� ��������� ����
}


