/*
This file is part of Explorer Plugin for Notepad++
Copyright (C)2006 Jens Lorenz <jens.plugin.npp@gmx.de>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#pragma once

#include <windows.h>
#include <commctrl.h>
#include <vector>
#include <string>


#ifndef TreeView_GetItemState
#define TVM_GETITEMSTATE (TV_FIRST+39)
#define TreeView_GetItemState(hwndTV, hti, mask) \
(UINT)::SendMessage((hwndTV), TVM_GETITEMSTATE, (WPARAM)(hti), (LPARAM)(mask))
#endif


class TreeHelper
{
public:
	TreeHelper() : _hTreeCtrl(NULL) {};
	~TreeHelper() {};

protected:
	std::vector<std::wstring> GetItemPathFromRoot(HTREEITEM currentItem) const;
	HTREEITEM InsertItem(const std::wstring &itemName, INT nImage, INT nSelectedIamage, INT nOverlayedImage, BOOL bHidden, HTREEITEM hParent, HTREEITEM hInsertAfter = TVI_LAST, BOOL haveChildren = FALSE, LPARAM lParam = NULL);
	BOOL UpdateItem(HTREEITEM hItem, const std::wstring &itemName, INT nImage, INT nSelectedIamage, INT nOverlayedImage, BOOL bHidden, BOOL haveChildren = FALSE, LPARAM lParam = NULL, BOOL delChildren = TRUE);
	void DeleteChildren(HTREEITEM parentItem);
	BOOL GetItemText(HTREEITEM hItem, LPTSTR szBuf, INT bufSize);
	std::wstring GetItemText(HTREEITEM hItem) const;
	LPARAM GetParam(HTREEITEM hItem);
	void SetParam(HTREEITEM hItem, LPARAM lParam);
	BOOL GetItemIcons(HTREEITEM hItem, LPINT iIcon, LPINT piSelected, LPINT iOverlay);
	void SetItemIcons(HTREEITEM hItem, INT icon, INT selected, INT overlay);
	BOOL IsItemExpanded(HTREEITEM hItem);
	INT GetChildrenCount(HTREEITEM item);

protected:
	HWND				_hTreeCtrl;
};
