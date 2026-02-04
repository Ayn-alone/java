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
static const char *ng0 = "D:/ISE/homework/CPU_P6_final/vtest/mips.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {8U, 0U};
static int ng7[] = {2, 0};
static unsigned int ng8[] = {3U, 0U};
static unsigned int ng9[] = {12U, 0U};



static void Cont_58_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 20608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 3768U);
    t3 = *((char **)t2);
    t2 = (t0 + 22856);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t8 = (t0 + 22664);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_59_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 20856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 7608U);
    t3 = *((char **)t2);
    t2 = (t0 + 22920);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t8 = (t0 + 22680);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_60_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t22[8];
    char t36[8];
    char t52[8];
    char t60[8];
    char t103[8];
    char t104[8];
    char t119[8];
    char t120[8];
    char t123[8];
    char t139[8];
    char t153[8];
    char t169[8];
    char t177[8];
    char t220[8];
    char t222[8];
    char t237[8];
    char t238[8];
    char t241[8];
    char t257[8];
    char t271[8];
    char t287[8];
    char t295[8];
    char t338[8];
    char t340[8];
    char t355[8];
    char t356[8];
    char t359[8];
    char t375[8];
    char t389[8];
    char t405[8];
    char t413[8];
    char t456[8];
    char t458[8];
    char t472[8];
    char t473[8];
    char t476[8];
    char t492[8];
    char t506[8];
    char t522[8];
    char t530[8];
    char t573[8];
    char t574[8];
    char t589[8];
    char t590[8];
    char t593[8];
    char t609[8];
    char t623[8];
    char t639[8];
    char t647[8];
    char t690[8];
    char t692[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t105;
    char *t106;
    char *t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t121;
    char *t122;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    char *t138;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    char *t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    char *t154;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    char *t168;
    char *t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    char *t176;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    char *t181;
    char *t182;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    char *t191;
    char *t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    int t201;
    int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    char *t215;
    char *t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    char *t221;
    char *t223;
    char *t224;
    char *t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    char *t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t239;
    char *t240;
    char *t242;
    char *t243;
    unsigned int t244;
    unsigned int t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    char *t256;
    char *t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    char *t264;
    char *t265;
    unsigned int t266;
    unsigned int t267;
    unsigned int t268;
    char *t269;
    char *t270;
    char *t272;
    char *t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    unsigned int t278;
    unsigned int t279;
    unsigned int t280;
    unsigned int t281;
    unsigned int t282;
    unsigned int t283;
    unsigned int t284;
    unsigned int t285;
    char *t286;
    char *t288;
    unsigned int t289;
    unsigned int t290;
    unsigned int t291;
    unsigned int t292;
    unsigned int t293;
    char *t294;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    char *t299;
    char *t300;
    char *t301;
    unsigned int t302;
    unsigned int t303;
    unsigned int t304;
    unsigned int t305;
    unsigned int t306;
    unsigned int t307;
    unsigned int t308;
    char *t309;
    char *t310;
    unsigned int t311;
    unsigned int t312;
    unsigned int t313;
    unsigned int t314;
    unsigned int t315;
    unsigned int t316;
    unsigned int t317;
    unsigned int t318;
    int t319;
    int t320;
    unsigned int t321;
    unsigned int t322;
    unsigned int t323;
    unsigned int t324;
    unsigned int t325;
    unsigned int t326;
    char *t327;
    unsigned int t328;
    unsigned int t329;
    unsigned int t330;
    unsigned int t331;
    unsigned int t332;
    char *t333;
    char *t334;
    unsigned int t335;
    unsigned int t336;
    unsigned int t337;
    char *t339;
    char *t341;
    char *t342;
    char *t343;
    unsigned int t344;
    unsigned int t345;
    unsigned int t346;
    unsigned int t347;
    unsigned int t348;
    unsigned int t349;
    char *t350;
    unsigned int t351;
    unsigned int t352;
    unsigned int t353;
    unsigned int t354;
    char *t357;
    char *t358;
    char *t360;
    char *t361;
    unsigned int t362;
    unsigned int t363;
    unsigned int t364;
    unsigned int t365;
    unsigned int t366;
    unsigned int t367;
    unsigned int t368;
    unsigned int t369;
    unsigned int t370;
    unsigned int t371;
    unsigned int t372;
    unsigned int t373;
    char *t374;
    char *t376;
    unsigned int t377;
    unsigned int t378;
    unsigned int t379;
    unsigned int t380;
    unsigned int t381;
    char *t382;
    char *t383;
    unsigned int t384;
    unsigned int t385;
    unsigned int t386;
    char *t387;
    char *t388;
    char *t390;
    char *t391;
    unsigned int t392;
    unsigned int t393;
    unsigned int t394;
    unsigned int t395;
    unsigned int t396;
    unsigned int t397;
    unsigned int t398;
    unsigned int t399;
    unsigned int t400;
    unsigned int t401;
    unsigned int t402;
    unsigned int t403;
    char *t404;
    char *t406;
    unsigned int t407;
    unsigned int t408;
    unsigned int t409;
    unsigned int t410;
    unsigned int t411;
    char *t412;
    unsigned int t414;
    unsigned int t415;
    unsigned int t416;
    char *t417;
    char *t418;
    char *t419;
    unsigned int t420;
    unsigned int t421;
    unsigned int t422;
    unsigned int t423;
    unsigned int t424;
    unsigned int t425;
    unsigned int t426;
    char *t427;
    char *t428;
    unsigned int t429;
    unsigned int t430;
    unsigned int t431;
    unsigned int t432;
    unsigned int t433;
    unsigned int t434;
    unsigned int t435;
    unsigned int t436;
    int t437;
    int t438;
    unsigned int t439;
    unsigned int t440;
    unsigned int t441;
    unsigned int t442;
    unsigned int t443;
    unsigned int t444;
    char *t445;
    unsigned int t446;
    unsigned int t447;
    unsigned int t448;
    unsigned int t449;
    unsigned int t450;
    char *t451;
    char *t452;
    unsigned int t453;
    unsigned int t454;
    unsigned int t455;
    char *t457;
    char *t459;
    char *t460;
    char *t461;
    unsigned int t462;
    unsigned int t463;
    unsigned int t464;
    unsigned int t465;
    unsigned int t466;
    unsigned int t467;
    unsigned int t468;
    unsigned int t469;
    unsigned int t470;
    unsigned int t471;
    char *t474;
    char *t475;
    char *t477;
    char *t478;
    unsigned int t479;
    unsigned int t480;
    unsigned int t481;
    unsigned int t482;
    unsigned int t483;
    unsigned int t484;
    unsigned int t485;
    unsigned int t486;
    unsigned int t487;
    unsigned int t488;
    unsigned int t489;
    unsigned int t490;
    char *t491;
    char *t493;
    unsigned int t494;
    unsigned int t495;
    unsigned int t496;
    unsigned int t497;
    unsigned int t498;
    char *t499;
    char *t500;
    unsigned int t501;
    unsigned int t502;
    unsigned int t503;
    char *t504;
    char *t505;
    char *t507;
    char *t508;
    unsigned int t509;
    unsigned int t510;
    unsigned int t511;
    unsigned int t512;
    unsigned int t513;
    unsigned int t514;
    unsigned int t515;
    unsigned int t516;
    unsigned int t517;
    unsigned int t518;
    unsigned int t519;
    unsigned int t520;
    char *t521;
    char *t523;
    unsigned int t524;
    unsigned int t525;
    unsigned int t526;
    unsigned int t527;
    unsigned int t528;
    char *t529;
    unsigned int t531;
    unsigned int t532;
    unsigned int t533;
    char *t534;
    char *t535;
    char *t536;
    unsigned int t537;
    unsigned int t538;
    unsigned int t539;
    unsigned int t540;
    unsigned int t541;
    unsigned int t542;
    unsigned int t543;
    char *t544;
    char *t545;
    unsigned int t546;
    unsigned int t547;
    unsigned int t548;
    unsigned int t549;
    unsigned int t550;
    unsigned int t551;
    unsigned int t552;
    unsigned int t553;
    int t554;
    int t555;
    unsigned int t556;
    unsigned int t557;
    unsigned int t558;
    unsigned int t559;
    unsigned int t560;
    unsigned int t561;
    char *t562;
    unsigned int t563;
    unsigned int t564;
    unsigned int t565;
    unsigned int t566;
    unsigned int t567;
    char *t568;
    char *t569;
    unsigned int t570;
    unsigned int t571;
    unsigned int t572;
    char *t575;
    char *t576;
    char *t577;
    unsigned int t578;
    unsigned int t579;
    unsigned int t580;
    unsigned int t581;
    unsigned int t582;
    unsigned int t583;
    char *t584;
    unsigned int t585;
    unsigned int t586;
    unsigned int t587;
    unsigned int t588;
    char *t591;
    char *t592;
    char *t594;
    char *t595;
    unsigned int t596;
    unsigned int t597;
    unsigned int t598;
    unsigned int t599;
    unsigned int t600;
    unsigned int t601;
    unsigned int t602;
    unsigned int t603;
    unsigned int t604;
    unsigned int t605;
    unsigned int t606;
    unsigned int t607;
    char *t608;
    char *t610;
    unsigned int t611;
    unsigned int t612;
    unsigned int t613;
    unsigned int t614;
    unsigned int t615;
    char *t616;
    char *t617;
    unsigned int t618;
    unsigned int t619;
    unsigned int t620;
    char *t621;
    char *t622;
    char *t624;
    char *t625;
    unsigned int t626;
    unsigned int t627;
    unsigned int t628;
    unsigned int t629;
    unsigned int t630;
    unsigned int t631;
    unsigned int t632;
    unsigned int t633;
    unsigned int t634;
    unsigned int t635;
    unsigned int t636;
    unsigned int t637;
    char *t638;
    char *t640;
    unsigned int t641;
    unsigned int t642;
    unsigned int t643;
    unsigned int t644;
    unsigned int t645;
    char *t646;
    unsigned int t648;
    unsigned int t649;
    unsigned int t650;
    char *t651;
    char *t652;
    char *t653;
    unsigned int t654;
    unsigned int t655;
    unsigned int t656;
    unsigned int t657;
    unsigned int t658;
    unsigned int t659;
    unsigned int t660;
    char *t661;
    char *t662;
    unsigned int t663;
    unsigned int t664;
    unsigned int t665;
    unsigned int t666;
    unsigned int t667;
    unsigned int t668;
    unsigned int t669;
    unsigned int t670;
    int t671;
    int t672;
    unsigned int t673;
    unsigned int t674;
    unsigned int t675;
    unsigned int t676;
    unsigned int t677;
    unsigned int t678;
    char *t679;
    unsigned int t680;
    unsigned int t681;
    unsigned int t682;
    unsigned int t683;
    unsigned int t684;
    char *t685;
    char *t686;
    unsigned int t687;
    unsigned int t688;
    unsigned int t689;
    char *t691;
    char *t693;
    char *t694;
    char *t695;
    unsigned int t696;
    unsigned int t697;
    unsigned int t698;
    unsigned int t699;
    unsigned int t700;
    unsigned int t701;
    unsigned int t702;
    unsigned int t703;
    unsigned int t704;
    unsigned int t705;
    char *t706;
    char *t707;
    char *t708;
    char *t709;
    char *t710;
    char *t711;
    char *t712;

LAB0:    t1 = (t0 + 21104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 10648U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t2 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t23) != 0)
        goto LAB10;

