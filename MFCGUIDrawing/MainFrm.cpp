
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "MFCGUIDrawing.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_32771, &CMainFrame::OnOpenPDBA)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_VS_2008);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("메뉴 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// 메뉴 모음을 활성화해도 포커스가 이동하지 않게 합니다.
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// 사용자 정의 도구 모음 작업을 허용합니다.
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: 도구 모음 및 메뉴 모음을 도킹할 수 없게 하려면 이 다섯 줄을 삭제하십시오.
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);


	// Visual Studio 2005 스타일 도킹 창 동작을 활성화합니다.
	CDockingManager::SetDockingMode(DT_SMART);
	// Visual Studio 2005 스타일 도킹 창 자동 숨김 동작을 활성화합니다.
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 보관된 값에 따라 비주얼 관리자 및 스타일을 설정합니다.
	OnApplicationLook(theApp.m_nAppLook);

	// 도구 모음 및 도킹 창 메뉴 바꾸기를 활성화합니다.
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// 빠른(<Alt> 키를 누른 채 끌기) 도구 모음 사용자 지정을 활성화합니다.
	CMFCToolBar::EnableQuickCustomization();

	if (CMFCToolBar::GetUserImages() == NULL)
	{
		// 사용자 정의 도구 모음 이미지를 로드합니다.
		if (m_UserImages.Load(_T(".\\UserImages.bmp")))
		{
			CMFCToolBar::SetUserImages(&m_UserImages);
		}
	}

	// 메뉴 개인 설정을 활성화합니다(가장 최근에 사용한 명령).
	// TODO: 사용자의 기본 명령을 정의하여 각 풀다운 메뉴에 하나 이상의 기본 명령을 포함시킵니다.
	CList<UINT, UINT> lstBasicCommands;

	lstBasicCommands.AddTail(ID_FILE_NEW);
	lstBasicCommands.AddTail(ID_FILE_OPEN);
	lstBasicCommands.AddTail(ID_FILE_SAVE);
	lstBasicCommands.AddTail(ID_FILE_PRINT);
	lstBasicCommands.AddTail(ID_APP_EXIT);
	lstBasicCommands.AddTail(ID_EDIT_CUT);
	lstBasicCommands.AddTail(ID_EDIT_PASTE);
	lstBasicCommands.AddTail(ID_EDIT_UNDO);
	lstBasicCommands.AddTail(ID_APP_ABOUT);
	lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2003);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_VS_2005);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLUE);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_SILVER);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLACK);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_AQUA);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_WINDOWS_7);

	CMFCToolBar::SetBasicCommands(lstBasicCommands);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWndEx::PreCreateWindow(cs))
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* 메뉴를 검색합니다. */);
	pDlgCust->EnableUserDefinedToolbars();
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp, LPARAM lp)
{
	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp, lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	// 기본 클래스가 실제 작업을 수행합니다.

	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// 모든 사용자 도구 모음에 사용자 지정 단추를 활성화합니다.
	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	for (int i = 0; i < iMaxUserToolbars; i++)
	{
		CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
		if (pUserToolbar != NULL)
		{
			pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
		}
	}

	return TRUE;
}


inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{//일일이 다 확인해라 
	s.erase(0, s.find_first_not_of(t)); // erase(시작 인덱스, 삭제할 문자 개수)
	return s;    // find_first_not_of = first부터 string의 length-1까지 0이 아닐 때 까지의 인덱스를 구해주는 함수
}
// trim from right 
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
	s.erase(s.find_last_not_of(t) + 1);
	return s; //  find_last_not_of 함수는 string의 length - 1부터 first까지 찾아 0이 아닐 때 까지의 인덱스를 반환
}
// trim from left & right 
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
	return ltrim(rtrim(s, t), t);
}

bool vStringToBool(const std::string & v)
{
	return !v.empty() &&
		(_stricmp(v.c_str(), "true") == 0 ||
			atoi(v.c_str()) != 0);
	//atoi 함수에 문자열을 넣어주면 정수가 반환,처음부터 숫자가 아니면 0으로 변환

	/* strcmp 설명
	모든 영문자는 비교 전에 소문자로 변환
	0보다 작음	string1이 string2보다 작음
	0	string1이 string2와 같음
	0보다 큼	string1이 string2보다 큼
	*/
}

void CMainFrame::vAddMaterial(CMaterialArray* pPcbMaterial, CMaterial* pMaterial)
{
	CMaterial* TmpMaterial = pMaterial->clone();
	pPcbMaterial->Add(TmpMaterial);
}

