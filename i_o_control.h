#ifndef I_O_CONTROL_H
#define I_O_CONTROL_H

#include "error_holder.h"

void init_Read();
BOOL Inputcheck(UCHAR portnum,UCHAR ckecknum);


void Output_Write();
void Input_Read();


extern UCHAR Output_port0;
extern UCHAR Output_port1;
extern UCHAR Output_port2;
extern UCHAR Output_port3;

extern UCHAR Input_port0;
extern UCHAR Input_port1;
extern UCHAR Input_port2;
extern UCHAR Input_port3;

//----------Output Bool Signal---------------
extern bool Stop_led;            //Port0,0
extern bool Work_led;            //Port0,1
extern bool Error_led;           //Port0,2
extern bool Pass_led;            //Port0,4
extern bool Fail_led;            //Port0,5
extern bool Glue_claw;           //Port0,6
extern bool LD_claw;             //Port0,7

extern bool LD_neg_pressure;     //Port1,0
extern bool Unknow_neg_pressure; //Port1,0
extern bool Lens_neg_pressure;   //Port1,0

extern bool Glue_pressure;       //Port2,3
extern bool Glue_machine;        //Port2,4
extern bool Lens_claw;           //Port2,5
extern bool block;               //Port2,7

extern bool UV_on;               //Port3,0
extern bool UV_off;              //Port3,1

//----------Output Signal On-----------------

extern INT	X_shift_pos;
extern INT	Y_shift_pos;
extern INT	Z_shift_pos;
extern INT	X_tilt_pos;
extern INT	Y_tilt_pos;
extern INT	Rotion_pos;
extern INT	X_gule_pos;
extern INT	Y_gule_pos;

//----------Platform position----------------
void Stop_led_On();
void Work_led_On();
void Error_led_On();
void Pass_led_On();
void Fail_led_On();
void Glue_claw_On();
void LD_claw_On();

void LD_neg_pressure_On();
void Unknow_neg_pressure_On();
void Lens_neg_pressure_On();

void Glue_pressure_On();
void Glue_machine_On();
void Lens_claw_On();
void block_On();

void UV_on_On();
void UV_off_On();

//----------Output Signal Off-----------------
void Stop_led_Off();
void Work_led_Off();
void Error_led_Off();
void Pass_led_Off();
void Fail_led_Off();
void Glue_claw_Off();
void LD_claw_Off();

void LD_neg_pressure_Off();
void Unknow_neg_pressure_Off();
void Lens_neg_pressure_Off();

void Glue_pressure_Off();
void Glue_machine_Off();
void Lens_claw_Off();
void block_Off();

void UV_on_Off();
void UV_off_Off();

#endif // I_O_CONTROL_H