LAB11:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB12;

LAB13:    memcpy(t60, t22, 8);

LAB14:    memset(t4, 0, 8);
    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 & 1U);
    if (t97 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t92) != 0)
        goto LAB28;

LAB29:    t99 = (t4 + 4);
    t100 = *((unsigned int *)t4);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB30;

LAB31:    t115 = *((unsigned int *)t4);
    t116 = (~(t115));
    t117 = *((unsigned int *)t99);
    t118 = (t116 || t117);
    if (t118 > 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t99) > 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t4) > 0)
        goto LAB36;

LAB37:    memcpy(t3, t119, 8);

LAB38:    t706 = (t0 + 22984);
    t708 = (t706 + 56U);
    t709 = *((char **)t708);
    t710 = (t709 + 56U);
    t711 = *((char **)t710);
    memcpy(t711, t3, 8);
    xsi_driver_vfirst_trans(t706, 0, 31);
    t712 = (t0 + 22696);
    *((int *)t712) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t22) = 1;
    goto LAB11;

LAB10:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB11;

LAB12:    t34 = (t0 + 2168U);
    t35 = *((char **)t34);
    t34 = ((char*)((ng2)));
    memset(t36, 0, 8);
    t37 = (t35 + 4);
    t38 = (t34 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t34);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB18;

LAB15:    if (t48 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t36) = 1;

LAB18:    memset(t52, 0, 8);
    t53 = (t36 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t53) != 0)
        goto LAB21;

LAB22:    t61 = *((unsigned int *)t22);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t22 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB14;

LAB17:    t51 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t52) = 1;
    goto LAB22;

LAB21:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB22;

LAB23:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t22 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t22);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB25;

LAB26:    *((unsigned int *)t4) = 1;
    goto LAB29;

LAB28:    t98 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t98) = 1;
    goto LAB29;

