#include "i_o_control.h"

UCHAR Output_port0 = 0;
UCHAR Output_port1 = 0;
UCHAR Output_port2 = 0;
UCHAR Output_port3 = 0;

UCHAR Input_port0 = 0;
UCHAR Input_port1 = 0;
UCHAR Input_port2 = 0;
UCHAR Input_port3 = 0;

bool Stop_led = FALSE;
bool Work_led = FALSE;
bool Error_led = FALSE;
bool Pass_led = FALSE;
bool Fail_led = FALSE;
bool Glue_claw = FALSE;
bool LD_claw = FALSE;

bool LD_neg_pressure = FALSE;
bool Unknow_neg_pressure = FALSE;
bool Lens_neg_pressure = FALSE;

bool Glue_pressure = FALSE;
bool Glue_machine = FALSE;
bool Lens_claw = FALSE;
bool block = FALSE;

bool UV_on = FALSE;
bool UV_off = FALSE;




void init_Read()
{

    Input_port0 = (UCHAR)_mnet_io_input(m_RingNo, 16 , 0);
    Input_port1 = (UCHAR)_mnet_io_input(m_RingNo, 16 , 1);
    Input_port2 = (UCHAR)_mnet_io_input(m_RingNo, 16 , 2);
    Input_port3 = (UCHAR)_mnet_io_input(m_RingNo, 16 , 3);

}

BOOL Inputcheck(UCHAR portnum,UCHAR ckecknum)
{
    UCHAR check;

    if(portnum > 3 || ckecknum > 7)
    {
        QMessageBox::warning(NULL,"Waring","Port or Check number error");
        return FALSE;
    }

    switch(portnum)
    {
        case 0 :
        {
            Input_port0 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port0 >> ckecknum;
            if(!check%2)
                return TRUE;
            return FALSE;
        }
        case 1 :
        {
            Input_port1 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port1 >> ckecknum;
            if(!check%2)
                return TRUE;
            return FALSE;
        }
        case 2 :
        {
            Input_port2 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port2 >> ckecknum;
            if(!check%2)
                return TRUE;
            return FALSE;
        }
        case 3 :
        {
            Input_port3 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port3 >> ckecknum;
            if(!check%2)
                return TRUE;
            return FALSE;
        }

    }

    return FALSE;
}

void Stop_led_On()
{
    if(!Stop_led)
    {
        Output_port0+=1;                                         //Output 01
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Stop_led=TRUE;
    }
}

void Work_led_On()
{
    if(!Work_led)
    {
        Output_port0+=2;                                        //Output 02
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Work_led=TRUE;
    }
}

void Error_led_On()
{
    if(!Error_led)
    {
        Output_port0+=4;                                        //Output 04
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Error_led=TRUE;
    }
}

void Pass_led_On()
{
    if(!Pass_led)
    {
        Output_port0+=16;                                        //Output 10
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Pass_led=TRUE;
    }
}

void Fail_led_On()
{
    if(!Fail_led)
    {
        Output_port0+=32;                                        //Output 20
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Fail_led=TRUE;
    }
}

void Glue_claw_On()
{
    if(!Glue_claw)
    {
        Output_port0+=64;                                        //Output 40
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Glue_claw=TRUE;
    }
}

void LD_claw_On()
{
    if(!LD_claw)
    {
        Output_port0+=128;                                        //Output 80
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        LD_claw=TRUE;
    }
}

//---port 1---

void LD_neg_pressure_On()
{
    if(!LD_neg_pressure)
    {
        Output_port1+=1;                                        //Output 01
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        LD_neg_pressure=TRUE;
    }
}

void Unknow_neg_pressure_On()
{
    if(!Unknow_neg_pressure)
    {
        Output_port1+=4;                                        //Output 04
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        Unknow_neg_pressure=TRUE;
    }
}

void Lens_neg_pressure_On()
{
    if(!Lens_neg_pressure)
    {
        Output_port1+=16;                                        //Output 10
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        Lens_neg_pressure=TRUE;
    }
}

//---port 2---

void Glue_pressure_On()
{
    if(!Glue_pressure)
    {
        Output_port2+=8;                                        //Output 08
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Glue_pressure=TRUE;
    }
}

void Glue_machine_On()
{
    if(!Glue_machine)
    {
        Output_port2+=16;                                        //Output 10
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Glue_machine=TRUE;
    }
}

void Lens_claw_On()
{
    if(!Lens_claw)
    {
        Output_port2+=32;                                        //Output 20
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Lens_claw=TRUE;
    }
}

void block_On()
{
    if(!block)
    {
        Output_port2+=128;                                        //Output 80
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        block=TRUE;
    }
}

void UV_on_On()
{
    if(!UV_on)
    {
        Output_port3+=1;                                        //Output 01
        _mnet_io_output(m_RingNo, 8, 3, Output_port3);
        UV_on=TRUE;
    }
}

void UV_off_On()
{
    if(!UV_off)
    {
        Output_port3+=2;                                        //Output 02
        _mnet_io_output(m_RingNo, 8, 3, Output_port3);
        UV_off=TRUE;
    }
}

