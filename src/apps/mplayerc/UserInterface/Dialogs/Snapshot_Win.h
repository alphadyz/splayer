#pragma once

#include <atlgdi.h>
#include <atlimage.h>
#include <memory>
#include "Snapshot_Viewfinder.h"

class CSnapshot_Win : public CDialogImpl<CSnapshot_Win>
{
// Normal part
public:
  CSnapshot_Win(const std::wstring &sSavePath);
  ~CSnapshot_Win();

// Internal part
private:
  std::tr1::shared_ptr<Gdiplus::Bitmap>      m_pigBKImage;
  std::tr1::shared_ptr<Gdiplus::Bitmap>      m_pigMemImage;
  std::tr1::shared_ptr<CSnapshot_Viewfinder> m_pwndViewfinder;

  LPDLGTEMPLATE                              m_pdialogTemplate;
  std::wstring                               m_sSavePath;

// Reimpl
public:
  INT_PTR DoModal(HWND hWndParent = ::GetActiveWindow(), LPARAM dwInitParam = NULL);

// Message handler
public:
  BEGIN_MSG_MAP_EX(CSnapshot_Win)
    MSG_WM_INITDIALOG(OnInitDialog)
    MSG_WM_DESTROY(OnDestroy)
    MSG_WM_KEYUP(OnKeyUp)
    MSG_WM_PAINT(OnPaint)
    MSG_WM_ERASEBKGND(OnEraseBkgnd)
    MSG_WM_MOUSEMOVE(OnMouseMove)
    MSG_WM_LBUTTONDOWN(OnLButtonDown)
    MSG_WM_LBUTTONUP(OnLButtonUp)
    MSG_WM_RBUTTONUP(OnRButtonUp)
    MSG_WM_LBUTTONDBLCLK(OnLButtonDblClk)
  END_MSG_MAP()

  BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam);
  void OnDestroy();

  void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
  void OnPaint(WTL::CDCHandle dc);
  BOOL OnEraseBkgnd(WTL::CDCHandle dc);

  void OnMouseMove(UINT nFlags, CPoint point);
  void OnLButtonDown(UINT nFlags, CPoint point);
  void OnLButtonUp(UINT nFlags, CPoint point);

  void OnRButtonUp(UINT nFlags, CPoint point);
  void OnLButtonDblClk(UINT nFlags, CPoint point);   // Save the image
};