LAB30:    t105 = (t0 + 7448U);
    t106 = *((char **)t105);
    memset(t104, 0, 8);
    t105 = (t104 + 4);
    t107 = (t106 + 4);
    t108 = *((unsigned int *)t106);
    t109 = (t108 >> 0);
    *((unsigned int *)t104) = t109;
    t110 = *((unsigned int *)t107);
    t111 = (t110 >> 0);
    *((unsigned int *)t105) = t111;
    t112 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t112 & 255U);
    t113 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t113 & 255U);
    t114 = ((char*)((ng3)));
    xsi_vlogtype_concat(t103, 32, 32, 2U, t114, 24, t104, 8);
    goto LAB31;

LAB32:    t121 = (t0 + 10648U);
    t122 = *((char **)t121);
    t121 = ((char*)((ng1)));
    memset(t123, 0, 8);
    t124 = (t122 + 4);
    t125 = (t121 + 4);
    t126 = *((unsigned int *)t122);
    t127 = *((unsigned int *)t121);
    t128 = (t126 ^ t127);
    t129 = *((unsigned int *)t124);
    t130 = *((unsigned int *)t125);
    t131 = (t129 ^ t130);
    t132 = (t128 | t131);
    t133 = *((unsigned int *)t124);
    t134 = *((unsigned int *)t125);
    t135 = (t133 | t134);
    t136 = (~(t135));
    t137 = (t132 & t136);
    if (t137 != 0)
        goto LAB42;

LAB39:    if (t135 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t123) = 1;

LAB42:    memset(t139, 0, 8);
    t140 = (t123 + 4);
    t141 = *((unsigned int *)t140);
    t142 = (~(t141));
    t143 = *((unsigned int *)t123);
    t144 = (t143 & t142);
    t145 = (t144 & 1U);
    if (t145 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t140) != 0)
        goto LAB45;

LAB46:    t147 = (t139 + 4);
    t148 = *((unsigned int *)t139);
    t149 = *((unsigned int *)t147);
    t150 = (t148 || t149);
    if (t150 > 0)
        goto LAB47;

LAB48:    memcpy(t177, t139, 8);

LAB49:    memset(t120, 0, 8);
    t209 = (t177 + 4);
    t210 = *((unsigned int *)t209);
    t211 = (~(t210));
    t212 = *((unsigned int *)t177);
    t213 = (t212 & t211);
    t214 = (t213 & 1U);
    if (t214 != 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t209) != 0)
        goto LAB63;

LAB64:    t216 = (t120 + 4);
    t217 = *((unsigned int *)t120);
    t218 = *((unsigned int *)t216);
    t219 = (t217 || t218);
    if (t219 > 0)
        goto LAB65;

LAB66:    t233 = *((unsigned int *)t120);
    t234 = (~(t233));
    t235 = *((unsigned int *)t216);
    t236 = (t234 || t235);
    if (t236 > 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t216) > 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t120) > 0)
        goto LAB71;

LAB72:    memcpy(t119, t237, 8);

LAB73:    goto LAB33;

LAB34:    xsi_vlog_unsigned_bit_combine(t3, 32, t103, 32, t119, 32);
    goto LAB38;

LAB36:    memcpy(t3, t103, 8);
    goto LAB38;

LAB41:    t138 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t138) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t139) = 1;
    goto LAB46;

LAB45:    t146 = (t139 + 4);
    *((unsigned int *)t139) = 1;
    *((unsigned int *)t146) = 1;
    goto LAB46;

LAB47:    t151 = (t0 + 2168U);
    t152 = *((char **)t151);
    t151 = ((char*)((ng4)));
    memset(t153, 0, 8);
    t154 = (t152 + 4);
    t155 = (t151 + 4);
    t156 = *((unsigned int *)t152);
    t157 = *((unsigned int *)t151);
    t158 = (t156 ^ t157);
    t159 = *((unsigned int *)t154);
    t160 = *((unsigned int *)t155);
    t161 = (t159 ^ t160);
    t162 = (t158 | t161);
    t163 = *((unsigned int *)t154);
    t164 = *((unsigned int *)t155);
    t165 = (t163 | t164);
    t166 = (~(t165));
    t167 = (t162 & t166);
    if (t167 != 0)
        goto LAB53;

LAB50:    if (t165 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t153) = 1;

LAB53:    memset(t169, 0, 8);
    t170 = (t153 + 4);
    t171 = *((unsigned int *)t170);
    t172 = (~(t171));
    t173 = *((unsigned int *)t153);
    t174 = (t173 & t172);
    t175 = (t174 & 1U);
    if (t175 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t170) != 0)
        goto LAB56;

LAB57:    t178 = *((unsigned int *)t139);
    t179 = *((unsigned int *)t169);
    t180 = (t178 & t179);
    *((unsigned int *)t177) = t180;
    t181 = (t139 + 4);
    t182 = (t169 + 4);
    t183 = (t177 + 4);
    t184 = *((unsigned int *)t181);
    t185 = *((unsigned int *)t182);
    t186 = (t184 | t185);
    *((unsigned int *)t183) = t186;
    t187 = *((unsigned int *)t183);
    t188 = (t187 != 0);
    if (t188 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB49;

LAB52:    t168 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t168) = 1;
    goto LAB53;

LAB54:    *((unsigned int *)t169) = 1;
    goto LAB57;

LAB56:    t176 = (t169 + 4);
    *((unsigned int *)t169) = 1;
    *((unsigned int *)t176) = 1;
    goto LAB57;

LAB58:    t189 = *((unsigned int *)t177);
    t190 = *((unsigned int *)t183);
    *((unsigned int *)t177) = (t189 | t190);
    t191 = (t139 + 4);
    t192 = (t169 + 4);
    t193 = *((unsigned int *)t139);
    t194 = (~(t193));
    t195 = *((unsigned int *)t191);
    t196 = (~(t195));
    t197 = *((unsigned int *)t169);
    t198 = (~(t197));
    t199 = *((unsigned int *)t192);
    t200 = (~(t199));
    t201 = (t194 & t196);
    t202 = (t198 & t200);
    t203 = (~(t201));
    t204 = (~(t202));
    t205 = *((unsigned int *)t183);
    *((unsigned int *)t183) = (t205 & t203);
    t206 = *((unsigned int *)t183);
    *((unsigned int *)t183) = (t206 & t204);
    t207 = *((unsigned int *)t177);
    *((unsigned int *)t177) = (t207 & t203);
    t208 = *((unsigned int *)t177);
    *((unsigned int *)t177) = (t208 & t204);
    goto LAB60;

LAB61:    *((unsigned int *)t120) = 1;
    goto LAB64;

LAB63:    t215 = (t120 + 4);
    *((unsigned int *)t120) = 1;
    *((unsigned int *)t215) = 1;
    goto LAB64;

