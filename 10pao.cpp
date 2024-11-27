#include "avz.h"

using namespace AvZ;

void Script(){
    //OpenMultipleEffective('Q', AvZ::MAIN_UI_OR_FIGHT_UI);
    //设置僵尸
    SetZombies({CG_3,TT_18,BC_12, XC_15, WW_8, FT_21, KG_17, BY_23, HY_32, HT_14});
    //选卡
    SelectCards({
        ICE_SHROOM,
        M_ICE_SHROOM,
        COFFEE_BEAN,
        CHERRY_BOMB, 
        JALAPENO,
        PUMPKIN,
        PUFF_SHROOM,
        SUN_SHROOM,
        FLOWER_POT,
        SCAREDY_SHROOM,
    });
    
    //在第1波刷新5.99秒之前，设置炮列表
    SetTime(-599,1);
    pao_operator.resetPaoList({{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{3,1},
    {4,1},{3,3},{4,3},{3,7},{4,7}
    });//游戏内{行,列}，一共9行9列
    
    {SetTime(-95,1);
    pao_operator.pao({{2,9},{5,9}});}

    for(auto wave : {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18}){
    SetTime(-45,wave);
    pao_operator.pao({{2,8.65},{5,8.65}})//在第wave波第0.45秒前发射玉米跑
    ;}

    for(auto wave : {9,19,20}){
    SetTime(700,wave);
    pao_operator.recoverPao({{2,8.7},{5,8.7},{2,8.7},{5,8.7}})
    ;} //补刀
    
    //w20
    {SetTime(-35,20);
    pao_operator.pao({{2,9},{5,9}});} 

    //中场消延迟
    SetTime(-45+373-100,10);
    Card(CHERRY_BOMB,{{2,9},{5,9}});//优先在{2,9}使用樱桃炸弹，否则{5,9}
    
    //w19
    SetTime(-45+373-100,19);
    Card(CHERRY_BOMB,{{2,9}});
    {SetTime(-45,19);
    pao_operator.pao({{5,9}});}

    //pao消珊瑚
    SetTime(-150,20);
    pao_operator.pao(4,7.5875);

}
