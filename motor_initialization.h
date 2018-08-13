#ifndef MOTOR_INITIALIZATION_H
#define MOTOR_INITIALIZATION_H

#include "error_holder.h"
#include "QString"
//#include <AMONet.h>
//#include <AMONetError.h>


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

I16 motor_r_move(UINT m_DeviceIP, UINT AxisNum, FLOAT StrVel, FLOAT MaxVel, FLOAT Tacc, FLOAT Tdec,int distance);
I16 motor_home(UINT m_DeviceIP, UINT AxisNum, FLOAT StrVel, FLOAT MaxVel, FLOAT Tacc, FLOAT Tdec, CHAR way);

//-------------------------------------------

extern INT	X_shift_pos;
extern INT	Y_shift_pos;
extern INT	Z_shift_pos;
extern INT	X_tilt_pos;
extern INT	Y_tilt_pos;
extern INT	Rotion_pos;
extern INT	X_gule_pos;
extern INT	Y_gule_pos;

//----------Platform position----------------



#endif // MOTOR_INITIALIZATION_H