LAB65:    t221 = ((char*)((ng3)));
    t223 = (t0 + 7448U);
    t224 = *((char **)t223);
    memset(t222, 0, 8);
    t223 = (t222 + 4);
    t225 = (t224 + 4);
    t226 = *((unsigned int *)t224);
    t227 = (t226 >> 0);
    *((unsigned int *)t222) = t227;
    t228 = *((unsigned int *)t225);
    t229 = (t228 >> 0);
    *((unsigned int *)t223) = t229;
    t230 = *((unsigned int *)t222);
    *((unsigned int *)t222) = (t230 & 255U);
    t231 = *((unsigned int *)t223);
    *((unsigned int *)t223) = (t231 & 255U);
    t232 = ((char*)((ng3)));
    xsi_vlogtype_concat(t220, 32, 32, 3U, t232, 16, t222, 8, t221, 8);
    goto LAB66;

LAB67:    t239 = (t0 + 10648U);
    t240 = *((char **)t239);
    t239 = ((char*)((ng1)));
    memset(t241, 0, 8);
    t242 = (t240 + 4);
    t243 = (t239 + 4);
    t244 = *((unsigned int *)t240);
    t245 = *((unsigned int *)t239);
    t246 = (t244 ^ t245);
    t247 = *((unsigned int *)t242);
    t248 = *((unsigned int *)t243);
    t249 = (t247 ^ t248);
    t250 = (t246 | t249);
    t251 = *((unsigned int *)t242);
    t252 = *((unsigned int *)t243);
    t253 = (t251 | t252);
    t254 = (~(t253));
    t255 = (t250 & t254);
    if (t255 != 0)
        goto LAB77;

LAB74:    if (t253 != 0)
        goto LAB76;

LAB75:    *((unsigned int *)t241) = 1;

LAB77:    memset(t257, 0, 8);
    t258 = (t241 + 4);
    t259 = *((unsigned int *)t258);
    t260 = (~(t259));
    t261 = *((unsigned int *)t241);
    t262 = (t261 & t260);
    t263 = (t262 & 1U);
    if (t263 != 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t258) != 0)
        goto LAB80;

LAB81:    t265 = (t257 + 4);
    t266 = *((unsigned int *)t257);
    t267 = *((unsigned int *)t265);
    t268 = (t266 || t267);
    if (t268 > 0)
        goto LAB82;

LAB83:    memcpy(t295, t257, 8);

LAB84:    memset(t238, 0, 8);
    t327 = (t295 + 4);
    t328 = *((unsigned int *)t327);
    t329 = (~(t328));
    t330 = *((unsigned int *)t295);
    t331 = (t330 & t329);
    t332 = (t331 & 1U);
    if (t332 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t327) != 0)
        goto LAB98;

LAB99:    t334 = (t238 + 4);
    t335 = *((unsigned int *)t238);
    t336 = *((unsigned int *)t334);
    t337 = (t335 || t336);
    if (t337 > 0)
        goto LAB100;

LAB101:    t351 = *((unsigned int *)t238);
    t352 = (~(t351));
    t353 = *((unsigned int *)t334);
    t354 = (t352 || t353);
    if (t354 > 0)
        goto LAB102;

LAB103:    if (*((unsigned int *)t334) > 0)
        goto LAB104;

LAB105:    if (*((unsigned int *)t238) > 0)
        goto LAB106;

LAB107:    memcpy(t237, t355, 8);

LAB108:    goto LAB68;

LAB69:    xsi_vlog_unsigned_bit_combine(t119, 32, t220, 32, t237, 32);
    goto LAB73;

LAB71:    memcpy(t119, t220, 8);
    goto LAB73;

LAB76:    t256 = (t241 + 4);
    *((unsigned int *)t241) = 1;
    *((unsigned int *)t256) = 1;
    goto LAB77;

LAB78:    *((unsigned int *)t257) = 1;
    goto LAB81;

LAB80:    t264 = (t257 + 4);
    *((unsigned int *)t257) = 1;
    *((unsigned int *)t264) = 1;
    goto LAB81;

LAB82:    t269 = (t0 + 2168U);
    t270 = *((char **)t269);
    t269 = ((char*)((ng5)));
    memset(t271, 0, 8);
    t272 = (t270 + 4);
    t273 = (t269 + 4);
    t274 = *((unsigned int *)t270);
    t275 = *((unsigned int *)t269);
    t276 = (t274 ^ t275);
    t277 = *((unsigned int *)t272);
    t278 = *((unsigned int *)t273);
    t279 = (t277 ^ t278);
    t280 = (t276 | t279);
    t281 = *((unsigned int *)t272);
    t282 = *((unsigned int *)t273);
    t283 = (t281 | t282);
    t284 = (~(t283));
    t285 = (t280 & t284);
    if (t285 != 0)
        goto LAB88;

LAB85:    if (t283 != 0)
        goto LAB87;

LAB86:    *((unsigned int *)t271) = 1;

LAB88:    memset(t287, 0, 8);
    t288 = (t271 + 4);
    t289 = *((unsigned int *)t288);
    t290 = (~(t289));
    t291 = *((unsigned int *)t271);
    t292 = (t291 & t290);
    t293 = (t292 & 1U);
    if (t293 != 0)
        goto LAB89;

LAB90:    if (*((unsigned int *)t288) != 0)
        goto LAB91;

LAB92:    t296 = *((unsigned int *)t257);
    t297 = *((unsigned int *)t287);
    t298 = (t296 & t297);
    *((unsigned int *)t295) = t298;
    t299 = (t257 + 4);
    t300 = (t287 + 4);
    t301 = (t295 + 4);
    t302 = *((unsigned int *)t299);
    t303 = *((unsigned int *)t300);
    t304 = (t302 | t303);
    *((unsigned int *)t301) = t304;
    t305 = *((unsigned int *)t301);
    t306 = (t305 != 0);
    if (t306 == 1)
        goto LAB93;

LAB94:
LAB95:    goto LAB84;

LAB87:    t286 = (t271 + 4);
    *((unsigned int *)t271) = 1;
    *((unsigned int *)t286) = 1;
    goto LAB88;

LAB89:    *((unsigned int *)t287) = 1;
    goto LAB92;

LAB91:    t294 = (t287 + 4);
    *((unsigned int *)t287) = 1;
    *((unsigned int *)t294) = 1;
    goto LAB92;

