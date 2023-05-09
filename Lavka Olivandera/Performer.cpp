#include "Performer.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;
using namespace System::ComponentModel;
SqlConnection^ ExecutionStart() {                   //Я разделил запросы на 3 части. 1 и 3 менять не нужно, а 2 надо. Это 1 часть
    // Создание объектов для подключения и выполнения SQL-запросов
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    // Настройка параметров подключения
    connStringBuilder->DataSource = "DESKTOP-D69Q8OK"; // Имя ВАШЕГО сервера
    connStringBuilder->InitialCatalog = "Olivander"; // Имя ВАШЕЙ базы данных
    connStringBuilder->IntegratedSecurity = true; // Использование Windows-аутентификации

    // Установка настроек подключения для объекта SqlConnection
    conn->ConnectionString = connStringBuilder->ToString();

    // Создание SQL-запроса
    return conn;
}

DataTable^ ExecutionEnd(SqlConnection^ conn, SqlCommand^ cmd) {             //Это 3 часть
    // Открытие соединения с базой данных
    conn->Open();

    // Выполнение SQL-запроса и получение результатов в виде DataTable
    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    // Закрытие соединения
    conn->Close();

    // Возвращение DataTable с результатами запроса
    return dt;
}

DataTable^ SelectWood() {                    //Это 2 части. Названия функций описывают их действия
    SqlConnection^ conn = ExecutionStart();         //я получаю conn с 1 части
    String^ sql = "SELECT wood_name as древесина FROM wood";                //это мой запрос, который я меняю
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    //а получившуюся таблицу с 3 части
}

DataTable^ SelectCore() {                               
    SqlConnection^ conn = ExecutionStart();         
    String^ sql = "SELECT core_name as сердцевина FROM core";                
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    
}

DataTable^ Cost(String^ str1, String^ str2) {                    //Расчёт цены
    String^ procent = "2.8";        //процент, на который всё умножается
    SqlConnection^ conn = ExecutionStart();             
    String^ sql = "SELECT ("+procent+" * (wood.wood_cost + core.core_cost)) as Цена_палочки_в_Галоннах FROM wood, core WHERE wood.wood_name = \'" + str1 + "\' AND core.core_name = \'" + str2 + "\'";        
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
    return ExecutionEnd(conn, cmd);                    //а получившуюся таблицу с 3 части
}