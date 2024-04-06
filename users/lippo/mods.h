#pragma once

#define GASC_BOTTOM(...) GASC_BOTTOM_IMPL(__VA_ARGS__)
#define GASC_BOTTOM_IMPL( \
    LT4, LT3, LT2, LT1, LT0,   RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,   RM0, RM1, RM2, RM3, RM4, \
    LB4, LB3, LB2, LB1, LB0,   RB0, RB1, RB2, RB3, RB4  \
) \
    LT4, LT3, LT2, LT1, LT0,   RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,   RM0, RM1, RM2, RM3, RM4, \
    LGUI_T(LB4), LALT_T(LB3), LSFT_T(LB2), LCTL_T(LB1), LB0,   RB0, RCTL_T(RB1), RSFT_T(RB2), LALT_T(RB3), RGUI_T(RB4)
