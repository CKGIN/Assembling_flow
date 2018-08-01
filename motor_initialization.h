#ifndef MOTOR_INITIALIZATION_H
#define MOTOR_INITIALIZATION_H

#include "error_holder.h"

//#include <AMONet.h>
//#include <AMONetError.h>

extern UINT	m_RingNo;

I16 Amotnet_init();
I16 ring_init();

I16 Xshift_init();
I16 Yshift_init();
I16 Zshift_init();
I16 Xtilt_init();
I16 Ytilt_init();
I16 Rotate_init();
I16 Xglue_init();
I16 Yglue_init();






#endif // MOTOR_INITIALIZATION_H
