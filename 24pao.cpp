#include "avz.h"
using namespace AvZ;
void Script()
{
    //OpenMultipleEffective('Q', AvZ::MAIN_UI_OR_FIGHT_UI); //多次生效
    SetZombies({CG_3,TT_18,BC_12, XC_15, WW_8, FT_21, KG_17, BY_23, HY_32, HT_14});
    pao_operator.resetPaoList({ { 1, 1 }, { 6, 1 }, { 1, 3 }, { 6, 3 }, { 1, 5 }, { 6, 5 }, { 1, 7 }, { 6, 7 }, { 2, 1 }, { 5, 1 }, { 2, 3 }, { 5, 3 }, { 2, 5, }, { 5, 5 }, { 2, 7 }, { 5, 7 }, { 3, 1 }, { 4, 1 }, { 3, 3 }, { 4, 3 }, { 3, 5 }, { 4, 5 }, { 3, 7 }, { 4, 7 } }); //炮序
    ice_filler.start({ { 4, 9 } }); //存冰
    SelectCards({
    ICE_SHROOM, // 寒冰菇
    M_ICE_SHROOM, // 模仿寒冰菇
    COFFEE_BEAN, // 咖啡豆
    DOOM_SHROOM, // 毁灭菇
    LILY_PAD, // 荷叶
    SQUASH, // 倭瓜
    CHERRY_BOMB, // 樱桃炸弹
    BLOVER, // 三叶草
    PUMPKIN, // 南瓜头
    PUFF_SHROOM, // 小喷菇
    }); //选卡
    //SetZombies({ CG_3, GL_7, KG_17, BC_12, XC_15, FT_21, HT_14, TT_18, BY_23, HY_32, WW_8, TL_22, QQ_16 }); //刺激的出怪
    KeyConnect('Q', [=]() {AvZ::setGameSpeed(0.5);});
    KeyConnect('W', [=]() {AvZ::setGameSpeed(1);});
    KeyConnect('E', [=]() {AvZ::setGameSpeed(10);}); //10倍速冲关（约15秒/2f）
    KeyConnect('P', [=]() {pao_operator.pao(MouseRow(), MouseCol());});
    for (auto wave:{ 1, 4, 7, 11, 14, 17 })
    {
        SetTime(-15, wave);
        pao_operator.pao({ { 2, 9 }, { 5, 9 } });
        SetTime(-15+107,wave);
        pao_operator.pao({ { 1, 7.7 }, { 5, 7.7 } }); //精准之舞
    }
    for (auto wave:{ 2, 5, 8, 12, 15, 18 })
    {
        SetTime(-95, wave);
        pao_operator.pao({ { 2, 9 }, { 5, 9 } });
        SetTime(-95+180,wave);
        ice_filler.coffee();
        Ice3(298); //ice3
    }
    for (auto wave:{ 3, 6, 9, 13, 16, 19 })
    {
        SetTime(-95, wave);
        pao_operator.pao({ { 2, 9 }, { 5, 9 }, { 2, 9 }, { 5, 9 } });
        SetTime(-95+110,wave);
        pao_operator.pao({ { 1, 8.8 }, { 5, 8.8 } }); //双边PSD
    }
    for (auto wave:{ 9, 19 })
    {
        SetTime(601-15, wave);
        pao_operator.pao({ { 2, 9 }, { 5, 9 } }); //补刀红眼
    }
    for (auto wave:{ 10 })
    {
        SetTime(-55, wave);
        pao_operator.pao({ { 2, 9 }, { 5, 9 }, { 2, 9 }, { 5, 9 } });
        SetTime(-55+110,wave);
        pao_operator.pao({ { 1, 8.8 }, { 5, 8.8 } }); //W10
    }
    for (auto wave:{ 20 })
    {
        SetTime(-150, wave);
        pao_operator.pao({ { 4, 6 }, { 4, 8 } });
        SetTime(-150+90, wave);
        pao_operator.pao({ { 1, 9 }, { 2, 9 }, { 5, 9 }, { 6, 9 } });
        SetTime(-150+90+100, wave);
        pao_operator.pao({ { 1, 9 }, { 2, 9 }, { 5, 9 }, { 6, 9 } }); //W20暴力收尾
    }
}