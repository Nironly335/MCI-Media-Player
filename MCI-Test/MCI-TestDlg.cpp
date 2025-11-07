
// MCI-TestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MCI-Test.h"
#include "MCI-TestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMCITestDlg dialog



CMCITestDlg::CMCITestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MCITEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMCITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMCITestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMCITestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMCITestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMCITestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMCITestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CMCITestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &CMCITestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMCITestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_DESTIN, &CMCITestDlg::OnBnClickedDestin)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMCITestDlg::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_TRACKZ, &CMCITestDlg::OnLbnSelchangeTrackz)
END_MESSAGE_MAP()


// CMCITestDlg message handlers

BOOL CMCITestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMCITestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMCITestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMCITestDlg::OnBnClickedButton1()
{
	CRect r;
	GetDlgItem(IDC_DESTIN)->GetWindowRect(r);
	ScreenToClient(r);
	mci.OpenFile(L"U:\\AVG-Programmierung\\MCI-Test\\MCI-Test\\files\\video.mpg");
	mci.SetVideoPosition(GetSafeHwnd(),
		CRect(r.left, r.top, r.Width(), r.Height()));

	mci.Play();
}


void CMCITestDlg::OnBnClickedButton3()
{
	
	mci.OpenFile(L"U:\\AVG-Programmierung\\MCI-Test\\MCI-Test\\files\\audio.mid");
	//mci.SetVideoPosition(GetSafeHwnd(), CRect(30, 60, 210, 140));
	mci.Play();
}


void CMCITestDlg::OnBnClickedButton2()
{
	
	mci.OpenFile(L"U:\\AVG-Programmierung\\MCI-Test\\MCI-Test\\files\\audio.mp3");
	//mci.SetVideoPosition(GetSafeHwnd(), CRect(30, 60, 210, 140));
	mci.Play();
}


void CMCITestDlg::OnBnClickedButton4()
{
	
	BYTE tracks;
	mci.OpenAudioCD(0, tracks);

	BYTE min, sek, frame;
	//mci.TMSFSeek(((CListBox*)GetDlgItem(IDC_TRACKZ))->GetCurSel() + 1, 0, 0, 0);
	((CListBox*)GetDlgItem(IDC_TRACKZ))->ResetContent();
	for (int i = 1; i <= tracks; i++) {
		mci.GetTrackLength(i, min, sek, frame);
		CString temp; // z.B.Eintrag in eine ListBox : -)
		temp.Format(L"[%02d] %02d:%02d", i, min, sek);
		((CListBox*)GetDlgItem(IDC_TRACKZ))->AddString(temp);
	}
	//mci.TMSFSeek(2, 0, 0, 0);
	mci.Play();
}

void CMCITestDlg::OnBnClickedButton5()
{
	mci.Play();
}


void CMCITestDlg::OnBnClickedButton6()
{
	mci.Pause();
}

void CMCITestDlg::OnBnClickedButton7()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}

void CMCITestDlg::OnBnClickedDestin()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}


void CMCITestDlg::OnLbnSelchangeList1()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}


void CMCITestDlg::OnLbnSelchangeTrackz()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}
