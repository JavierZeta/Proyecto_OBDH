/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2024
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

//TODO 10 Complete FT_UAH_PHOTSAT_SERV_129_0010

//TODO 11 Complete FT_UAH_PHOTSAT_SERV_129_FDIR_0020


//#define FT_UAH_PHOTSAT_SERV_129_0010
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020


#ifdef FT_UAH_PHOTSAT_SERV_129_0010

EmuGSS_TCProgram3_5 prog_FT_0010_step0(OBT_AFTER_POWER_ON+1,
        "FT_UAH_PHOTSAT_SERV_129_0010_Step0, Enable SID 20 Report",20);

EmuGSS_TCProgram129_1 prog_FT_0010_step1(OBT_AFTER_POWER_ON+10,"FT_ASW_SERV_129_0010_Step0, Set theta_pitch theta_yaw and "
"number of images tet",1200,1800,5);




#endif

#ifdef FT_UAH_PHOTSAT_SERV_129_FDIR_0020

EmuGSS_TCProgram3_5 prog_FT_0010_step0(OBT_AFTER_POWER_ON+1,
        "FT_UAH_PHOTSAT_SERV_129_0010_Step0, Enable SID 20 Report",20);

//ThetaPitch
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_0020_step1(OBT_AFTER_POWER_ON+2,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step1, Define PMONID 1 to monitor PID 13",
    1, 13, 1, 1, 0xFF, 0x00, 0x4003);
//ThetaYaw
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_0020_step2(OBT_AFTER_POWER_ON+4,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step2, Define PMONID 2 to monitor PID 14",
    2, 14, 1, 1, 0xFF, 0x00, 0x4003);


EmuGSS_TCProgram12_1 prog_FT_0020_step3(OBT_AFTER_POWER_ON+6,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step3a, Enable PMONID 1", 1);

EmuGSS_TCProgram12_1 prog_FT_0020_step4(OBT_AFTER_POWER_ON+8,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step3b, Enable PMONID 2", 2);

//reset
EmuGSS_TCProgram19_1_Action_129_3 prog_FT_0020_step5(OBT_AFTER_POWER_ON+10,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step4, 0x4003 Action set to Reset", 0x4003);

EmuGSS_TCProgram19_4 prog_FT_0020_step6(OBT_AFTER_POWER_ON+12,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step5, "
    "Enable Event-Action Reset for 0x4003", 0x4003);


EmuGSS_TCProgram129_2 prog_FT_0020_step7(OBT_AFTER_POWER_ON+14,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020_Step6, Change PID Control Values in "
    "order to force an error", 0.5, 0.5, 0.5);

EmuGSS_TCProgram129_1 prog_FT_0010_step8(OBT_AFTER_POWER_ON+16,
    "FT_UAH_PHOTSAT_SERV_129_0010_Step0, Send Pitch & Yaw desired attitude and "
    "number of images", 1000, 800, 6);






#endif




