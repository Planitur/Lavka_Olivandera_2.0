#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;

DataTable^ SelectWood();
DataTable^ SelectCore();
DataTable^ Cost(String^ str1, String^ str2);