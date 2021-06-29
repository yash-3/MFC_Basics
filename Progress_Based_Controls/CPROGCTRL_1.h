#pragma once

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated
// by Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CPROGCTRL_1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CPROGCTRL_1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x35053a22,0x8589,0x11d1,{0xb1,0x6a,0x00,0xc0,0xf0,0x28,0x36,0x28}};
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:
enum
{
	ccNone = 0,
	ccFixedSingle = 1
}BorderStyleConstants;

enum
{
	ccDefault = 0,
	ccArrow = 1,
	ccCross = 2,
	ccIBeam = 3,
	ccIcon = 4,
	ccSize = 5,
	ccSizeNESW = 6,
	ccSizeNS = 7,
	ccSizeNWSE = 8,
	ccSizeEW = 9,
	ccUpArrow = 10,
	ccHourglass = 11,
	ccNoDrop = 12,
	ccArrowHourglass = 13,
	ccArrowQuestion = 14,
	ccSizeAll = 15,
	ccCustom = 99
}MousePointerConstants;

enum
{
	ccFlat = 0,
	cc3D = 1
}AppearanceConstants;

enum
{
	vbFlat = 0,
	vb3D = 1
}VB4AppearanceConstants;

enum
{
	ccScrollingStandard = 0,
	ccScrollingSmooth = 1
}ScrollingConstants;

enum
{
	ccOrientationHorizontal = 0,
	ccOrientationVertical = 1
}OrientationConstants;

enum
{
	ccOLEDragManual = 0,
	ccOLEDragAutomatic = 1
}OLEDragConstants;

enum
{
	ccOLEDropNone = 0,
	ccOLEDropManual = 1
}OLEDropConstants;

enum
{
	ccEnter = 0,
	ccLeave = 1,
	ccOver = 2
}DragOverConstants;

enum
{
	ccCFText = 1,
	ccCFBitmap = 2,
	ccCFMetafile = 3,
	ccCFDIB = 8,
	ccCFPalette = 9,
	ccCFEMetafile = 14,
	ccCFFiles = 15,
	ccCFRTF = -16639
}ClipBoardConstants;

enum
{
	ccOLEDropEffectNone = 0,
	ccOLEDropEffectCopy = 1,
	ccOLEDropEffectMove = 2,
	ccOLEDropEffectScroll = 2147483648
}OLEDropEffectConstants;

enum
{
	ccInvalidProcedureCall = 5,
	ccOutOfMemory = 7,
	ccTypeMismatch = 13,
	ccObjectVariableNotSet = 91,
	ccInvalidPropertyValue = 380,
	ccSetNotSupportedAtRuntime = 382,
	ccSetNotSupported = 383,
	ccSetNotPermitted = 387,
	ccGetNotSupported = 394,
	ccInvalidPicture = 481,
	ccInvalidObjectUse = 425,
	ccWrongClipboardFormat = 461,
	ccDataObjectLocked = 672,
	ccExpectedAnArgument = 673,
	ccRecursiveOleDrag = 674,
	ccFormatNotByteArray = 675,
	ccDataNotSetForFormat = 676,
	ccIndexOutOfBounds = 35600,
	ccElemNotFound = 35601,
	ccNonUniqueKey = 35602,
	ccInvalidKey = 35603,
	ccElemNotPartOfCollection = 35605,
	ccCollectionChangedDuringEnum = 35606,
	ccWouldIntroduceCycle = 35614,
	ccMissingRequiredArg = 35607,
	ccBadObjectReference = 35610,
	ccCircularReference = 35700,
	ccCol1MustBeLeftAligned = 35604,
	ccReadOnlyIfHasImages = 35611,
	ccImageListMustBeInitialized = 35613,
	ccNotSameSize = 35615,
	ccImageListLocked = 35617,
	ccMaxPanelsExceeded = 35616,
	ccMaxButtonsExceeded = 35619,
	ccInvalidSafeModeProcCall = 680
}ErrorConstants;

enum
{
	tabJustified = 0,
	tabNonJustified = 1,
	tabFixed = 2
}TabWidthStyleConstants;

enum
{
	tabTabs = 0,
	tabButtons = 1,
	tabFlatButtons = 2
}TabStyleConstants;

enum
{
	tabPlacementTop = 0,
	tabPlacementBottom = 1,
	tabPlacementLeft = 2,
	tabPlacementRight = 3
}PlacementConstants;

enum
{
	tabTabStandard = 0,
	tabTabOpposite = 1
}TabSelStyleConstants;

enum
{
	tbrDefault = 0,
	tbrCheck = 1,
	tbrButtonGroup = 2,
	tbrSeparator = 3,
	tbrPlaceholder = 4,
	tbrDropdown = 5
}ButtonStyleConstants;

enum
{
	tbrUnpressed = 0,
	tbrPressed = 1
}ValueConstants;

enum
{
	tbrStandard = 0,
	tbrFlat = 1
}ToolbarStyleConstants;

enum
{
	tbrTextAlignBottom = 0,
	tbrTextAlignRight = 1
}ToolbarTextAlignConstants;