void CMainFrame::OnOpenPDBA()
{
	static TCHAR BASED_CODE FileFilter[] = _T("PDBA파일(*.pdba)|*.pdba|*.PDBA||");

	CFileDialog FileDialog(TRUE, _T("*.pdba"), _T("PollEx_New_Sample"), OFN_HIDEREADONLY, FileFilter);
	//파일 열기(True) 및 저장모드(False),기본 확장자,기본 파일명, 열기모드(읽기 전용 파일을 보이지 않고, 덮어 쓰기를 할 경우 덮어 쓴다는 경고 메세지를 보여 준다), 
	//읽기 전용 파일은 숨김
	CString sPathName;
	if (IDOK == FileDialog.DoModal())
	{
		sPathName = FileDialog.GetPathName(); // 파일 경로 가져와서

		int nExt = sPathName.ReverseFind('.');  
		CString sExtension = sPathName.Mid(nExt + 1);
		if (sExtension == "pdba" || sExtension == "PDBA")
			MessageBox(sPathName); // 메시지 박스에 띄움
		else
			MessageBox("PDBA 파일이 아닙니다 다시 파일 선택 해주세요");
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	char cLine[1000];
	int nClassName;
	ifstream  ReadFileStrem; // 파일 읽기
	bool bNetListRef = false;
	bool bRefAfterFirst = false;

	ReadFileStrem.open(sPathName);
	if (ReadFileStrem.is_open())
	{
		CPdb* pPdb = new CPdb();
		CMaterial* pMaterial = new CMaterial();
		CLibPadStack pLibPadStack;
		CGLayer* pGLayer = new CGLayer();
		CRNET *pRnet = new CRNET();
		CRef* pRef = new CRef();
		CNetListNet* pNetListNet = new CNetListNet();
		CPart* pPart = new CPart();
		CVoid *pVoid = new CVoid();
		CPolyline *pPolyline = new CPolyline();
		CPolygon *pPolygon = new CPolygon();
		CPadDefinition* pPadDefinition = new CPadDefinition();
		CViaDefinition* pViaDefinition = new CViaDefinition();
		CVia* pVia = new CVia();
		CLayerTypeName * pLayerTypeName = new CLayerTypeName();
		CConnectionType* pConnectionType = new CConnectionType();
		bool bNetClassList = false;
		bool bIsPadObj = false;
		bool bIsInsideVoid = false;
		int nPadDefinitionNum = 0;
		int nNetListReference = 0;
		int nLibArtworkLayNo;
		bool bIsSilkscreen = false;
		bool bIsCfigure = false;
		bool bIsPolygon = false;
		bool bIsPolyline = false;
		bool bIsPropertyEnd = false;
		bool bIsLoopFirst = false;
		bool bSecondLoop = false;
		bool bPolygonInsideVoid = false;
		bool bRefText2 = false;




		while (ReadFileStrem.getline(cLine, sizeof(cLine)))
		{
			string sLine = cLine;
			if (sLine.find("(INFORMATION") != string::npos)
				nClassName = 0;
			else if (sLine.find("(BOARD ") != string::npos)
				nClassName = 1;
			else if (sLine.find("(LIB_LAYER") != string::npos)
				nClassName = 2;
			else if (sLine.find("(LAYER_UNION") != string::npos)
				nClassName = 3;
			else if (sLine.find("(LIB_TURRET") != string::npos)
				nClassName = 4;
			else if (sLine.find("(LIB_SHAPE") != string::npos)
				nClassName = 5;
			else if (sLine.find("(LIB_TEXT") != string::npos)
				nClassName = 6;
			else if (sLine.find("(LIB_PADSTACK") != string::npos)
				nClassName = 7;
			else if (sLine.find("(LIB_VIA") != string::npos)
				nClassName = 8;
			else if (sLine.find("(LIB_COMPONENT") != string::npos)
				nClassName = 9;
			else if (sLine.find("(NETLIST_REFDESLIST") != string::npos)
				nClassName = 10;
			else if (sLine.find("(ROUTE") != string::npos)
				nClassName = 11;
			else if (sLine.find("(BOARDFIGURE") != string::npos)
				nClassName = 12;
			else if (sLine.find("(GERBER") != string::npos)
				nClassName = 13;

			cout << trim(string(cLine)) << endl;

			CArray<string> saTokenArray;
			stringstream sStream(trim(string(cLine)));
			string sToken, sTmp;
			bool bTokenExtend = false;
			bool bStringExtend = false;

			while (getline(sStream, sToken, ' '))
			{ // eof까지 while문을 돌린다.
				if (sToken.find("\"\")") != string::npos)
				{
					saTokenArray.Add(sToken);
				}
				else if (sToken.find("\"") != string::npos)
				{
					if (sToken[0] == '\"' && (sToken[sToken.length()-1] == '\"' || (sToken[sToken.length() - 1] == ')' && sToken[sToken.length() - 2] == '\"')))
					{
						saTokenArray.Add(sToken);
					}
					else if (bStringExtend == false)
					{
						sTmp = "";
						sTmp += sToken;
						bStringExtend = true;
					}
					else
					{
						sTmp += " ";
						sTmp += sToken;
						saTokenArray.Add(sTmp);
						bStringExtend = false;
					}
				}
				else if (bStringExtend)
				{
					sTmp += " ";
					sTmp += sToken;
				}
				else
					saTokenArray.Add(sToken);
			}
			//while (getline(sStream, sToken, ' ')) { // eof까지 while문을 돌린다.
			//	saTokenArray.Add(sToken);                                   
			//}
			switch (nClassName)
			{
			case 0://INFORMATION
				if (sLine.find("(POLLIWOGDATABASE") != string::npos)
				{
					pPdb->m_Information.m_PolliwogDatabase.m_sVersion = saTokenArray[1];
					saTokenArray[2].erase(saTokenArray[2].end() - 1);
					pPdb->m_Information.m_PolliwogDatabase.m_nMinorVersionNum = stoi(saTokenArray[2]);
				}
				else if (sLine.find("(IMPORTFILEVERSION") != string::npos)
				{
					pPdb->m_Information.m_ImportFileVersion.m_sECADTypeName = saTokenArray[1];
					pPdb->m_Information.m_ImportFileVersion.m_nMajorVerNum = stoi(saTokenArray[2]);
					saTokenArray[3].erase(saTokenArray[3].end() - 1);
					pPdb->m_Information.m_ImportFileVersion.m_nMinorVerNum = stoi(saTokenArray[3]);
				}
				else if (sLine.find("(UNIT ") != string::npos)
				{
					saTokenArray[1].erase(saTokenArray[1].size() - 1);
					pPdb->m_Information.m_Unit.m_sUnit = saTokenArray[1];
				}
				else if (sLine.find("(UNITSCALE") != string::npos)
				{
					saTokenArray[1].erase(saTokenArray[1].size() - 1);
					pPdb->m_Information.m_Unitscale.m_nUnitScale = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(AUTHOR") != string::npos)
				{
					if (saTokenArray[1] == "\"\"")
						pPdb->m_Information.m_Author.m_sMakerName = "\"\"";
					else
					{
						saTokenArray[1].erase(saTokenArray[1].size() - 1);
						pPdb->m_Information.m_Author.m_sMakerName = saTokenArray[1];
					}
				}
				else if (sLine.find("(DATE") != string::npos)
				{
					if (saTokenArray[1] == "\"\"")
						pPdb->m_Information.m_Date.m_sMakingDate = "\"\"";
					else
					{
						for (int i = 1; i < saTokenArray.GetSize(); i++)
						{
							if (saTokenArray.GetSize() - 1 == i)
								saTokenArray[i].erase(saTokenArray[i].size() - 1);
							pPdb->m_Information.m_Date.m_sMakingDate += saTokenArray[i];
						}
					}
				}
				else if (sLine.find("(FILEPATH") != string::npos)
				{
					saTokenArray[1].erase(saTokenArray[1].size() - 1);
					pPdb->m_Information.m_FilePath.m_sOrigianlEcadFilePath = saTokenArray[1];
				}
				else if (sLine.find("(INTERFACEFILEPATH") != string::npos)
				{
					saTokenArray[1].erase(saTokenArray[1].size() - 1);
					pPdb->m_Information.m_InterfaceFilePath.m_sInterfaceFilePath = saTokenArray[1];
				}
				else if (sLine.find("(COMMENT") != string::npos)
				{
					if (saTokenArray[1] == "\"\"")
						pPdb->m_Information.m_Comment.m_sComment = "\"\"";
					else
					{
						saTokenArray[1].erase(saTokenArray[1].size() - 1);
						pPdb->m_Information.m_Comment.m_sComment = saTokenArray[1];
					}
				}
				else if (sLine.find("(LIBRARYPARTPATH") != string::npos)
				{
					if (saTokenArray[1] == "\"\"")
						pPdb->m_Information.m_Comment.m_sComment = "\"\"";
					else
					{
						saTokenArray[1].erase(saTokenArray[1].size() - 1);
						pPdb->m_Information.m_LibRaryPartPath.m_sLibRaryPartPath = saTokenArray[1];
					}
				}
				break;
			case 1: //BOARD
				if (sLine.find("(BOARD ") != string::npos)
				{
					pPdb->m_Board.m_nNoOfPhysicalLayers = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(DRAWINGAREA ") != string::npos)
				{
					pPdb->m_Board.m_DrawingArea.m_dLowLeftMinX = stod(saTokenArray[1]);
					pPdb->m_Board.m_DrawingArea.m_dLowLeftMaxY = stod(saTokenArray[2]);
					pPdb->m_Board.m_DrawingArea.m_dUpperRightX = stod(saTokenArray[3]);
					saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pPdb->m_Board.m_DrawingArea.m_dUpperRightY = stod(saTokenArray[4]);
				}
				else if (sLine.find("(PANEL") != string::npos)
				{
					if (saTokenArray.GetSize() != 2)
					{
						for (int i = 1; i < saTokenArray.GetSize(); i++)
						{
							if (i == saTokenArray.GetSize() - 1)
							{
								saTokenArray[i].erase(saTokenArray[i].end() - 1);
							}
							//Pdb.m_Board.m_Pannel.Add((CDrawObj)TokenVector[i]);
						}
						if (sLine.find("(SUBBOARD") != string::npos)
						{
							pPdb->m_Board.m_Pannel.m_Subboard.m_sSubBoardName = saTokenArray[1];
							for (int i = 2; i < saTokenArray.GetSize(); i++)
							{
								if (saTokenArray[i].find(")") != string::npos)
								{
									saTokenArray[i].erase(saTokenArray[i].end() - 1);
								}
								//Pdb.m_Board.m_Pannel.Add(TokenVector[i]);
							}
						}
					}
				}
				else if (sLine.find("(POLYLINE") != string::npos)
				{
					if (pPolyline->m_aDrawObj.GetSize()>0)
					{
						pPdb->m_Board.vAddPolylineToBoardOutline(pPolyline, nLibArtworkLayNo);
						delete pPolyline;
						pPolyline = new CPolyline();
					}
					nLibArtworkLayNo = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();// 캐스팅  벡터안에 포인터 CArray<line*> a
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					pPolyline->vAddLineAndArc(pLine);
					//Pdb.m_Board.m_aBoardOutline.Add(Line);
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc *pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					pPolyline->vAddLineAndArc(pArc);
					//Pdb.m_Board.m_aBoardOutline.Add(Arc);
				}
				else if (sLine.find("(STACKUP") != string::npos)
				{
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_Board.vAddPolylineToBoardOutline(pPolyline, nLibArtworkLayNo);
						delete pPolyline;
						pPolyline = new CPolyline();
					}
				}
				else if (sLine.find("(LAY ") != string::npos)
				{
					CStackUp* pStackUp = new CStackUp();
					pStackUp->m_sLayerType = saTokenArray[1];
					pStackUp->m_nArtworkLayNo = stoi(saTokenArray[2]);
					pStackUp->m_nPhysicalLayerNo = stoi(saTokenArray[3]);
					pStackUp->m_sConductingMaterial = saTokenArray[4];
					pStackUp->m_sDielectricMaterial = saTokenArray[5];
					pStackUp->m_dThickness = stod(saTokenArray[6]);
					pStackUp->m_dTraceWidthDifference = stod(saTokenArray[7]);
					saTokenArray[8].erase(saTokenArray[8].end() - 1);
					pStackUp->m_nWiderTraceSide = stoi(saTokenArray[8]);
					pPdb->m_Board.m_aStackUp.Add(pStackUp->clone());
					delete pStackUp;
				}
				else if (sLine.find("(Material ") != string::npos)
				{
					pMaterial->m_sMaterialName = saTokenArray[1];
					pMaterial->m_sMaterialType = saTokenArray[2];
					pMaterial->m_dThermalConductivityX = stod(saTokenArray[3]);
					pMaterial->m_dThermalConductivityY = stod(saTokenArray[4]);
					pMaterial->m_dThermalConductivityZ = stod(saTokenArray[5]);
				}
				else if (sLine.find("(Frequency ") != string::npos)
				{
					pMaterial->m_Frequency.m_dFrequency = stod(saTokenArray[1]);
					pMaterial->m_Frequency.m_dElectricProperty1 = stod(saTokenArray[2]);
					saTokenArray[3].erase(saTokenArray[3].end() - 1);
					pMaterial->m_Frequency.m_dElectricProperty2 = stod(saTokenArray[3]);
					vAddMaterial(&pPdb->m_Board.m_LibMaterial.m_aMaterial, pMaterial);
					delete pMaterial;
					pMaterial = new CMaterial();
					cout << "d" << endl;
				}
				else if (sLine.find("(FLEXIBLE_AREA ") != string::npos)
				{
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dMinX = stod(saTokenArray[1]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dMinY = stod(saTokenArray[2]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dMaxX = stod(saTokenArray[3]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dMaxY = stod(saTokenArray[4]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_sTopLayerName = stod(saTokenArray[5]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_sBottomLayerName = stod(saTokenArray[6]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_sCoverlayMaterialName = stod(saTokenArray[7]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dTopCoverlayThickness = stod(saTokenArray[8]);
					pPdb->m_Board.m_RigidFlexiblePcb.m_FlexibleAreas.m_FlexibleArea.m_dBottomCoverlayThickness = stod(saTokenArray[9]);
				}
				break;
			case 2: //LIB_LAYER				if (sLine.find("(LAY ") != string::npos)
				if (sLine.find("(LAY ") != string::npos)
				{
					CLay* pLay = new CLay();
					pLay->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLay->m_nEcadLayNum = stoi(saTokenArray[2]);
					pLay->m_nPhysicalLayNo = stoi(saTokenArray[3]);
					pLay->m_sLayerName = saTokenArray[4]; 
					pLay->m_sLayerType = saTokenArray[5];
					pLay->m_sNetName = saTokenArray[6]; 
					pLay->m_sPolarity = saTokenArray[7];
					pLay->m_sComment = saTokenArray[8]; 
					pLay->m_nRed = stoi(saTokenArray[9]);
					pLay->m_nGreen = stoi(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLay->m_nBlue = stoi(saTokenArray[11]);
					pPdb->m_LibLayer.m_aLay.Add(pLay->clone());
					delete pLay;
				}
				break;
			case 3: // LAYER_UNION
				if (sLine.find("(ALU ") != string::npos)
				{
					pPdb->m_LayerUnion.m_Alu.m_sUnionName = stoi(saTokenArray[1]);
					saTokenArray[2].erase(saTokenArray[2].end() - 1);
					pPdb->m_LayerUnion.m_Alu.m_nArtworkLayNo = stoi(saTokenArray[2]);
				}
				break;
			case 4: // lib_turret
				if (sLine.find("(TUR ") != string::npos)
				{
					CTur* pTur = new CTur();
					pTur->m_nLibTurretNo = stoi(saTokenArray[1]);
					pTur->m_sTurretType = saTokenArray[2];
					pTur->m_dInnerSize = stod(saTokenArray[3]);
					if (saTokenArray[4].find(")") != string::npos)
						saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pTur->m_dOuterSize = stod(saTokenArray[4]);
					pTur->m_Wing.m_dWingAngle = NULL;
					pTur->m_Wing.m_dWingDistance = NULL;
					pTur->m_Wing.m_nWingCount1 = NULL;
					pTur->m_Wing.m_nWingCount2 = NULL;
					pTur->m_Wing.m_nWingCount3 = NULL;
					pTur->m_Wing.m_nWingCount4 = NULL;
					pPdb->m_LibTurret.m_aTur.Add(pTur->clone());
					delete pTur;
					//vAddMaterial(&Pdb.m_Board.m_LibMaterial.m_aMaterial, pMaterial);
				}
				else if (sLine.find("(WING ") != string::npos)
				{
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_dWingAngle = stod(saTokenArray[1]);
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_dWingDistance = stod(saTokenArray[2]);
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_nWingCount1 = stoi(saTokenArray[3]);
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_nWingCount2 = stoi(saTokenArray[4]);
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_nWingCount3 = stoi(saTokenArray[5]);
					saTokenArray[6].erase(saTokenArray[6].end() - 1);
					pPdb->m_LibTurret.m_aTur[pPdb->m_LibTurret.m_aTur.GetSize() - 1]->m_Wing.m_nWingCount4 = stoi(saTokenArray[6]);
				}
				break;
			case 5: // lib_PenType
				if (sLine.find("(LIB_PENTYPE ") != string::npos)
				{
					CLibPenType LibPenType;
					pPdb->m_LibPenType.m_PenType.m_nLibPenType = stoi(saTokenArray[1]);
					pPdb->m_LibPenType.m_PenType.m_nPenType = stoi(saTokenArray[2]);
					pPdb->m_LibPenType.m_PenType.m_nTurretNo = stoi(saTokenArray[3]);
					pPdb->m_LibPenType.m_PenType.m_dLineLength = stod(saTokenArray[4]);
					pPdb->m_LibPenType.m_PenType.m_dDotLineLength = stod(saTokenArray[5]);
					saTokenArray[6].erase(saTokenArray[6].end() - 1);
					pPdb->m_LibPenType.m_PenType.m_dLineSpace = stod(saTokenArray[6]);
				}
				break;
			case 6: // lib_text
				if (sLine.find("(TEXT ") != string::npos)
				{
					CLibTextText* pLibTextText = new CLibTextText();
					pLibTextText->m_nLibTextNo = stoi(saTokenArray[1]);
					pLibTextText->m_sFontName = saTokenArray[2];
					pLibTextText->m_sFontType = saTokenArray[3];
					pLibTextText->m_dTextHeight = stod(saTokenArray[4]);
					pLibTextText->m_dTextWidth = stod(saTokenArray[5]);
					pLibTextText->m_dTextSpace = stod(saTokenArray[6]);
					pLibTextText->m_dTextLineSpace = stod(saTokenArray[7]);
					pLibTextText->m_dTextThickness = stod(saTokenArray[8]);
					saTokenArray[9].erase(saTokenArray[9].end() - 1);
					pLibTextText->m_nEcadFontID = stoi(saTokenArray[9]);
					pPdb->m_LibText.m_aText.Add(pLibTextText->clone());
					delete pLibTextText;
				}
				break;
			case 7: // (LIB_PADSTACK
				if (sLine.find("(PAD ") != string::npos)
				{
					if (bIsLoopFirst)
					{
						if (pConnectionType->m_aDrawObj.GetSize() > 0)
						{
							pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
							delete pConnectionType;
							pConnectionType = new CConnectionType();
						}
						if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
						{
							pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
							delete pLayerTypeName;
							pLayerTypeName = new CLayerTypeName();
						}
						if (pPadDefinition->m_aLayerTypeName.GetSize() > 0)
						{
							pPdb->m_LibPadStack.m_aPadStackDefinition.Add(pPadDefinition->clone());
							delete pPadDefinition;
							pPadDefinition = new CPadDefinition();
						}
					}
					pPadDefinition->m_nLibPadStackNo = stoi(saTokenArray[1]);
					pPadDefinition->m_sPadStackName = saTokenArray[2];
					pPadDefinition->m_sPadstackType = saTokenArray[3];
					pPadDefinition->m_nLibTurretForHoleNo = stoi(saTokenArray[4]);
					pPadDefinition->m_sPlatedType = saTokenArray[5];
					pPadDefinition->m_nPadStackStartingArtworkLayNo = stoi(saTokenArray[6]);
					pPadDefinition->m_nPadstackEndingArtworkLayNo = stoi(saTokenArray[7]);
					bIsLoopFirst = true;
				}
				else if (sLine.find("(TOP") != string::npos)
				{
					if (bSecondLoop)
					{
						if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
						{
							pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
							delete pLayerTypeName;
							pLayerTypeName = new CLayerTypeName();
						}
					}
					pLayerTypeName->m_sLayerTypeName = "TOP";
					bSecondLoop = true;
				}
				else if (sLine.find("(INNERSIGNAL") != string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "INNERSIGNAL";
				}
				else if (sLine.find("(INNERPLANE") != string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "INNERPLANE";
				}
				else if (sLine.find("(THERMAL") != string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "THERMAL";
				}
				else if (sLine.find("(HOLE") != string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "HOLE";
				}
				else if (sLine.find("(BOTTOM") != string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "BOTTOM";
				}
				else if (sLine.find("(CONNECT") != string::npos)
				{
					pConnectionType->m_sConnectionType = "CONNECT";
				}
				else if (sLine.find("(UNCONN") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();

					}
					pConnectionType->m_sConnectionType = "UNCONN";
				}
				else if (sLine.find("(ANTI") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();

					}
					pConnectionType->m_sConnectionType = "ANTI";
				}
				else if (sLine.find("(SOLDER") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();

					}
					pConnectionType->m_sConnectionType = "SOLDER";
				}
				else if (sLine.find("(METAL") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					pConnectionType->m_sConnectionType = "METAL";
				}
				else if (sLine.find("(POLYGON ") != string::npos)
				{
					if (bPolygonInsideVoid)
					{
						if (pPolygon->m_aDrawObj.GetSize() > 0)
							pVoid->m_aDrawObj.Add(pPolygon->clone());
					}
					else
					{
						if (pPolygon->m_aDrawObj.GetSize() > 0)
							pConnectionType->m_aDrawObj.Add(pPolygon->clone());
					}
					delete pPolygon;
					pPolygon = new CPolygon();
					pPolygon->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					bIsPadObj = true;
				}
				else if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					if (bIsPadObj)
						pPolygon->vAddLineAndArc(pLine);
					else
					{
						pConnectionType->m_sConnectionType = "";
						pConnectionType->m_aDrawObj.Add(pLine->clone());
						delete pLine;
					}
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc *pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					if (bIsPadObj)
						pPolygon->vAddLineAndArc(pArc);
					else
					{
						pConnectionType->m_sConnectionType = "";
						pConnectionType->m_aDrawObj.Add(pArc->clone());
						delete pArc;
					}
				}
				else if (sLine.find("(DPT ") != string::npos) //Arc
				{
					CPt *pPt = new CPt();
					pPt->m_dPtX = stod(saTokenArray[1]);
					pPt->m_dPtY = stod(saTokenArray[2]);
					pPt->m_nLibArtworkLayNum = stoi(saTokenArray[3]);
					saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pPt->m_nLibTurretNum = stoi(saTokenArray[4]);
					pConnectionType->m_aDrawObj.Add(pPt->clone());
					delete pPt;
				}
				else if (sLine.find("(VOID ") != string::npos) //Arc
				{
					pVoid->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					bPolygonInsideVoid = true;
				}
				else if (sLine.find(")") != string::npos && bIsPadObj)
				{
					if (pPolygon->m_aDrawObj.GetSize() > 0)
					{
						pConnectionType->m_aDrawObj.Add(pPolygon->clone());
						delete pPolygon;
						pPolygon = new CPolygon();
					}
					bIsPadObj = false;
				}
				break;
			case 8: // (LIB_VIA
				if (sLine.find("(LIB_VIA") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pPadDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					if (pPadDefinition->m_aLayerTypeName.GetSize() > 0)
					{
						pPdb->m_LibPadStack.m_aPadStackDefinition.Add(pPadDefinition->clone());
						delete pPadDefinition;
						pPadDefinition = new CPadDefinition();
					}

					bIsLoopFirst = false;
					bSecondLoop = false;
					bPolygonInsideVoid = false;
				}
				else if (sLine.find("(VIA ") != string::npos)
				{
					if (bIsLoopFirst)
					{
						if (pConnectionType->m_aDrawObj.GetSize() > 0)
						{
							pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
							delete pConnectionType;
							pConnectionType = new CConnectionType();
						}
						if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
						{
							pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
							delete pLayerTypeName;
							pLayerTypeName = new CLayerTypeName();
						}
						if (pViaDefinition->m_aLayerTypeName.GetSize() > 0)
						{
							pPdb->m_LibVia.m_aViaDefinition.Add(pViaDefinition->clone());
							delete pViaDefinition;
							pViaDefinition = new CViaDefinition();
						}

					}
					pViaDefinition->m_nLibViaNo = stoi(saTokenArray[1]);
					pViaDefinition->m_sViaName = saTokenArray[2];
					pViaDefinition->m_sViaType = saTokenArray[3];
					pViaDefinition->m_nLibTurretForHoleNo = stoi(saTokenArray[4]);
					pViaDefinition->m_sPlatedType = saTokenArray[5];
					pViaDefinition->m_nViaStartingArtworkLayNo = stoi(saTokenArray[6]);
					pViaDefinition->m_nViaEndingArtworkLayNo = stoi(saTokenArray[7]);
					bIsLoopFirst = true;
				}
				else if (sLine.find("(TOP") != string::npos)
				{
					if (bSecondLoop)
					{
						if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
						{
							pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
							delete pLayerTypeName;
							pLayerTypeName = new CLayerTypeName();
						}
					}
					pLayerTypeName->m_sLayerTypeName = "TOP";
					bSecondLoop = true;
				}
				else if (sLine.find("(INNERSIGNAL") != string::npos && sLine.find("(INNERSIGNAL)") == string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "INNERSIGNAL";
				}
				else if (sLine.find("(INNERPLANE") != string::npos && sLine.find("(INNERPLANE)") == string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "INNERPLANE";
				}
				else if (sLine.find("(THERMAL") != string::npos && sLine.find("(THERMAL)") == string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "THERMAL";
				}
				else if (sLine.find("(HOLE") != string::npos && sLine.find("(HOLE)") == string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "HOLE";
				}
				else if (sLine.find("(BOTTOM") != string::npos && sLine.find("(BOTTOM)") == string::npos)
				{
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					pLayerTypeName->m_sLayerTypeName = "BOTTOM";
				}
				else if (sLine.find("(CONNECT") != string::npos)
				{
					delete pConnectionType;
					pConnectionType = new CConnectionType();
					pConnectionType->m_sConnectionType = "CONNECT";
				}
				else if (sLine.find("(UNCONN") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					pConnectionType->m_sConnectionType = "UNCONN";
				}
				else if (sLine.find("(ANTI") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					pConnectionType->m_sConnectionType = "ANTI";
				}
				else if (sLine.find("(SOLDER") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					pConnectionType->m_sConnectionType = "SOLDER";
				}
				else if (sLine.find("(METAL") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					pConnectionType->m_sConnectionType = "METAL";
				}
				else if (sLine.find("(POLYGON ") != string::npos)
				{
					if (bPolygonInsideVoid)
					{
						if (pPolygon->m_aDrawObj.GetSize() > 0)
							pVoid->m_aDrawObj.Add(pPolygon->clone());
					}
					else
					{
						if (pPolygon->m_aDrawObj.GetSize() > 0)
							pConnectionType->m_aDrawObj.Add(pPolygon->clone());
					}
					delete pPolygon;
					pPolygon = new CPolygon();
					pPolygon->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					bIsPadObj = true;
				}
				else if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					if (bIsPadObj)
						pPolygon->vAddLineAndArc(pLine);
					else
					{
						pConnectionType->m_sConnectionType = "";
						pConnectionType->m_aDrawObj.Add(pLine->clone());
						delete pLine;
					}
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc *pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					if (bIsPadObj)
						pPolygon->vAddLineAndArc(pArc);
					else
					{
						pConnectionType->m_sConnectionType = "";
						pConnectionType->m_aDrawObj.Add(pArc->clone());
						delete pArc;
					}
				}
				else if (sLine.find("(DPT ") != string::npos) //Arc
				{
					CPt *pPt = new CPt();
					pPt->m_dPtX = stod(saTokenArray[1]);
					pPt->m_dPtY = stod(saTokenArray[2]);
					pPt->m_nLibArtworkLayNum = stoi(saTokenArray[3]);
					saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pPt->m_nLibTurretNum = stoi(saTokenArray[4]);
					pConnectionType->m_aDrawObj.Add(pPt->clone());
					delete pPt;
				}
				else if (sLine.find("(VOID ") != string::npos) //Arc
				{
					pVoid->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					bPolygonInsideVoid = true;
				}
				else if (sLine.find(")") != string::npos && bIsPadObj)
				{
					if (pPolygon->m_aDrawObj.GetSize() > 0)
					{
						pConnectionType->m_aDrawObj.Add(pPolygon->clone());
						delete pPolygon;
						pPolygon = new CPolygon();
					}
					bIsPadObj = false;
				}
				break;
			case 9:// (LIB_COMPONENT
				if (sLine.find("(PART ") != string::npos)
				{
					if (pConnectionType->m_aDrawObj.GetSize() > 0)
					{
						pLayerTypeName->m_aConnectionType.Add(pConnectionType->clone());
						delete pConnectionType;
						pConnectionType = new CConnectionType();
					}
					if (pLayerTypeName->m_aConnectionType.GetSize() > 0)
					{
						pViaDefinition->m_aLayerTypeName.Add(pLayerTypeName->clone());
						delete pLayerTypeName;
						pLayerTypeName = new CLayerTypeName();
					}
					if (pViaDefinition->m_aLayerTypeName.GetSize() > 0)
					{
						pPdb->m_LibVia.m_aViaDefinition.Add(pViaDefinition->clone());
						delete pViaDefinition;
						pViaDefinition = new CViaDefinition();
					}
					if (bIsPropertyEnd)
					{
						pPdb->m_LibComponent.m_aPart.Add(pPart->clone());
						delete pPart;
						pPart = new CPart();
					}
					pPart->m_nLibPartNo = stoi(saTokenArray[1]);
					pPart->m_dDrawingSizeX = stod(saTokenArray[2]);
					pPart->m_dDrawingSizeY = stod(saTokenArray[3]);
					pPart->m_dHeight = stod(saTokenArray[4]);
					pPart->m_bIsBroken = stoi(saTokenArray[5]);
					pPart->m_dHighHeight = stod(saTokenArray[6]);
					pPart->m_dLowHeight = stod(saTokenArray[7]);
					bIsPropertyEnd = true;
				}
				else if (sLine.find("(NAME ") != string::npos)
				{
					pPart->m_NameDefinition.m_sPartName = saTokenArray[1];
					pPart->m_NameDefinition.m_sEcadPartName = saTokenArray[2];
					pPart->m_NameDefinition.m_sPackageName = saTokenArray[3];
					pPart->m_NameDefinition.m_sDeviceName = saTokenArray[4];
					pPart->m_NameDefinition.m_sFunctionName = saTokenArray[5];
					pPart->m_NameDefinition.m_sPackageType = saTokenArray[6];
					pPart->m_NameDefinition.m_sReferencePrefix = saTokenArray[7];
					pPart->m_NameDefinition.m_sPlaceableLayer = saTokenArray[8];
					saTokenArray[9].erase(saTokenArray[9].end() - 1);
					pPart->m_NameDefinition.m_sFootPrintName = saTokenArray[9];
				}
				else if (sLine.find("(MPN ") != string::npos)
				{
					saTokenArray[1].erase(saTokenArray[1].end() - 1);
					pPart->m_CMPNNameDefinition.m_sMPNName = saTokenArray[1];
				}
				else if (sLine.find("(PIN ") != string::npos)
				{
					CPinDefinition* pPinDefinition = new CPinDefinition();
					pPinDefinition->m_nPinNo = stoi(saTokenArray[1]);
					pPinDefinition->m_sPinName = saTokenArray[2];
					pPinDefinition->m_sGatePinName = saTokenArray[3];
					pPinDefinition->m_sPinType = saTokenArray[4];
					pPinDefinition->m_nLibPadStackNo = stoi(saTokenArray[5]);
					pPinDefinition->m_dAngle = stod(saTokenArray[6]);
					pPinDefinition->m_nSymbolNo = stoi(saTokenArray[7]);
					pPinDefinition->m_dPtX = stod(saTokenArray[8]);
					saTokenArray[9].erase(saTokenArray[9].end() - 1);
					pPinDefinition->m_dPtY = stod(saTokenArray[9]);
					pPart->m_aPinDefinition.Add(pPinDefinition->clone());
					delete pPinDefinition;
				}
				else if (sLine.find("(SILKSCREEN") != string::npos)
				{
					bIsSilkscreen = true;
					bIsCfigure = false;
				}
				else if (sLine.find("(CFIGURE") != string::npos)
				{
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
						pPart->m_SilkScreenDefinition.m_aDrawObj.Add(pPolyline->clone());
						delete pPolyline;
						pPolyline = new CPolyline();
					}
					if (pPolygon->m_aDrawObj.GetSize() > 0)
					{
						pPolygon->m_nLibArtworkLayNo = nLibArtworkLayNo;
						pPart->m_SilkScreenDefinition.m_aDrawObj.Add(pPolygon->clone());
						delete pPolygon;
						pPolygon = new CPolygon();
					}
					bIsSilkscreen = false;
					bIsCfigure = true;
				}
				else if (sLine.find("(POLYLINE ") != string::npos)
				{
					bIsPolyline = true;
					bIsPolygon = false;
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;

						if (bIsSilkscreen)
						{
							pPart->m_SilkScreenDefinition.m_aDrawObj.Add(pPolyline->clone());
							delete pPolyline;
							pPolyline = new CPolyline();
						}
						if (bIsCfigure)
						{
							pPart->m_FigureDefinition.m_aDrawObj.Add(pPolyline->clone());
							delete pPolyline;
							pPolyline = new CPolyline();
						}
					}
					nLibArtworkLayNo = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(POLYGON ") != string::npos)
				{
					bIsPolyline = false;
					bIsPolygon = true;
					if (pPolygon->m_aDrawObj.GetSize() > 0)
					{
						pPolygon->m_nLibArtworkLayNo = nLibArtworkLayNo;
						if (bIsSilkscreen)
							pPart->m_SilkScreenDefinition.m_aDrawObj.Add(pPolygon->clone());
						if (bIsCfigure)
							pPart->m_FigureDefinition.m_aDrawObj.Add(pPolygon->clone());
						delete pPolygon;
						pPolygon = new CPolygon();
					}
					nLibArtworkLayNo = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					if (bIsPolyline)
						pPolyline->m_aDrawObj.Add(pLine->clone());
					if (bIsPolygon)
						pPolygon->m_aDrawObj.Add(pLine->clone());
					delete pLine;
				}
				else if (sLine.find("(PROPERTY") != string::npos)
				{
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
						pPart->m_FigureDefinition.m_aDrawObj.Add(pPolyline->clone());
						delete pPolyline;
						pPolyline = new CPolyline();
					}
					if (pPolygon->m_aDrawObj.GetSize() > 0)
					{
						pPolygon->m_nLibArtworkLayNo = nLibArtworkLayNo;
						pPart->m_FigureDefinition.m_aDrawObj.Add(pPolygon->clone());
						delete pPolygon;
						pPolygon = new CPolygon();
					}
				}
				else if (sLine.find("(PROP ") != string::npos)
				{
					CPropertys* pProperty = new CPropertys();
					pProperty->m_sPropertyContents = saTokenArray[1];
					saTokenArray[2].erase(saTokenArray[2].end() - 1);
					pProperty->m_sPropertyItem = saTokenArray[2];

					pPart->m_aProperty.Add(pProperty->clone());
					delete pProperty;
				}
				break;
			case 10://(NETLIST_REFDESLIST
				if (sLine.find("(REFDESLIST ") != string::npos)
				{
					pPdb->m_LibComponent.m_aPart.Add(pPart->clone());
					delete pPart;
					pPart = new CPart();
					pPdb->m_CNetListRefdesList.m_ReferenceList.m_sPointingType = saTokenArray[1];
				}
				else if (sLine.find("(REF ") != string::npos)
				{
					if (bRefAfterFirst)
					{
						pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.Add(pRef->clone());
						delete pRef;
						pRef = new CRef();
						bRefAfterFirst = false;
					}
					// REFDESLIST - Ref
					if (bNetListRef == false)
					{
						pRef->m_nLibPartNo = stoi(saTokenArray[1]);
						pRef->m_sReferenceName = saTokenArray[2];
						pRef->m_sPlacedLayer = saTokenArray[3];
						pRef->m_dPtX = stod(saTokenArray[4]);
						pRef->m_dPtY = stod(saTokenArray[5]);
						pRef->m_dAngle = stod(saTokenArray[6]);
						pRef->m_dECADAngle = stod(saTokenArray[7]);
						const char* pch = saTokenArray[8].c_str();
						pRef->m_cPassiveType = pch[0];
						pRef->m_dPassiveValue = stod(saTokenArray[9]);
						pRef->m_bReferenceTextReversePlaced = vStringToBool(saTokenArray[10]);
						pRef->m_bExistInBom = vStringToBool(saTokenArray[11]);
					}
					else if (bNetListRef == true)
					{
						CNetRef* NetRef = new CNetRef();
						NetRef->m_sReferenceName = saTokenArray[1];
						saTokenArray[2].erase(saTokenArray[2].end() - 1);
						NetRef->m_nPinNo = stoi(saTokenArray[2]);
						pNetListNet->m_aNetRef.Add(NetRef->clone());
						delete NetRef;
					}
				}
				else if (sLine.find("(REFTEXT ") != string::npos)
				{
					pRef->m_RefText.m_nLibTextNo = stoi(saTokenArray[1]);
					pRef->m_RefText.m_sString = saTokenArray[2];
					pRef->m_RefText.m_dAngle = stod(saTokenArray[3]);
					pRef->m_RefText.m_sMirror = saTokenArray[4];
					pRef->m_RefText.m_dPtX = stod(saTokenArray[5]);
					pRef->m_RefText.m_dPtY = stod(saTokenArray[6]);
					saTokenArray[7].erase(saTokenArray[7].end() - 1);
					pRef->m_RefText.m_nJustification = stoi(saTokenArray[7]);
				}
				else if (sLine.find("(DT ") != string::npos)
				{
					if (bRefText2)
					{
						CText * pText = new CText();
						pText->m_nArtworkLayNo = stoi(saTokenArray[1]);
						pText->m_nLibFontNo = stoi(saTokenArray[2]);
						pText->m_sValue = saTokenArray[3];
						pText->m_dAngle = stod(saTokenArray[4]);
						pText->m_sMirror = saTokenArray[5];
						pText->m_nJustification = stoi(saTokenArray[6]);
						pText->m_dPtX = stod(saTokenArray[7]);
						pText->m_dPtY = stod(saTokenArray[8]);
						pRef->m_RefText2.m_aDrawObj.Add(pText->clone());
						delete pText;
					}
				}
				else if (sLine.find("(REFTEXT2") != string::npos)
				{
					bRefText2 = true;
				}
				else if (sLine.find("(PINCONN ") != string::npos)
				{
					bRefText2 = false;
					CPinConnectionStatus* pPinConnectionStatus = new CPinConnectionStatus();
					pPinConnectionStatus->m_nPinNo = stoi(saTokenArray[1]);
					for (int i = 2; i < saTokenArray.GetSize(); i++)
					{
						if ( i == saTokenArray.GetSize() - 1 )
							saTokenArray[i].erase(saTokenArray[i].end() - 1);
						pPinConnectionStatus->m_asConnectionStatus.Add(saTokenArray[i]);
					}
					pRef->m_aPinConnectionStatus.Add(pPinConnectionStatus->clone());
					delete pPinConnectionStatus;
				}
				else if (sLine.find("(PROP ") != string::npos)
				{
					CPropertys* pProperty = new CPropertys();
					pProperty->m_sPropertyContents = saTokenArray[1];
					saTokenArray[2].erase(saTokenArray[2].end() - 1);
					pProperty->m_sPropertyItem = saTokenArray[2];
					pRef->m_aProperty.Add(pProperty->clone());
					bRefAfterFirst = true;
					delete pProperty;
				}
				else if (sLine.find("(NETLIST ") != string::npos)
				{
					pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.Add(pRef->clone());
					delete pRef;
					pRef = new CRef();
				}
				else if (sLine.find("(NET ") != string::npos)
				{
					if (pNetListNet->m_sNetName != "")
					{
						pPdb->m_CNetListRefdesList.m_NetList.m_aNetListNet.Add(pNetListNet->clone());
						delete pNetListNet;
						pNetListNet = new CNetListNet();
					}
					pNetListNet->m_sNetName = saTokenArray[1];
					pNetListNet->m_sNetType = saTokenArray[2];
					pNetListNet->m_nNetType = stoi(saTokenArray[3]);
					if (saTokenArray.GetSize() == 5)
						pNetListNet->m_sNetClassName = saTokenArray[4];
				}
				else if (sLine.find("(NETSTATUS ") != string::npos)
				{
					pNetListNet->m_NetStatus.m_nST1 = stoi(saTokenArray[1]);
					pNetListNet->m_NetStatus.m_nST2 = stoi(saTokenArray[2]);
					pNetListNet->m_NetStatus.m_nST3 = stoi(saTokenArray[3]);
					pNetListNet->m_NetStatus.m_nST4 = stoi(saTokenArray[4]);
				}
				else if (sLine.find("(ELECTRIC_CONSTRAINTS ") != string::npos)
				{
					bNetListRef = true;
					pNetListNet->m_ElectricConstraints.m_nTargetImpedance = stoi(saTokenArray[1]);
					pNetListNet->m_ElectricConstraints.m_dMininumDelay = stod(saTokenArray[2]);
					pNetListNet->m_ElectricConstraints.m_dMaximumDelay = stod(saTokenArray[3]);
					pNetListNet->m_ElectricConstraints.m_dMaximumCrosstalk = stod(saTokenArray[4]);
					pNetListNet->m_ElectricConstraints.m_dSignalDelay = stod(saTokenArray[5]);
					pNetListNet->m_ElectricConstraints.m_nOperatingFrequency = stoi(saTokenArray[6]);
					pNetListNet->m_ElectricConstraints.m_dMinimumFrequency = stod(saTokenArray[7]);
					pNetListNet->m_ElectricConstraints.m_dMaximumFrequency = stod(saTokenArray[8]);
					pNetListNet->m_ElectricConstraints.m_dEyeMaskHeight = stod(saTokenArray[9]);
					pNetListNet->m_ElectricConstraints.m_dEyeMaskWidthPercent = stod(saTokenArray[10]);
					pNetListNet->m_ElectricConstraints.m_dEyeMaskMiddleWidthPercent = stod(saTokenArray[11]);
					pNetListNet->m_ElectricConstraints.m_dVoltage = stod(saTokenArray[12]);
					pNetListNet->m_ElectricConstraints.m_nDiffPairNetIndex = stoi(saTokenArray[13]);
					pNetListNet->m_ElectricConstraints.m_dImpedanceTolerance = stod(saTokenArray[14]);
					pNetListNet->m_ElectricConstraints.m_dMaxCrosstalkJitter = stod(saTokenArray[15]);
					pNetListNet->m_ElectricConstraints.m_dDiffPairSkew = stod(saTokenArray[16]);
					pNetListNet->m_ElectricConstraints.m_dDifferentialImpedance = stod(saTokenArray[17]);
					pNetListNet->m_ElectricConstraints.m_dCommonImpedance = stod(saTokenArray[18]);
					pNetListNet->m_ElectricConstraints.m_dMaxFECrosstalk = stod(saTokenArray[19]);
					saTokenArray[20].erase(saTokenArray[20].end() - 1);
					pNetListNet->m_ElectricConstraints.m_dDiffImpedanceTolerance = stod(saTokenArray[20]);
				}
				else if (sLine.find("(NETBUSGROUP ") != string::npos)
				{
					CNetBusGroup* NetBusGroup = new CNetBusGroup();
					NetBusGroup->m_sBusGroupName = saTokenArray[1];
					NetBusGroup->m_dMaxBusSkew = stod(saTokenArray[2]);
					NetBusGroup->m_dMaxStrobedSkew = stod(saTokenArray[3]);
					NetBusGroup->m_sControlDevice = saTokenArray[4];
					pPdb->m_CNetListRefdesList.m_NetBusGroupList.m_aNetBusGroup.Add(NetBusGroup->clone());
					delete NetBusGroup;
				}
				else if (sLine.find("(STROBEDNET_INDEX ") != string::npos)
				{
					CStrobedNetIndex* StrobedNetIndex = new CStrobedNetIndex();
					for (int i = 1; i < saTokenArray.GetSize(); i++)
					{
						StrobedNetIndex->m_naStrobedNetIndex.Add(stoi(saTokenArray[i]));
					}
					pPdb->m_CNetListRefdesList.m_NetBusGroupList.m_aStrobedNetIndex.Add(StrobedNetIndex->clone());
					delete StrobedNetIndex;
				}
				else if (sLine.find("(NET_INDEX ") != string::npos)
				{
					CNetIndex* NetIndex = new CNetIndex();
					for (int i = 1; i < saTokenArray.GetSize(); i++)
					{
						NetIndex->m_naNetIndex.Add(stoi(saTokenArray[i]));
					}
					pPdb->m_CNetListRefdesList.m_NetBusGroupList.m_aNetIndex.Add(NetIndex->clone());
					delete NetIndex;
				}
				else if (sLine.find("(NETCLASSLIST") != string::npos)
				{
					bNetClassList = true;
				}
				else if (bNetClassList)
				{
					CNetClassList* pNetClassList = new CNetClassList();
					saTokenArray[0].erase(0, 1);
					pNetClassList->m_sClassName = saTokenArray[0];
					pNetClassList->m_saStringFilter.RemoveAll();
					for (int i = 1; i < saTokenArray.GetSize(); i++)
					{
						if (i == saTokenArray.GetSize() - 1)
							saTokenArray[saTokenArray.GetSize() - 1].erase(saTokenArray[saTokenArray.GetSize() - 1].end() - 1);
						pNetClassList->m_saStringFilter.Add(saTokenArray[i]);
					}
					pPdb->m_CNetListRefdesList.m_aNetClassList.Add(pNetClassList->clone());
					delete pNetClassList;
				}
				break;
			case 11: // (ROUTE
				if (sLine.find("(RNET ") != string::npos)
				{
					pRnet->m_sNetName = saTokenArray[1];
				}
				if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					pRnet->m_aDrawObj.Add(pLine->clone());
					delete pLine;
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc* pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					pRnet->m_aDrawObj.Add(pArc->clone());
					delete pArc;
				}
				else if (sLine.find("(DCM ") != string::npos)
				{
					CComp* pComp = new CComp();
					pComp->m_sPlaceLayer = saTokenArray[1];
					pComp->m_sReferenceName = saTokenArray[2];
					pComp->m_sPinNumber = saTokenArray[3];
					pComp->m_sTeardropExist = saTokenArray[4];
					pComp->m_dPtX = stod(saTokenArray[5]);
					saTokenArray[6].erase(saTokenArray[6].end() - 1);
					pComp->m_dPtY = stod(saTokenArray[6]);

					pRnet->m_aDrawObj.Add(pComp->clone());
					delete pComp;
				}
				else if (sLine.find("(DV ") != string::npos)
				{
					pVia->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pVia->m_nLibViaNo = stoi(saTokenArray[2]);
					pVia->m_dAngle = stod(saTokenArray[3]);
					pVia->m_sTearDropExist = saTokenArray[4];
					pVia->m_dPtX = stod(saTokenArray[5]);
					pVia->m_dPtY = stod(saTokenArray[6]);
				}
				else if (sLine.find("(LCS ") != string::npos)
				{
					for (int i = 1; i < saTokenArray.GetSize(); i++)
					{
						if (i == saTokenArray.GetSize() - 1)
							saTokenArray[i].erase(saTokenArray[i].end() - 1);
						pVia->m_PinConnectionStatus.m_asConnectionStatus.Add(saTokenArray[i]);
					}

					pRnet->m_aDrawObj.Add(pVia->clone());
					delete pVia;
					pVia = new CVia();
				}
				else if (sLine.find("(COLOR ") != string::npos)
				{
					pRnet->m_Color.m_nR = stoi(saTokenArray[1]);
					pRnet->m_Color.m_nG = stoi(saTokenArray[2]);
					saTokenArray[3].erase(saTokenArray[3].end() - 1);
					pRnet->m_Color.m_nB = stoi(saTokenArray[3]);
				}
				else if (sLine.find("(PADCOLOR ") != string::npos)
				{
					pRnet->m_PadColor.m_nR = stoi(saTokenArray[1]);
					pRnet->m_PadColor.m_nG = stoi(saTokenArray[2]);
					saTokenArray[3].erase(saTokenArray[3].end() - 1);
					pRnet->m_PadColor.m_nB = stoi(saTokenArray[3]);

					pPdb->m_Route.m_aRnet.Add(pRnet->clone());
					delete pRnet;
					pRnet = new CRNET();
				}
				break;
			case 12:// (BOARDFIGURE
				if (sLine.find("(POLYLINE ") != string::npos)
				{
					if (pVoid->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddVoidToBoardFigure(pVoid, nLibArtworkLayNo);
						delete pVoid;
						pVoid = new CVoid();
					}
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddPolylineToBoardFigure(pPolyline, nLibArtworkLayNo);
						delete pPolyline;
						pPolyline = new CPolyline();
					}
					nLibArtworkLayNo = stoi(saTokenArray[1]);
				}
				if (sLine.find("(VOID ") != string::npos)
				{
					if (pVoid->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddVoidToBoardFigure(pVoid, nLibArtworkLayNo);
						delete pVoid;
						pVoid = new CVoid();
					}

					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddPolylineToBoardFigure(pPolyline, nLibArtworkLayNo);
						delete pPolyline;
						pPolyline = new CPolyline();
					}
					nLibArtworkLayNo = stoi(saTokenArray[1]);
				}
				else if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					pPolyline->vAddLineAndArc(pLine);
					//Pdb.m_BoardFigure.m_aDrawObj.Add(Line);
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc* pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					pPolyline->vAddLineAndArc(pArc);
					//Pdb.m_BoardFigure.m_aDrawObj.Add(Arc);
				}
				else if (sLine.find("(DPT ") != string::npos)
				{
					CPt* pPt = new CPt();
					pPt->m_nLibArtworkLayNum = stoi(saTokenArray[1]);
					pPt->m_nLibTurretNum = stoi(saTokenArray[2]);
					pPt->m_dPtX = stod(saTokenArray[3]);
					saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pPt->m_dPtY = stod(saTokenArray[4]);
					pVoid->vAddPt(pPt);
					delete pPt;
					//Pdb.m_BoardFigure.m_aDrawObj.Add(Pt);
				}
				break;
			case 13://(GERBER
				if (sLine.find("(GERBER ") != string::npos || sLine.find("(GERBER") != string::npos)
				{
					if (pPolyline->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddPolylineToBoardFigure(pPolyline, nLibArtworkLayNo);
						delete pPolyline;
						pPolyline = new CPolyline();
					}

					if (pVoid->m_aDrawObj.GetSize() > 0)
					{
						pPdb->m_BoardFigure.vAddVoidToBoardFigure(pVoid, nLibArtworkLayNo);
						delete pVoid;
						pVoid = new CVoid();
					}
					pGLayer->m_aDrawObj.RemoveAll();
				}
				if (sLine.find("(DL ") != string::npos) //Line
				{
					CLine* pLine = new CLine();
					pLine->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pLine->m_nLibTurretNo = stoi(saTokenArray[2]);
					pLine->m_dStartPtX = stod(saTokenArray[3]);
					pLine->m_dStartPtY = stod(saTokenArray[4]);
					pLine->m_dEndPtX = stod(saTokenArray[5]);
					pLine->m_dEndPtY = stod(saTokenArray[6]);
					pLine->m_nStartFilletExist = stoi(saTokenArray[7]);
					pLine->m_dStartFilletLength = stod(saTokenArray[8]);
					pLine->m_nEndFilletExist = stoi(saTokenArray[9]);
					pLine->m_dEndFilletLength = stod(saTokenArray[10]);
					saTokenArray[11].erase(saTokenArray[11].end() - 1);
					pLine->m_nLibPenType = stoi(saTokenArray[11]);
					pGLayer->m_aDrawObj.Add(pLine->clone());
					delete pLine;
				}
				else if (sLine.find("(DA ") != string::npos) //Arc
				{
					CArc* pArc = new CArc();
					pArc->m_nLibArtworkLayNo = stoi(saTokenArray[1]);
					pArc->m_nLibTurretNo = stoi(saTokenArray[2]);
					pArc->m_dRadius = stod(saTokenArray[3]);
					pArc->m_dStartAngle = stod(saTokenArray[4]);
					pArc->m_dEndAngle = stod(saTokenArray[5]);
					pArc->m_sDirection = saTokenArray[6];
					pArc->m_dStartPtX = stod(saTokenArray[7]);
					pArc->m_dStartPtY = stod(saTokenArray[8]);
					pArc->m_dEndPtX = stod(saTokenArray[9]);
					pArc->m_dEndPtY = stod(saTokenArray[10]);
					pArc->m_dCenterPtX = stod(saTokenArray[11]);
					pArc->m_dCenterPtY = stod(saTokenArray[12]);
					saTokenArray[13].erase(saTokenArray[13].end() - 1);
					pArc->m_nLibPenType = stoi(saTokenArray[13]);
					pGLayer->m_aDrawObj.Add(pArc->clone());
					delete pArc;
				}
				else if (sLine.find("(DPT ") != string::npos)
				{
					CPt* pPt = new CPt();
					pPt->m_nLibArtworkLayNum = stoi(saTokenArray[1]);
					pPt->m_nLibTurretNum = stoi(saTokenArray[2]);
					pPt->m_dPtX = stod(saTokenArray[3]);
					saTokenArray[4].erase(saTokenArray[4].end() - 1);
					pPt->m_dPtY = stod(saTokenArray[4]);
					pGLayer->m_aDrawObj.Add(pPt->clone());
					delete pPt;
				}
				else if (sLine.find(") ") != string::npos)
				{
					pPdb->m_Gerber.m_aGLayer.Add(pGLayer->clone());
					delete pGLayer;
					pGLayer = new CGLayer();
				}
				break;
			default:
				cout << "default: " << nClassName << endl;
			}

			// cLine 초기화
			// 안필요할수도있어
		}

		//CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
		//CPDBAGUIDrawingView *pView = (CPDBAGUIDrawingView *)pFrame->GetActiveView();

		//CPDBAGUIDrawingView *pView = (CPDBAGUIDrawingView*)pOldOriginalActiveView;	// 뷰 주소할당
		//pView->Pdb = Pdb;  // 뷰의 함수 사용

		CMFCGUIDrawingView* pView = (CMFCGUIDrawingView*)GetActiveView();
		pView->vOnPDBChange(pPdb);
		//pView->RedrawWindow();
		delete pPdb;
		delete pMaterial;
		delete pGLayer;
		delete pRnet;
		delete pRef;
		delete pNetListNet;
		delete pPart;
		delete pVoid;
		delete pPolyline;
		delete pPolygon;
		delete pPadDefinition;
		delete pViaDefinition;
		delete pVia;
		delete pLayerTypeName;
		delete pConnectionType;

		//pOldOriginalActiveView->RedrawWindow();
		//Invalidate();
	}

	ReadFileStrem.close(); // 열었던 파일을 닫는다. 
}