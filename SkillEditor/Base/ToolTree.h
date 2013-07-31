#ifndef _TOOL_TREE_H_
#define _TOOL_TREE_H_

#define _CRT_SECURE_NO_WARNINGS

#include <afx.h>
#include <afxwin.h>
#include <afxcmn.h>
#include <afxdtctl.h>
#include "OptionTree.h"
#include "ToolDef.h"
#include "ToolApp.h"
#include "ACString.h"

BEGIN_NS_AC

class ToolTree : public COptionTree, public Module<ToolApp>
{
public:
	ToolTree(ToolApp* app);
	virtual ~ToolTree();
public:
	BOOL Create(RECT rcRect, CWnd* pWnd, UINT nID);
public:
	int Create();
public:
	int SetCurrentDB(const CString& strDBName);
	CString GetCurrentDB();
public:
	void OnSelect(int key);
public:
	void ResetSelectKey();
	void SelectKey(int key);
public:
	int InsertUndefinedRoot();
public:
	int UpdateOrInsertItemByKey(int key,CString& strDes,std::vector<CString>& vtLayers);
	int DeleteItemByKey(int key);
public:
	COptionTreeItem* FindItemByKey(int key);
protected:
	COptionTreeItem* FindOrCreateLayers(std::vector<CString>& vtLayers);
	COptionTreeItem* FindItemByInfoText(COptionTreeItem* otiRoot, const CString& strInfoText);
protected:
	static BOOL CALLBACK EnumFindItemByInfoText(COptionTree* otProp, COptionTreeItem* otiItem, LPARAM lParam);
private:
	int m_nLastSelKey;
	CString m_strDBName;
	COptionTreeItem* m_pUndefinedRoot;
};

class COptionTreeItemStaticEx : public COptionTreeItemStatic
{
public:
	virtual void OnSelect()
	{
		ToolTree* pTree = (ToolTree*)m_otOption;
		CString key = GetInfoText();
		pTree->OnSelect(atoi(CStringToStlString(key).c_str()));
	}
};

END_NS_AC

#endif//_TOOL_TREE_H_