enum
{
	sbrNormal = 0,
	sbrSimple = 1
}SbarStyleConstants;

enum
{
	sbrLeft = 0,
	sbrCenter = 1,
	sbrRight = 2
}PanelAlignmentConstants;

enum
{
	sbrNoAutoSize = 0,
	sbrSpring = 1,
	sbrContents = 2
}PanelAutoSizeConstants;

enum
{
	sbrNoBevel = 0,
	sbrInset = 1,
	sbrRaised = 2
}PanelBevelConstants;

enum
{
	sbrText = 0,
	sbrCaps = 1,
	sbrNum = 2,
	sbrIns = 3,
	sbrScrl = 4,
	sbrTime = 5,
	sbrDate = 6,
	sbrKana = 7
}PanelStyleConstants;

enum
{
	tvwAutomatic = 0,
	tvwManual = 1
}LabelEditConstants;

enum
{
	tvwTreeLines = 0,
	tvwRootLines = 1
}TreeLineStyleConstants;

enum
{
	tvwTextOnly = 0,
	tvwPictureText = 1,
	tvwPlusMinusText = 2,
	tvwPlusPictureText = 3,
	tvwTreelinesText = 4,
	tvwTreelinesPictureText = 5,
	tvwTreelinesPlusMinusText = 6,
	tvwTreelinesPlusMinusPictureText = 7
}TreeStyleConstants;

enum
{
	tvwFirst = 0,
	tvwLast = 1,
	tvwNext = 2,
	tvwPrevious = 3,
	tvwChild = 4
}TreeRelationshipConstants;

enum
{
	lvwTransparent = 0,
	lvwOpaque = 1
}ListTextBackgroundConstants;

enum
{
	lvwNone = 0,
	lvwAutoLeft = 1,
	lvwAutoTop = 2
}ListArrangeConstants;

enum
{
	lvwTopLeft = 0,
	lvwTopRight = 1,
	lvwBottomLeft = 2,
	lvwBottomRight = 3,
	lvwCenter = 4,
	lvwTile = 5
}ListPictureAlignmentConstants;

enum
{
	lvwAutomatic = 0,
	lvwManual = 1
}ListLabelEditConstants;

enum
{
	lvwAscending = 0,
	lvwDescending = 1
}ListSortOrderConstants;

enum
{
	lvwIcon = 0,
	lvwSmallIcon = 1,
	lvwList = 2,
	lvwReport = 3
}ListViewConstants;

enum
{
	lvwColumnLeft = 0,
	lvwColumnRight = 1,
	lvwColumnCenter = 2
}ListColumnAlignmentConstants;

enum
{
	lvwText = 0,
	lvwSubItem = 1,
	lvwTag = 2
}ListFindItemWhereConstants;

enum
{
	lvwWhole = 0,
	lvwPartial = 1
}ListFindItemHowConstants;

enum
{
	imlNormal = 0,
	imlTransparent = 1,
	imlSelected = 2,
	imlFocus = 3
}ImageDrawConstants;

enum
{
	sldBottomRight = 0,
	sldTopLeft = 1,
	sldBoth = 2,
	sldNoTicks = 3
}TickStyleConstants;

enum
{
	sldAboveLeft = 0,
	sldBelowRight = 1
}TextPositionConstants;

enum
{
	ImgCboDropdownCombo = 0,
	ImgCboSimpleCombo = 1,
	ImgCboDropdownList = 2
}ImageComboStyleConstants;



// Operations
public:
// IProgressBar

// Functions
//

	float get_ControlDefault()
	{
		float result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, nullptr);
		return result;
	}
	void put_ControlDefault(float newValue)
	{
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	float get_Max()
	{
		float result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, nullptr);
		return result;
	}
	void put_Max(float newValue)
	{
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	float get_Min()
	{
		float result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, nullptr);
		return result;
	}
	void put_Min(float newValue)
	{
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_MousePointer()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_MousePointer(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_MouseIcon()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void putref_MouseIcon(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	void put_MouseIcon(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	float get_Value()
	{
		float result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, nullptr);
		return result;
	}
	void put_Value(float newValue)
	{
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_OLEDropMode()
	{
		long result;
		InvokeHelper(0x60F, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_OLEDropMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60F, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_Appearance()
	{
		long result;
		InvokeHelper(0xFFFFFDF8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Appearance(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xFFFFFDF8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_BorderStyle()
	{
		long result;
		InvokeHelper(0xFFFFFE08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_BorderStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xFFFFFE08, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_Enabled()
	{
		BOOL result;
		InvokeHelper(0xFFFFFDFE, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_Enabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xFFFFFDFE, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_hWnd()
	{
		long result;
		InvokeHelper(0xFFFFFDFD, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void OLEDrag()
	{
		InvokeHelper(0x610, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void AboutBox()
	{
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	long get_Orientation()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Orientation(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_Scrolling()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Scrolling(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void Refresh()
	{
		InvokeHelper(0xFFFFFDDA, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

// Properties
//



};