LAB93:    t307 = *((unsigned int *)t295);
    t308 = *((unsigned int *)t301);
    *((unsigned int *)t295) = (t307 | t308);
    t309 = (t257 + 4);
    t310 = (t287 + 4);
    t311 = *((unsigned int *)t257);
    t312 = (~(t311));
    t313 = *((unsigned int *)t309);
    t314 = (~(t313));
    t315 = *((unsigned int *)t287);
    t316 = (~(t315));
    t317 = *((unsigned int *)t310);
    t318 = (~(t317));
    t319 = (t312 & t314);
    t320 = (t316 & t318);
    t321 = (~(t319));
    t322 = (~(t320));
    t323 = *((unsigned int *)t301);
    *((unsigned int *)t301) = (t323 & t321);
    t324 = *((unsigned int *)t301);
    *((unsigned int *)t301) = (t324 & t322);
    t325 = *((unsigned int *)t295);
    *((unsigned int *)t295) = (t325 & t321);
    t326 = *((unsigned int *)t295);
    *((unsigned int *)t295) = (t326 & t322);
    goto LAB95;

LAB96:    *((unsigned int *)t238) = 1;
    goto LAB99;

LAB98:    t333 = (t238 + 4);
    *((unsigned int *)t238) = 1;
    *((unsigned int *)t333) = 1;
    goto LAB99;

LAB100:    t339 = ((char*)((ng3)));
    t341 = (t0 + 7448U);
    t342 = *((char **)t341);
    memset(t340, 0, 8);
    t341 = (t340 + 4);
    t343 = (t342 + 4);
    t344 = *((unsigned int *)t342);
    t345 = (t344 >> 0);
    *((unsigned int *)t340) = t345;
    t346 = *((unsigned int *)t343);
    t347 = (t346 >> 0);
    *((unsigned int *)t341) = t347;
    t348 = *((unsigned int *)t340);
    *((unsigned int *)t340) = (t348 & 255U);
    t349 = *((unsigned int *)t341);
    *((unsigned int *)t341) = (t349 & 255U);
    t350 = ((char*)((ng3)));
    xsi_vlogtype_concat(t338, 32, 32, 3U, t350, 8, t340, 8, t339, 16);
    goto LAB101;

LAB102:    t357 = (t0 + 10648U);
    t358 = *((char **)t357);
    t357 = ((char*)((ng1)));
    memset(t359, 0, 8);
    t360 = (t358 + 4);
    t361 = (t357 + 4);
    t362 = *((unsigned int *)t358);
    t363 = *((unsigned int *)t357);
    t364 = (t362 ^ t363);
    t365 = *((unsigned int *)t360);
    t366 = *((unsigned int *)t361);
    t367 = (t365 ^ t366);
    t368 = (t364 | t367);
    t369 = *((unsigned int *)t360);
    t370 = *((unsigned int *)t361);
    t371 = (t369 | t370);
    t372 = (~(t371));
    t373 = (t368 & t372);
    if (t373 != 0)
        goto LAB112;

LAB109:    if (t371 != 0)
        goto LAB111;

LAB110:    *((unsigned int *)t359) = 1;

LAB112:    memset(t375, 0, 8);
    t376 = (t359 + 4);
    t377 = *((unsigned int *)t376);
    t378 = (~(t377));
    t379 = *((unsigned int *)t359);
    t380 = (t379 & t378);
    t381 = (t380 & 1U);
    if (t381 != 0)
        goto LAB113;

LAB114:    if (*((unsigned int *)t376) != 0)
        goto LAB115;

LAB116:    t383 = (t375 + 4);
    t384 = *((unsigned int *)t375);
    t385 = *((unsigned int *)t383);
    t386 = (t384 || t385);
    if (t386 > 0)
        goto LAB117;

LAB118:    memcpy(t413, t375, 8);

LAB119:    memset(t356, 0, 8);
    t445 = (t413 + 4);
    t446 = *((unsigned int *)t445);
    t447 = (~(t446));
    t448 = *((unsigned int *)t413);
    t449 = (t448 & t447);
    t450 = (t449 & 1U);
    if (t450 != 0)
        goto LAB131;

LAB132:    if (*((unsigned int *)t445) != 0)
        goto LAB133;

LAB134:    t452 = (t356 + 4);
    t453 = *((unsigned int *)t356);
    t454 = *((unsigned int *)t452);
    t455 = (t453 || t454);
    if (t455 > 0)
        goto LAB135;

LAB136:    t468 = *((unsigned int *)t356);
    t469 = (~(t468));
    t470 = *((unsigned int *)t452);
    t471 = (t469 || t470);
    if (t471 > 0)
        goto LAB137;

LAB138:    if (*((unsigned int *)t452) > 0)
        goto LAB139;

LAB140:    if (*((unsigned int *)t356) > 0)
        goto LAB141;

LAB142:    memcpy(t355, t472, 8);

LAB143:    goto LAB103;

LAB104:    xsi_vlog_unsigned_bit_combine(t237, 32, t338, 32, t355, 32);
    goto LAB108;

LAB106:    memcpy(t237, t338, 8);
    goto LAB108;

LAB111:    t374 = (t359 + 4);
    *((unsigned int *)t359) = 1;
    *((unsigned int *)t374) = 1;
    goto LAB112;

LAB113:    *((unsigned int *)t375) = 1;
    goto LAB116;

LAB115:    t382 = (t375 + 4);
    *((unsigned int *)t375) = 1;
    *((unsigned int *)t382) = 1;
    goto LAB116;

LAB117:    t387 = (t0 + 2168U);
    t388 = *((char **)t387);
    t387 = ((char*)((ng6)));
    memset(t389, 0, 8);
    t390 = (t388 + 4);
    t391 = (t387 + 4);
    t392 = *((unsigned int *)t388);
    t393 = *((unsigned int *)t387);
    t394 = (t392 ^ t393);
    t395 = *((unsigned int *)t390);
    t396 = *((unsigned int *)t391);
    t397 = (t395 ^ t396);
    t398 = (t394 | t397);
    t399 = *((unsigned int *)t390);
    t400 = *((unsigned int *)t391);
    t401 = (t399 | t400);
    t402 = (~(t401));
    t403 = (t398 & t402);
    if (t403 != 0)
        goto LAB123;

LAB120:    if (t401 != 0)
        goto LAB122;

LAB121:    *((unsigned int *)t389) = 1;

LAB123:    memset(t405, 0, 8);
    t406 = (t389 + 4);
    t407 = *((unsigned int *)t406);
    t408 = (~(t407));
    t409 = *((unsigned int *)t389);
    t410 = (t409 & t408);
    t411 = (t410 & 1U);
    if (t411 != 0)
        goto LAB124;

LAB125:    if (*((unsigned int *)t406) != 0)
        goto LAB126;

