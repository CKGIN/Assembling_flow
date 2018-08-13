#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(Amotnet_init())  return;

    Sleep(500);

    if(ring_init())     return;

    Sleep(500);

    if(Xshift_init())
    {
        QMessageBox::warning(this,"Waring","Xshift_init");
        return;
    }

    if(Yshift_init())
    {
        QMessageBox::warning(this,"Waring","Yshift_init");
        return;
    }

    if(Zshift_init())
    {
        QMessageBox::warning(this,"Waring","Zshift_init");
        return;
    }

    if(Xtilt_init())
    {
        QMessageBox::warning(this,"Waring","Xtilt_init");
        return;
    }

    if(Ytilt_init())
    {
        QMessageBox::warning(this,"Waring","Ytilt_init");
        return;
    }

    if(Rotate_init())
    {
        QMessageBox::warning(this,"Waring","Rotate_init");
        return;
    }

    if(Xglue_init())
    {
        QMessageBox::warning(this,"Waring","Xglue_init");
        return;
    }

    if(Yglue_init())
    {
        QMessageBox::warning(this,"Waring","Yglue_init");
        return;
    }

    init_Read();

    if(Inputcheck(0,3))
    {
        QMessageBox::warning(this,"Waring","空壓確認");
        return;
    }

    QMessageBox::information(this,"Waring","上夾爪 Open");

    Lens_claw_On();



}

void MainWindow::on_pushButton_2_clicked()
{
    //short nRet;

    if(motor_home(4,0,10000,50000,0.25,0.25,0)) return;
    //Zshift Home

    if(motor_home(4,3,10000,50000,0.25,0.25,0)) return;
    //Ygule Home

    if(motor_r_move(4,0,10000,50000,0.25,0.25,30000)) return;
    //Zshift move 30000

    //---X Glue Home---
    if(motor_home(4,2,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(4,2,10000,50000,0.25,0.25,10000)) return;
    if(motor_home(4,2,1000,8000,0.25,0.25,0)) return;
    //-----------------

    //---Y Shift Home---
    if(motor_home(2,1,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(2,1,10000,50000,0.25,0.25,5000)) return;
    if(motor_home(2,1,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(2,1,10000,50000,0.25,0.25,65700)) return;
    //-----------------

    //---X Shift Home---
    if(motor_home(2,0,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(2,0,10000,50000,0.25,0.25,5000)) return;
    if(motor_home(2,0,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(2,0,10000,50000,0.25,0.25,103700)) return;
    //-----------------

    //---X tilt Home---
    if(motor_home(2,3,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(2,3,10000,50000,0.25,0.25,3000)) return;
    if(motor_home(2,3,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(2,3,10000,50000,0.25,0.25,48000)) return;
    //-----------------

    //---Y tilt Home---
    if(motor_home(2,2,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(2,2,10000,50000,0.25,0.25,4000)) return;
    if(motor_home(2,2,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(2,2,10000,50000,0.25,0.25,54300)) return;
    //-----------------

    //---Rotate Home---
    if(motor_home(4,1,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(4,1,1000,8000,0.25,0.25,500)) return;
    if(motor_home(4,1,1000,8000,0.25,0.25,0)) return;
    if(motor_r_move(4,1,1000,4000,0.25,0.25,5300)) return;
    //-----------------

    //---Z shift Home---
    if(motor_home(4,0,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(4,0,10000,50000,0.25,0.25,4000)) return;
    if(motor_home(4,0,1000,8000,0.25,0.25,0)) return;
    //-----------------

    //---Y Glue Home---
    if(motor_home(4,3,10000,50000,0.25,0.25,0)) return;
    if(motor_r_move(4,3,10000,50000,0.25,0.25,10000)) return;
    if(motor_home(4,3,1000,8000,0.25,0.25,0)) return;
    //-----------------

    //QMessageBox::information(this,"Waring","1");
    /*
    nRet = _mnet_m4_set_tmove_speed( m_RingNo, 4, 0, 10000, 50000, 0.25, 0.25);
    if(!ErrorHandler(nRet))
        return;

    nRet = _mnet_m4_start_home_move( m_RingNo, 4, 0, 0);
    if(!ErrorHandler(nRet))
        return;

    nRet = _mnet_m4_set_tmove_speed( m_RingNo, 4, 3, 10000, 50000, 0.25, 0.25);
    if(!ErrorHandler(nRet))
        return;

    nRet = _mnet_m4_set_svon(m_RingNo, 4, 3, 1);
    if(!ErrorHandler(nRet))
        return;

    nRet = _mnet_m4_start_home_move( m_RingNo, 4, 3, 0);
    if(!ErrorHandler(nRet))
        return;

    nRet = _mnet_m4_start_r_move(m_RingNo, 4, 0, 30000);
    if(!ErrorHandler(nRet))
         return;
    */
    Sleep(100);
}

/*
void MainWindow::timer_use()    //每隔一段時間回傳訊息
{
    //#define IDC_EDIT_COMMAND 1014

    LONG   command;
    LONG   position;
    QString  sztext;

    _mnet_m4_get_command(m_RingNo, m_DeviceIP, AxisNum, command);   //命令訊息回傳
    sztext = QString("%1").arg(command);
    ui->Edit_Command->setText(sztext);

    //sztext.Format("%d", command);
    //SetDlgItemText(IDC_EDIT_COMMAND, sztext);                     //MFC raw code

    _mnet_m4_get_position(m_RingNo, m_DeviceIP, AxisNum, position); //位置回傳
    sztext = QString("%1").arg(position);
    ui->Edit_Position->setText(sztext);

    //sztext.Format("%d", position);
    //SetDlgItemText(IDC_EDIT_POSITION, sztext);                    //MFC raw code

    //CDialog::OnTimer(nIDEvent);
}
*/
/*
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Loading ....");
    msgBox.setText("Reading Files, please wait ...");
    msgBox.setModal( false );
    msgBox.setWindowModality(Qt::NonModal);
    msgBox.setVisible(true);
    msgBox.exec();
    QCoreApplication::processEvents();
*/
