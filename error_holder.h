#ifndef ERROR_HOLDER_H
#define ERROR_HOLDER_H

#include <windows.h>
#include "QMessageBox"

#include <AMONet.h>
#include <AMONetError.h>

extern UINT	m_RingNo;

BOOL ErrorHandler(short nRet);

#endif // ERROR_HOLDER_H
