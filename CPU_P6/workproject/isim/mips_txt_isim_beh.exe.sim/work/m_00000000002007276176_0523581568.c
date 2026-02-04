/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/ISE/homework/CPU_P6_final/vtest/EXT26.v";
static unsigned int ng1[] = {0U, 0U};



static void Cont_27_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t5;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    t1 = (t0 + 2528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 1048U);
    t5 = *((char **)t2);
    xsi_vlogtype_concat(t4, 26, 26, 1U, t5, 26);
    t2 = (t0 + 1208U);
    t8 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (t10 >> 28);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 28);
    *((unsigned int *)t2) = t13;
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 15U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 15U);
    xsi_vlogtype_concat(t6, 4, 4, 1U, t7, 4);
    t16 = ((char*)((ng1)));
    xsi_vlogtype_concat(t3, 32, 32, 3U, t16, 2, t6, 4, t4, 26);
    t17 = (t0 + 2928);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t3, 8);
    xsi_driver_vfirst_trans(t17, 0, 31);
    t22 = (t0 + 2848);
    *((int *)t22) = 1;

LAB1:    return;
}


extern void work_m_00000000002007276176_0523581568_init()
{
	static char *pe[] = {(void *)Cont_27_0};
	xsi_register_didat("work_m_00000000002007276176_0523581568", "isim/mips_txt_isim_beh.exe.sim/work/m_00000000002007276176_0523581568.didat");
	xsi_register_executes(pe);
}
