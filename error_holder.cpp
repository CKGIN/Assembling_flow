#include "error_holder.h"


BOOL ErrorHandler(short nRet)
{
    QString strString;
    if (!ADM_SUCCESS(nRet))
    {
        strString= QString("%1:%2").arg("Operation failed with error code:").arg(nRet);
        QMessageBox::warning(NULL,"Waring",strString);
        return  FALSE;
    }

    return  TRUE;
}
