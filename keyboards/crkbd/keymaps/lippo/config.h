#pragma once

#define MASTER_LEFT

#define QUICK_TAP_TERM 100
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define AAAAAAAAAAA 10

#define LAYOUT_3x6(...) LAYOUT_COLUMNS_3x6_IMPL(__VA_ARGS__)
#define LAYOUT_COLUMNS_3x6_IMPL( \
    LT5, LM5, LB5,              RT5, RM5, RB5,           \
    LT4, LT3, LT2, LT1, LT0,    RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,    RM0, RM1, RM2, RM3, RM4, \
    LB4, LB3, LB2, LB1, LB0,    RB0, RB1, RB2, RB3, RB4  \
) \
    LT5, LT4, LT3, LT2, LT1, LT0,    RT0, RT1, RT2, RT3, RT4, RT5, \
    LM5, LM4, LM3, LM2, LM1, LM0,    RM0, RM1, RM2, RM3, RM4, RM5, \
    LB5, LB4, LB3, LB2, LB1, LB0,    RB0, RB1, RB2, RB3, RB4, RB5
