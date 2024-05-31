//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.Dialogs.hpp>
#include "sqlite3.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *VirtualStringTreeTable;
	TButton *OpenFileButton;
	TButton *DeleteNodeButton;
	TLabel *LVThead;
	TLabel *LastVisitTimeLabel;
	TOpenDialog *FileOpenDialog;
	void __fastcall OpenFileButtonClick(TObject *Sender);
	void __fastcall VSTGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall DeleteNodeButtonClick(TObject *Sender);
	void __fastcall VSTAddToSelection(TBaseVirtualTree *Sender, PVirtualNode Node);

private:	// User declarations
	sqlite3* database;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct
{
	unsigned long long id;
	UnicodeString Title;
	UnicodeString URL;
	unsigned long long LastVisitTime;
} NodeStructure;
#endif