LAB127:    t414 = *((unsigned int *)t375);
    t415 = *((unsigned int *)t405);
    t416 = (t414 & t415);
    *((unsigned int *)t413) = t416;
    t417 = (t375 + 4);
    t418 = (t405 + 4);
    t419 = (t413 + 4);
    t420 = *((unsigned int *)t417);
    t421 = *((unsigned int *)t418);
    t422 = (t420 | t421);
    *((unsigned int *)t419) = t422;
    t423 = *((unsigned int *)t419);
    t424 = (t423 != 0);
    if (t424 == 1)
        goto LAB128;

LAB129:
LAB130:    goto LAB119;

LAB122:    t404 = (t389 + 4);
    *((unsigned int *)t389) = 1;
    *((unsigned int *)t404) = 1;
    goto LAB123;

LAB124:    *((unsigned int *)t405) = 1;
    goto LAB127;

LAB126:    t412 = (t405 + 4);
    *((unsigned int *)t405) = 1;
    *((unsigned int *)t412) = 1;
    goto LAB127;

LAB128:    t425 = *((unsigned int *)t413);
    t426 = *((unsigned int *)t419);
    *((unsigned int *)t413) = (t425 | t426);
    t427 = (t375 + 4);
    t428 = (t405 + 4);
    t429 = *((unsigned int *)t375);
    t430 = (~(t429));
    t431 = *((unsigned int *)t427);
    t432 = (~(t431));
    t433 = *((unsigned int *)t405);
    t434 = (~(t433));
    t435 = *((unsigned int *)t428);
    t436 = (~(t435));
    t437 = (t430 & t432);
    t438 = (t434 & t436);
    t439 = (~(t437));
    t440 = (~(t438));
    t441 = *((unsigned int *)t419);
    *((unsigned int *)t419) = (t441 & t439);
    t442 = *((unsigned int *)t419);
    *((unsigned int *)t419) = (t442 & t440);
    t443 = *((unsigned int *)t413);
    *((unsigned int *)t413) = (t443 & t439);
    t444 = *((unsigned int *)t413);
    *((unsigned int *)t413) = (t444 & t440);
    goto LAB130;

LAB131:    *((unsigned int *)t356) = 1;
    goto LAB134;

LAB133:    t451 = (t356 + 4);
    *((unsigned int *)t356) = 1;
    *((unsigned int *)t451) = 1;
    goto LAB134;

LAB135:    t457 = ((char*)((ng3)));
    t459 = (t0 + 7448U);
    t460 = *((char **)t459);
    memset(t458, 0, 8);
    t459 = (t458 + 4);
    t461 = (t460 + 4);
    t462 = *((unsigned int *)t460);
    t463 = (t462 >> 0);
    *((unsigned int *)t458) = t463;
    t464 = *((unsigned int *)t461);
    t465 = (t464 >> 0);
    *((unsigned int *)t459) = t465;
    t466 = *((unsigned int *)t458);
    *((unsigned int *)t458) = (t466 & 255U);
    t467 = *((unsigned int *)t459);
    *((unsigned int *)t459) = (t467 & 255U);
    xsi_vlogtype_concat(t456, 32, 32, 2U, t458, 8, t457, 24);
    goto LAB136;

LAB137:    t474 = (t0 + 10648U);
    t475 = *((char **)t474);
    t474 = ((char*)((ng7)));
    memset(t476, 0, 8);
    t477 = (t475 + 4);
    t478 = (t474 + 4);
    t479 = *((unsigned int *)t475);
    t480 = *((unsigned int *)t474);
    t481 = (t479 ^ t480);
    t482 = *((unsigned int *)t477);
    t483 = *((unsigned int *)t478);
    t484 = (t482 ^ t483);
    t485 = (t481 | t484);
    t486 = *((unsigned int *)t477);
    t487 = *((unsigned int *)t478);
    t488 = (t486 | t487);
    t489 = (~(t488));
    t490 = (t485 & t489);
    if (t490 != 0)
        goto LAB147;

LAB144:    if (t488 != 0)
        goto LAB146;

LAB145:    *((unsigned int *)t476) = 1;

LAB147:    memset(t492, 0, 8);
    t493 = (t476 + 4);
    t494 = *((unsigned int *)t493);
    t495 = (~(t494));
    t496 = *((unsigned int *)t476);
    t497 = (t496 & t495);
    t498 = (t497 & 1U);
    if (t498 != 0)
        goto LAB148;

LAB149:    if (*((unsigned int *)t493) != 0)
        goto LAB150;

LAB151:    t500 = (t492 + 4);
    t501 = *((unsigned int *)t492);
    t502 = *((unsigned int *)t500);
    t503 = (t501 || t502);
    if (t503 > 0)
        goto LAB152;

LAB153:    memcpy(t530, t492, 8);

LAB154:    memset(t473, 0, 8);
    t562 = (t530 + 4);
    t563 = *((unsigned int *)t562);
    t564 = (~(t563));
    t565 = *((unsigned int *)t530);
    t566 = (t565 & t564);
    t567 = (t566 & 1U);
    if (t567 != 0)
        goto LAB166;

LAB167:    if (*((unsigned int *)t562) != 0)
        goto LAB168;

LAB169:    t569 = (t473 + 4);
    t570 = *((unsigned int *)t473);
    t571 = *((unsigned int *)t569);
    t572 = (t570 || t571);
    if (t572 > 0)
        goto LAB170;

LAB171:    t585 = *((unsigned int *)t473);
    t586 = (~(t585));
    t587 = *((unsigned int *)t569);
    t588 = (t586 || t587);
    if (t588 > 0)
        goto LAB172;

LAB173:    if (*((unsigned int *)t569) > 0)
        goto LAB174;

LAB175:    if (*((unsigned int *)t473) > 0)
        goto LAB176;

LAB177:    memcpy(t472, t589, 8);

LAB178:    goto LAB138;

LAB139:    xsi_vlog_unsigned_bit_combine(t355, 32, t456, 32, t472, 32);
    goto LAB143;

LAB141:    memcpy(t355, t456, 8);
    goto LAB143;

LAB146:    t491 = (t476 + 4);
    *((unsigned int *)t476) = 1;
    *((unsigned int *)t491) = 1;
    goto LAB147;

LAB148:    *((unsigned int *)t492) = 1;
    goto LAB151;

LAB150:    t499 = (t492 + 4);
    *((unsigned int *)t492) = 1;
    *((unsigned int *)t499) = 1;
    goto LAB151;

LAB152:    t504 = (t0 + 2168U);
    t505 = *((char **)t504);
    t504 = ((char*)((ng8)));
    memset(t506, 0, 8);
    t507 = (t505 + 4);
    t508 = (t504 + 4);
    t509 = *((unsigned int *)t505);
    t510 = *((unsigned int *)t504);
    t511 = (t509 ^ t510);
    t512 = *((unsigned int *)t507);
    t513 = *((unsigned int *)t508);
    t514 = (t512 ^ t513);
    t515 = (t511 | t514);
    t516 = *((unsigned int *)t507);
    t517 = *((unsigned int *)t508);
    t518 = (t516 | t517);
    t519 = (~(t518));
    t520 = (t515 & t519);
    if (t520 != 0)
        goto LAB158;

