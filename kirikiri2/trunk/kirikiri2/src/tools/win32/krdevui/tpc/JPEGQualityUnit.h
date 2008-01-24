//---------------------------------------------------------------------------
/*
	fgconvert   (graphic converter for transparent images)
	Copyright (C) 2000-2008 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
#ifndef JPEGQualityUnitH
#define JPEGQualityUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
void __fastcall ShowJPEGQualityForm(TForm *parent, int & quality);
//---------------------------------------------------------------------------
class TJPEGQualityForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TLabel *Label1;
	TTrackBar *TrackBar;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *QualityLabel;
	TButton *RestoreDefaultButton;
	TButton *OKButton;
	TButton *CancelButton;
	void __fastcall TrackBarChange(TObject *Sender);
	void __fastcall RestoreDefaultButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TJPEGQualityForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TJPEGQualityForm *JPEGQualityForm;
//---------------------------------------------------------------------------
#endif