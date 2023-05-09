#include "Performer.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;
using namespace System::ComponentModel;
SqlConnection^ ExecutionStart() {                   //� �������� ������� �� 3 �����. 1 � 3 ������ �� �����, � 2 ����. ��� 1 �����
    // �������� �������� ��� ����������� � ���������� SQL-��������
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    // ��������� ���������� �����������
    connStringBuilder->DataSource = "DESKTOP-D69Q8OK"; // ��� ������ �������
    connStringBuilder->InitialCatalog = "Olivander"; // ��� ����� ���� ������
    connStringBuilder->IntegratedSecurity = true; // ������������� Windows-��������������

    // ��������� �������� ����������� ��� ������� SqlConnection
    conn->ConnectionString = connStringBuilder->ToString();

    // �������� SQL-�������
    return conn;
}

DataTable^ ExecutionEnd(SqlConnection^ conn, SqlCommand^ cmd) {             //��� 3 �����
    // �������� ���������� � ����� ������
    conn->Open();

    // ���������� SQL-������� � ��������� ����������� � ���� DataTable
    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    // �������� ����������
    conn->Close();

    // ����������� DataTable � ������������ �������
    return dt;
}

DataTable^ SelectWood() {                    //��� 2 �����. �������� ������� ��������� �� ��������
    SqlConnection^ conn = ExecutionStart();         //� ������� conn � 1 �����
    String^ sql = "SELECT wood_name as ��������� FROM wood";                //��� ��� ������, ������� � �����
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    //� ������������ ������� � 3 �����
}

DataTable^ SelectCore() {                               
    SqlConnection^ conn = ExecutionStart();         
    String^ sql = "SELECT core_name as ���������� FROM core";                
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    
}

DataTable^ Cost(String^ str1, String^ str2) {                    //������ ����
    String^ procent = "2.8";        //�������, �� ������� �� ����������
    SqlConnection^ conn = ExecutionStart();             
    String^ sql = "SELECT ("+procent+" * (wood.wood_cost + core.core_cost)) as ����_�������_�_�������� FROM wood, core WHERE wood.wood_name = \'" + str1 + "\' AND core.core_name = \'" + str2 + "\'";        
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    //� ������������ ������� � 3 �����
}