LAB155:    if (t518 != 0)
        goto LAB157;

LAB156:    *((unsigned int *)t506) = 1;

LAB158:    memset(t522, 0, 8);
    t523 = (t506 + 4);
    t524 = *((unsigned int *)t523);
    t525 = (~(t524));
    t526 = *((unsigned int *)t506);
    t527 = (t526 & t525);
    t528 = (t527 & 1U);
    if (t528 != 0)
        goto LAB159;

LAB160:    if (*((unsigned int *)t523) != 0)
        goto LAB161;

LAB162:    t531 = *((unsigned int *)t492);
    t532 = *((unsigned int *)t522);
    t533 = (t531 & t532);
    *((unsigned int *)t530) = t533;
    t534 = (t492 + 4);
    t535 = (t522 + 4);
    t536 = (t530 + 4);
    t537 = *((unsigned int *)t534);
    t538 = *((unsigned int *)t535);
    t539 = (t537 | t538);
    *((unsigned int *)t536) = t539;
    t540 = *((unsigned int *)t536);
    t541 = (t540 != 0);
    if (t541 == 1)
        goto LAB163;

LAB164:
LAB165:    goto LAB154;

LAB157:    t521 = (t506 + 4);
    *((unsigned int *)t506) = 1;
    *((unsigned int *)t521) = 1;
    goto LAB158;

LAB159:    *((unsigned int *)t522) = 1;
    goto LAB162;

LAB161:    t529 = (t522 + 4);
    *((unsigned int *)t522) = 1;
    *((unsigned int *)t529) = 1;
    goto LAB162;

LAB163:    t542 = *((unsigned int *)t530);
    t543 = *((unsigned int *)t536);
    *((unsigned int *)t530) = (t542 | t543);
    t544 = (t492 + 4);
    t545 = (t522 + 4);
    t546 = *((unsigned int *)t492);
    t547 = (~(t546));
    t548 = *((unsigned int *)t544);
    t549 = (~(t548));
    t550 = *((unsigned int *)t522);
    t551 = (~(t550));
    t552 = *((unsigned int *)t545);
    t553 = (~(t552));
    t554 = (t547 & t549);
    t555 = (t551 & t553);
    t556 = (~(t554));
    t557 = (~(t555));
    t558 = *((unsigned int *)t536);
    *((unsigned int *)t536) = (t558 & t556);
    t559 = *((unsigned int *)t536);
    *((unsigned int *)t536) = (t559 & t557);
    t560 = *((unsigned int *)t530);
    *((unsigned int *)t530) = (t560 & t556);
    t561 = *((unsigned int *)t530);
    *((unsigned int *)t530) = (t561 & t557);
    goto LAB165;

LAB166:    *((unsigned int *)t473) = 1;
    goto LAB169;

LAB168:    t568 = (t473 + 4);
    *((unsigned int *)t473) = 1;
    *((unsigned int *)t568) = 1;
    goto LAB169;

LAB170:    t575 = (t0 + 7448U);
    t576 = *((char **)t575);
    memset(t574, 0, 8);
    t575 = (t574 + 4);
    t577 = (t576 + 4);
    t578 = *((unsigned int *)t576);
    t579 = (t578 >> 0);
    *((unsigned int *)t574) = t579;
    t580 = *((unsigned int *)t577);
    t581 = (t580 >> 0);
    *((unsigned int *)t575) = t581;
    t582 = *((unsigned int *)t574);
    *((unsigned int *)t574) = (t582 & 65535U);
    t583 = *((unsigned int *)t575);
    *((unsigned int *)t575) = (t583 & 65535U);
    t584 = ((char*)((ng3)));
    xsi_vlogtype_concat(t573, 32, 32, 2U, t584, 16, t574, 16);
    goto LAB171;

LAB172:    t591 = (t0 + 10648U);
    t592 = *((char **)t591);
    t591 = ((char*)((ng7)));
    memset(t593, 0, 8);
    t594 = (t592 + 4);
    t595 = (t591 + 4);
    t596 = *((unsigned int *)t592);
    t597 = *((unsigned int *)t591);
    t598 = (t596 ^ t597);
    t599 = *((unsigned int *)t594);
    t600 = *((unsigned int *)t595);
    t601 = (t599 ^ t600);
    t602 = (t598 | t601);
    t603 = *((unsigned int *)t594);
    t604 = *((unsigned int *)t595);
    t605 = (t603 | t604);
    t606 = (~(t605));
    t607 = (t602 & t606);
    if (t607 != 0)
        goto LAB182;

LAB179:    if (t605 != 0)
        goto LAB181;

LAB180:    *((unsigned int *)t593) = 1;

LAB182:    memset(t609, 0, 8);
    t610 = (t593 + 4);
    t611 = *((unsigned int *)t610);
    t612 = (~(t611));
    t613 = *((unsigned int *)t593);
    t614 = (t613 & t612);
    t615 = (t614 & 1U);
    if (t615 != 0)
        goto LAB183;

LAB184:    if (*((unsigned int *)t610) != 0)
        goto LAB185;

LAB186:    t617 = (t609 + 4);
    t618 = *((unsigned int *)t609);
    t619 = *((unsigned int *)t617);
    t620 = (t618 || t619);
    if (t620 > 0)
        goto LAB187;

LAB188:    memcpy(t647, t609, 8);

LAB189:    memset(t590, 0, 8);
    t679 = (t647 + 4);
    t680 = *((unsigned int *)t679);
    t681 = (~(t680));
    t682 = *((unsigned int *)t647);
    t683 = (t682 & t681);
    t684 = (t683 & 1U);
    if (t684 != 0)
        goto LAB201;

LAB202:    if (*((unsigned int *)t679) != 0)
        goto LAB203;

LAB204:    t686 = (t590 + 4);
    t687 = *((unsigned int *)t590);
    t688 = *((unsigned int *)t686);
    t689 = (t687 || t688);
    if (t689 > 0)
        goto LAB205;

LAB206:    t702 = *((unsigned int *)t590);
    t703 = (~(t702));
    t704 = *((unsigned int *)t686);
    t705 = (t703 || t704);
    if (t705 > 0)
        goto LAB207;

LAB208:    if (*((unsigned int *)t686) > 0)
        goto LAB209;

LAB210:    if (*((unsigned int *)t590) > 0)
        goto LAB211;

LAB212:    memcpy(t589, t707, 8);

LAB213:    goto LAB173;

