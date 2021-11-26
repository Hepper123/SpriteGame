#include "acllib.h"
#include "CatchSprite.h"
#include "EscapedSprite.h"
#include "UserSprite.h"

void HomePage();//HOME界面
void UserGenerate();//用户精灵生成
void EscapedGenerate();//逃脱精灵生成
void CatchGenerate();//抓捕精灵生成
void initScore();//初始化分数
void mouseEvent(int x, int y, int button, int event);//鼠标事件
void EscapedMove();//逃脱精灵行动
void timeEvent(int id);//时间事件
void GameOver();//游戏结束
void ScoreUpdate();//更新分数
void KeyboardEvent(int key, int event);//键盘事件
void read(int *first, int *second, int *third);//读取文本数据
void string_(int a, char* b);//字符串化数据
void mouseEvent_(int x, int y, int button, int event);//排行榜
void Rank();//排行
void write(int first, int second, int third);//写入文本数据
void mouseEvent__(int x, int y, int button, int event);//重新游戏
void initgame();//游戏初始化