//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
using namespace std;
#include "Unit1.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VirtualStringTreeTable->NodeDataSize = sizeof(NodeStructure);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenFileButtonClick(TObject *Sender)
{
	wstring FileName;
	if (FileOpenDialog->Execute()) {
		FileName = FileOpenDialog->FileName.c_str();
		int res;
		if (FileName.empty() or (res = sqlite3_open16(FileName.c_str(), &database)) != SQLITE_OK) {
			sqlite3_close(database);
			Application->MessageBox(L"Ошибка открытия базы данных", L"Ошибка", MB_OK);
			return;
		}
	}
	else
	{
		Application->MessageBox(L"Ошибка открытия файла", L"Ошибка", MB_OK);
		return;
	}
	VirtualStringTreeTable->BeginUpdate();
	VirtualStringTreeTable->Clear();
	sqlite3_stmt* statement;
	int res;
	if ((res = sqlite3_prepare_v2(database, "SELECT * FROM urls", -1, &statement, NULL)) == SQLITE_OK) {
		while ((res = sqlite3_step(statement)) == SQLITE_ROW)
		{
			PVirtualNode initNode = VirtualStringTreeTable->AddChild(VirtualStringTreeTable->RootNode);
			NodeStructure* nodeData = (NodeStructure*)VirtualStringTreeTable->GetNodeData(initNode);
			nodeData->id = sqlite3_column_int64(statement, 0);
			nodeData->Title = (const wchar_t*)sqlite3_column_text16(statement, 2);
			nodeData->URL = (const wchar_t*)sqlite3_column_text16(statement, 1);
			nodeData->LastVisitTime = sqlite3_column_int64(statement, 5);
		}
		sqlite3_finalize(statement);
	}
	else
	{
		Application->MessageBox(L"Ошибка запроса к базе данных", L"Ошибка", MB_OK);
		sqlite3_close(database);
		return;
	}
	VirtualStringTreeTable->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VSTGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
	if (!Node) return;

	NodeStructure* nodeData = (NodeStructure*)Sender->GetNodeData(Node);
	switch(Column)
	{
		case 0:
			CellText = nodeData->Title;
			break;
		case 1:
			CellText = nodeData->URL;
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteNodeButtonClick(TObject *Sender)
{
	PVirtualNode selectedNode = VirtualStringTreeTable->FocusedNode;
	if (!selectedNode) return;
	NodeStructure* nodeData = (NodeStructure*)VirtualStringTreeTable->GetNodeData(selectedNode);
	stringstream SQLss;
	SQLss << "DELETE FROM urls WHERE id = " << nodeData->id;
	string SQLtmp = SQLss.str();
	const char* SQL = SQLtmp.c_str();
	char* err;
    int res;
	if ((res = sqlite3_exec(database, SQL, 0, 0, &err)) != SQLITE_OK) {
		Application->MessageBox(L"Ошибка удаления записи из базы данных", L"Ошибка", MB_OK);
		sqlite3_close(database);
		return;
	}
	VirtualStringTreeTable->DeleteNode(selectedNode);
	Application->MessageBox(L"Запись успешно удалена", L"", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VSTAddToSelection(TBaseVirtualTree *Sender, PVirtualNode Node)

{
	if (!Node) return;
	NodeStructure* nodeData = (NodeStructure*)Sender->GetNodeData(Node);
	LastVisitTimeLabel->Caption = nodeData->LastVisitTime;
}
//---------------------------------------------------------------------------