LAB174:    xsi_vlog_unsigned_bit_combine(t472, 32, t573, 32, t589, 32);
    goto LAB178;

LAB176:    memcpy(t472, t573, 8);
    goto LAB178;

LAB181:    t608 = (t593 + 4);
    *((unsigned int *)t593) = 1;
    *((unsigned int *)t608) = 1;
    goto LAB182;

LAB183:    *((unsigned int *)t609) = 1;
    goto LAB186;

LAB185:    t616 = (t609 + 4);
    *((unsigned int *)t609) = 1;
    *((unsigned int *)t616) = 1;
    goto LAB186;

LAB187:    t621 = (t0 + 2168U);
    t622 = *((char **)t621);
    t621 = ((char*)((ng9)));
    memset(t623, 0, 8);
    t624 = (t622 + 4);
    t625 = (t621 + 4);
    t626 = *((unsigned int *)t622);
    t627 = *((unsigned int *)t621);
    t628 = (t626 ^ t627);
    t629 = *((unsigned int *)t624);
    t630 = *((unsigned int *)t625);
    t631 = (t629 ^ t630);
    t632 = (t628 | t631);
    t633 = *((unsigned int *)t624);
    t634 = *((unsigned int *)t625);
    t635 = (t633 | t634);
    t636 = (~(t635));
    t637 = (t632 & t636);
    if (t637 != 0)
        goto LAB193;

LAB190:    if (t635 != 0)
        goto LAB192;

LAB191:    *((unsigned int *)t623) = 1;

LAB193:    memset(t639, 0, 8);
    t640 = (t623 + 4);
    t641 = *((unsigned int *)t640);
    t642 = (~(t641));
    t643 = *((unsigned int *)t623);
    t644 = (t643 & t642);
    t645 = (t644 & 1U);
    if (t645 != 0)
        goto LAB194;

LAB195:    if (*((unsigned int *)t640) != 0)
        goto LAB196;

LAB197:    t648 = *((unsigned int *)t609);
    t649 = *((unsigned int *)t639);
    t650 = (t648 & t649);
    *((unsigned int *)t647) = t650;
    t651 = (t609 + 4);
    t652 = (t639 + 4);
    t653 = (t647 + 4);
    t654 = *((unsigned int *)t651);
    t655 = *((unsigned int *)t652);
    t656 = (t654 | t655);
    *((unsigned int *)t653) = t656;
    t657 = *((unsigned int *)t653);
    t658 = (t657 != 0);
    if (t658 == 1)
        goto LAB198;

LAB199:
LAB200:    goto LAB189;

LAB192:    t638 = (t623 + 4);
    *((unsigned int *)t623) = 1;
    *((unsigned int *)t638) = 1;
    goto LAB193;

LAB194:    *((unsigned int *)t639) = 1;
    goto LAB197;

LAB196:    t646 = (t639 + 4);
    *((unsigned int *)t639) = 1;
    *((unsigned int *)t646) = 1;
    goto LAB197;

LAB198:    t659 = *((unsigned int *)t647);
    t660 = *((unsigned int *)t653);
    *((unsigned int *)t647) = (t659 | t660);
    t661 = (t609 + 4);
    t662 = (t639 + 4);
    t663 = *((unsigned int *)t609);
    t664 = (~(t663));
    t665 = *((unsigned int *)t661);
    t666 = (~(t665));
    t667 = *((unsigned int *)t639);
    t668 = (~(t667));
    t669 = *((unsigned int *)t662);
    t670 = (~(t669));
    t671 = (t664 & t666);
    t672 = (t668 & t670);
    t673 = (~(t671));
    t674 = (~(t672));
    t675 = *((unsigned int *)t653);
    *((unsigned int *)t653) = (t675 & t673);
    t676 = *((unsigned int *)t653);
    *((unsigned int *)t653) = (t676 & t674);
    t677 = *((unsigned int *)t647);
    *((unsigned int *)t647) = (t677 & t673);
    t678 = *((unsigned int *)t647);
    *((unsigned int *)t647) = (t678 & t674);
    goto LAB200;

LAB201:    *((unsigned int *)t590) = 1;
    goto LAB204;

LAB203:    t685 = (t590 + 4);
    *((unsigned int *)t590) = 1;
    *((unsigned int *)t685) = 1;
    goto LAB204;

LAB205:    t691 = ((char*)((ng3)));
    t693 = (t0 + 7448U);
    t694 = *((char **)t693);
    memset(t692, 0, 8);
    t693 = (t692 + 4);
    t695 = (t694 + 4);
    t696 = *((unsigned int *)t694);
    t697 = (t696 >> 0);
    *((unsigned int *)t692) = t697;
    t698 = *((unsigned int *)t695);
    t699 = (t698 >> 0);
    *((unsigned int *)t693) = t699;
    t700 = *((unsigned int *)t692);
    *((unsigned int *)t692) = (t700 & 65535U);
    t701 = *((unsigned int *)t693);
    *((unsigned int *)t693) = (t701 & 65535U);
    xsi_vlogtype_concat(t690, 32, 32, 2U, t692, 16, t691, 16);
    goto LAB206;

LAB207:    t706 = (t0 + 7448U);
    t707 = *((char **)t706);
    goto LAB208;

LAB209:    xsi_vlog_unsigned_bit_combine(t589, 32, t690, 32, t707, 32);
    goto LAB213;

LAB211:    memcpy(t589, t690, 8);
    goto LAB213;

}

static void Cont_67_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 21352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 8888U);
    t3 = *((char **)t2);
    t2 = (t0 + 23048);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t8 = (t0 + 22712);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_68_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 21600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 17048U);
    t3 = *((char **)t2);
    t2 = (t0 + 23112);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0);
    t16 = (t0 + 22728);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_69_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 21848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 11608U);
    t3 = *((char **)t2);
    t2 = (t0 + 23176);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 31U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 4);
    t16 = (t0 + 22744);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_70_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 22096U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4888U);
    t3 = *((char **)t2);
    t2 = (t0 + 23240);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t8 = (t0 + 22760);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_71_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 22344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 9048U);
    t3 = *((char **)t2);
    t2 = (t0 + 23304);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t8 = (t0 + 22776);
    *((int *)t8) = 1;

LAB1:    return;
}


extern void work_m_00000000003280226697_3877310806_init()
{
	static char *pe[] = {(void *)Cont_58_0,(void *)Cont_59_1,(void *)Cont_60_2,(void *)Cont_67_3,(void *)Cont_68_4,(void *)Cont_69_5,(void *)Cont_70_6,(void *)Cont_71_7};
	xsi_register_didat("work_m_00000000003280226697_3877310806", "isim/mips_txt_isim_beh.exe.sim/work/m_00000000003280226697_3877310806.didat");
	xsi_register_executes(pe);
}