void Stop_led_Off()
{
    if(Stop_led)
    {
        Output_port0-=1;                                         //Output 01
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Stop_led=FALSE;
    }
}

void Work_led_Off()
{
    if(Work_led)
    {
        Output_port0-=2;                                         //Output 02
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Work_led=FALSE;
    }
}

void Error_led_Off()
{
    if(Error_led)
    {
        Output_port0-=4;                                         //Output 04
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Error_led=FALSE;
    }
}

void Pass_led_Off()
{
    if(Pass_led)
    {
        Output_port0-=16;                                         //Output 10
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Pass_led=FALSE;
    }
}

void Fail_led_Off()
{
    if(Fail_led)
    {
        Output_port0-=32;                                         //Output 20
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Fail_led=FALSE;
    }
}

void Glue_claw_Off()
{
    if(Glue_claw)
    {
        Output_port0-=64;                                         //Output 40
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        Glue_claw=FALSE;
    }
}

void LD_claw_Off()
{
    if(LD_claw)
    {
        Output_port0-=128;                                        //Output 80
        _mnet_io_output(m_RingNo, 8, 0, Output_port0);
        LD_claw=FALSE;
    }
}

//---port 1---

void LD_neg_pressure_Off()
{
    if(LD_neg_pressure)
    {
        Output_port1-=1;                                         //Output 01
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        LD_neg_pressure=FALSE;
    }
}

void Unknow_neg_pressure_Off()
{
    if(Unknow_neg_pressure)
    {
        Output_port1-=4;                                         //Output 04
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        Unknow_neg_pressure=FALSE;
    }
}

void Lens_neg_pressure_Off()
{
    if(Lens_neg_pressure)
    {
        Output_port1-=16;                                         //Output 10
        _mnet_io_output(m_RingNo, 8, 1, Output_port1);
        Lens_neg_pressure=FALSE;
    }
}

//---port 2---

void Glue_pressure_Off()
{
    if(Glue_pressure)
    {
        Output_port2-=8;                                         //Output 08
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Glue_pressure=FALSE;
    }
}

void Glue_machine_Off()
{
    if(Glue_machine)
    {
        Output_port2-=16;                                         //Output 10
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Glue_machine=FALSE;
    }
}

void Lens_claw_Off()
{
    if(Lens_claw)
    {
        Output_port2-=32;                                         //Output 20
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        Lens_claw=FALSE;
    }
}

void block_Off()
{
    if(block)
    {
        Output_port2-=128;                                         //Output 80
        _mnet_io_output(m_RingNo, 8, 2, Output_port2);
        block=FALSE;
    }
}

//---port 3---

void UV_on_Off()
{
    if(UV_on)
    {
        Output_port3-=1;                                         //Output 01
        _mnet_io_output(m_RingNo, 8, 3, Output_port3);
        UV_on=FALSE;
    }
}

void UV_off_Off()
{
    if(UV_off)
    {
        Output_port3-=2;                                         //Output 02
        _mnet_io_output(m_RingNo, 8, 3, Output_port3);
        UV_off=FALSE;
    }
}

/*
void Output_Write(UCHAR portnum,UCHAR ckecknum,BOOL status)
{
    UCHAR check;

    if(portnum > 3 || ckecknum > 7)
    {
        QMessageBox::warning(NULL,"Waring","Port or Check number error");
        return False;
    }

    switch(portnum)
    {
        case 0 :
        {
            Input_port0 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port0 >> ckecknum;
            if(!check%2)
                return 1;
            return False;
        }
        case 1 :
        {
            Input_port1 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port1 >> ckecknum;
            if(!check%2)
                return 1;
            return False;
        }
        case 2 :
        {
            Input_port2 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port2 >> ckecknum;
            if(!check%2)
                return 1;
            return False;
        }
        case 3 :
        {
            Input_port3 = (UCHAR)_mnet_io_input(m_RingNo, 16 , portnum);
            check = Input_port3 >> ckecknum;
            if(!check%2)
                return 1;
            return False;
        }

    }

    return False;


}

void Output_Write1()
{
    QString Info;
    QString Writemessage;
    int hex;
    CHAR   value;

    if (m_usCardNum>0)
    {
        hex=Writemessage.toInt(nullptr,16);
        value=(char)hex;
        //value=value+0x04;
        _mnet_io_output(m_RingNo, m_DeviceIP, m_PortNo, value);
    }
    else if (m_usCardNum==0)
    {
        QMessageBox::warning(NULL,"Waring","No AMONet device has found.");
    }
}

void Input_Read()
{
    QString xx;
    UCHAR   value;
    if (m_usCardNum>0)
    {
        value = (UCHAR)_mnet_io_input(m_RingNo, m_DeviceIP, m_PortNo);
        xx=QString("%02X").arg(value);
        ui->Edit_Re->setText(xx);
        //UpdateData(TRUE);
        //xx.Format("%02X", value);
        //SetDlgItemText(IDC_EDIT_RX, xx);
        //UpdateData(FALSE);                    //MFC raw code
    }
}
*/
