#include "motor_initialization.h"


UINT m_RingNo=0;

extern INT	X_shift_pos=0;
extern INT	Y_shift_pos=0;
extern INT	Z_shift_pos=0;
extern INT	X_tilt_pos=0;
extern INT	Y_tilt_pos=0;
extern INT	Rotion_pos=0;
extern INT	X_gule_pos=0;
extern INT	Y_gule_pos=0;

I16 Amotnet_init()
{
    SHORT     CardNum;

    // You also can use _1202_open if you are using PCI-1202
    // _1202_open(&CardNo);

    CardNum = _mnet_initial();

    if (CardNum == 0)
    {
        QMessageBox::warning(NULL,"Waring","No AMONet device has found.");
        return 1;
    }

    return 0;
}

I16 ring_init()
{
    short nRet;

    nRet = _mnet_set_ring_config(m_RingNo, 3);                  //設置1202網路ring孔來源與Baud Rate
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_reset_ring(m_RingNo);                          //軟體內重啟ring孔與初始化
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_start_ring(m_RingNo);                          //ring孔啟用
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_set_ring_quality_param(m_RingNo, 50, 100);
    if(!ErrorHandler(nRet))                                     //設置連續錯誤次數
         return 1;

    nRet = _mnet_enable_soft_watchdog(m_RingNo, NULL);
    if(!ErrorHandler(nRet))                                     //檢測邏輯流程執行序是否有問題
         return 1;

    nRet = _mnet_m4_initial(m_RingNo, 2);
    if(!ErrorHandler(nRet))                //初始化軸卡
         return 1;

    nRet = _mnet_m4_initial(m_RingNo, 4);
    if(!ErrorHandler(nRet))                //初始化軸卡
         return 1;

    return 0;
}

I16 Xshift_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 2;
    int     AxisNum = 0;



    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Yshift_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 2;
    int     AxisNum = 1;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Zshift_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 4;
    int     AxisNum = 0;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 1, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Xtilt_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 2;
    int     AxisNum = 3;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1, 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Ytilt_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 2;
    int     AxisNum = 2;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Rotate_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 4;
    int     AxisNum = 1;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 1, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Xglue_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 4;
    int     AxisNum = 2;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 Yglue_init()
{
    SHORT   nRet;
    UINT    m_DeviceIP = 4;
    int     AxisNum = 3;

    //default setting

    nRet = _mnet_m4_set_pls_iptmode(m_RingNo, m_DeviceIP, AxisNum, 1, 0);
    if(!ErrorHandler(nRet))                //設定編碼器輸入脈衝(*,*,*,1 = 2x A/B ,0 = 非反向脈衝)
         return 1;

    nRet = _mnet_m4_set_pls_outmode(m_RingNo, m_DeviceIP, AxisNum,7);
    if(!ErrorHandler(nRet))                //設定編碼器輸出脈衝(*,*,*,7 = CW/CCW)
         return 1;

    nRet = _mnet_m4_set_feedback_src(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //設定位置輸入計數訊號(*,*,*,0 = External Feedback)
         return 1;

    nRet = _mnet_m4_set_erc(m_RingNo, m_DeviceIP, AxisNum, 1, 6,1);
    if(!ErrorHandler(nRet))                //設置ERC邏輯與時序(*,*,*,1 = Low Active ,6 = 104ms ,1(無說明))
         return 1;

    nRet = _mnet_m4_reset_position(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設位置計數器
         return 1;

    nRet = _mnet_m4_reset_command(m_RingNo, m_DeviceIP, AxisNum);
    if(!ErrorHandler(nRet))                //重設命令計數器
         return 1;

    nRet = _mnet_m4_set_sd(m_RingNo, m_DeviceIP, AxisNum, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //(*,*,*,0 = 關閉SD訊號,1 =Low active,0 = 關閉SD閂控制,0 = 純減速(1=減速並停止))
         return 1;

    nRet = _mnet_m4_set_alm( m_RingNo, m_DeviceIP, AxisNum, 1 , 0 );
    if(!ErrorHandler(nRet))                //(*,*,*,0=High Active 1=Low Active,0=收到緊急訊號後立即停止)
         return 1;

    nRet = _mnet_m4_set_ltc_logic(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))                //邏輯閂觸發設定(*,*,*,0=High Active 1=Low Active)
         return 1;

    nRet = _mnet_m4_set_tmove_speed(m_RingNo, m_DeviceIP, AxisNum, 3000, 15000, 0.3, 0.3);
    if(!ErrorHandler(nRet))                //設置梯形速度(*,*,*,初速(PPS),最大速度(PPS),加速時間(s),減速時間(s))
         return 1;

    nRet = _mnet_m4_set_home_config( m_RingNo, m_DeviceIP, AxisNum, 6, 0, 1, 0, 0);
    if(!ErrorHandler(nRet))                //Home參數設置(*,*,*,home_mode,org_logic,ez_logic,ez_count,erc_out)
         return 1;

    return 0;
}

I16 motor_r_move(UINT m_DeviceIP, UINT AxisNum, FLOAT StrVel, FLOAT MaxVel, FLOAT Tacc, FLOAT Tdec,int distance)
{
    SHORT   nRet;
    U16* asd = new U16;
    int test=1;

    nRet = _mnet_m4_set_svon(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_m4_set_tmove_speed( m_RingNo, m_DeviceIP, AxisNum, StrVel, MaxVel, Tacc, Tdec);
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_m4_start_r_move(m_RingNo, m_DeviceIP, AxisNum, distance);
    if(!ErrorHandler(nRet))
        return 1;

    while(test)
    {
        _mnet_m4_motion_done(m_RingNo, m_DeviceIP, AxisNum, *asd);
        test=*asd;
    }
    //QMessageBox::information(NULL,"Waring",QString("move-%01").arg(test));

    return 0;
}

I16 motor_home(UINT m_DeviceIP, UINT AxisNum, FLOAT StrVel, FLOAT MaxVel, FLOAT Tacc, FLOAT Tdec, CHAR way)
{
    SHORT   nRet;
    U16* asd = new U16;
    int test=1;

    nRet = _mnet_m4_set_svon(m_RingNo, m_DeviceIP, AxisNum, 1);
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_m4_set_tmove_speed( m_RingNo, m_DeviceIP, AxisNum, StrVel, MaxVel, Tacc, Tdec);
    if(!ErrorHandler(nRet))
        return 1;

    nRet = _mnet_m4_start_home_move( m_RingNo, m_DeviceIP, AxisNum, way);
    if(!ErrorHandler(nRet))
        return 1;


    while(test)
    {
        _mnet_m4_motion_done(m_RingNo, m_DeviceIP, AxisNum, *asd);
        test=*asd;
    }
    //QMessageBox::information(NULL,"Waring",QString("home-%01").arg(test));


    return 0;
}
