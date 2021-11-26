#include "game.h"
#include <iostream>
#include <fstream>
#define MAXNUM 30
#define MAX_V 5
#define MIN_V 2
#define LENGTH 50
#define SCORE_NUM 5
#define USER_V 6
#define CATCH_V 5
using namespace std;

EscapedSprite *escapedSprite[MAXNUM] = {nullptr};
UserSprite *userSprite = nullptr;
CatchSprite *catchSprite = nullptr;
ACL_Image Jerry, Tom, Dog, Game, Gameover, Rank_;
int escaped_num = 0;
int score = 0;
char Score[SCORE_NUM + 1] = "00000";
int time = 0;
int RANKFIRST = 0;
int RANKSECOND = 0;
int RANKTHIRD = 0;
char FIRST[SCORE_NUM + 1] = "00000";
char SECOND[SCORE_NUM + 1] = "00000";
char THIRD[SCORE_NUM + 1] = "00000";

int Setup()
{
    initWindow("Sprite Game", DEFAULT, DEFAULT, WIDTH, HIGH);
    loadImage("picture\\Jerry.jpg", &Jerry);
    loadImage("picture\\Tom.jpg", &Tom);
    loadImage("picture\\Dog.jpg", &Dog);
    loadImage("picture\\game.jpg", &Game);
    initConsole();
    HomePage();
    initScore();
    UserGenerate();
    CatchGenerate();
    registerMouseEvent(mouseEvent);
    return 0;
}

void Move()
{
    catchSprite->SelectDirection(userSprite);
    catchSprite->move();
    userSprite->move();
    for (int i = 0; i < escaped_num; i++)
    {
        escapedSprite[i]->escape(userSprite);
        escapedSprite[i]->move();
    }
}

void timeEvent(int tid)
{
    switch (tid)
    {
    case 0:
        Move();
        beginPaint();
        clearDevice();
        putImageScale(&Game, 0, 0, WIDTH, HIGH);
        for (int i = 0; i < escaped_num; i++)
        {
            escapedSprite[i]->show();
            if (collision(userSprite, escapedSprite[i]))
            {
                int randx = rand() % (WIDTH - LENGTH);
                int randy = rand() % (HIGH - LENGTH);
                int randv = rand() % (MAX_V - MIN_V) + MIN_V;
                escapedSprite[i] = new EscapedSprite(randx, randy, randv, LENGTH, LENGTH, &Jerry);
                score++;
            }
        }
        userSprite->show();
        catchSprite->show();
        ScoreUpdate();
        setTextSize(30);
        setTextColor(RED);
        setTextBkColor(EMPTY);
        paintText(0, 0, "SCORE:");
        paintText(95, 0, Score);
        if (collision(userSprite, catchSprite))
        {
            cancelTimer(0);
            cancelTimer(1);
            GameOver();
        }
        endPaint();
        break;
    case 1:
        if (escaped_num < MAXNUM)
        {
            int randx = rand() % (WIDTH - LENGTH);
            int randy = rand() % (HIGH - LENGTH);
            int randv = rand() % (MAX_V - MIN_V) + MIN_V;
            escapedSprite[escaped_num] = new EscapedSprite(randx, randy, randv, LENGTH, LENGTH, &Jerry);
            escaped_num++;
        }
        break;
    default:
        break;
    }
}

void UserGenerate()
{
    userSprite = new UserSprite(WIDTH / 2, HIGH / 2, USER_V, LENGTH, LENGTH, &Tom);
}

void CatchGenerate()
{
    catchSprite = new CatchSprite(0, 0, CATCH_V, LENGTH, LENGTH, &Dog);
}

void keyboardEvent(int key, int event)
{
    if (event == KEY_DOWN)
    {
        userSprite->PickDirection(key);
    }
    if (event == KEY_UP)
    {
        userSprite->ResetDirection(key);
    }
}

void ScoreUpdate()
{
    int score_ = score;
    for (int i = 0; i < SCORE_NUM; i++)
    {
        Score[SCORE_NUM - 1 - i] = score_ % 10 + 48;
        score_ /= 10;
    }
}

void initScore()
{
    for (int i = 0; i < MAXNUM; i++)
    {
        Score[i] = '\0';
    }
    score = 0;
}

void HomePage()
{
    beginPaint();
    ACL_Image StartIma;
    loadImage("picture\\Tom and Jerry.jpg", &StartIma);
    putImageScale(&StartIma, 0, 0, WIDTH, HIGH);
    setTextSize(80);
    setTextBkColor(WHITE);
    setTextColor(BLACK);
    paintText(1000, 100, "START");
    freeImage(&StartIma);
    endPaint();
}

void GameOver()
{
    initgame();
    read(&RANKFIRST, &RANKSECOND, &RANKTHIRD);
    Rank();
    write(RANKFIRST, RANKSECOND, RANKTHIRD);
    clearDevice();
    loadImage("picture\\gameover.gif", &Gameover);
    putImageScale(&Gameover, 0, 0, WIDTH, HIGH);
    setTextSize(50);
    setTextBkColor(EMPTY);
    setTextColor(BLACK);
    paintText(450, 300, "SCORE:");
    paintText(700, 300, Score);
    setTextBkColor(EMPTY);
    setTextColor(BLACK);
    setTextSize(100);
    paintText(400, 100, "Game Over!");
    registerMouseEvent(mouseEvent_);
    setTextBkColor(RED);
    setTextColor(WHITE);
    paintText(525, 400, "RANK");
    freeImage(&Jerry);
    freeImage(&Tom);
    freeImage(&Dog);
}

void mouseEvent(int x, int y, int button, int event)
{
    if (button == LEFT_BUTTON && event == BUTTON_DOWN)
    {
        if (x > 1000 && x < 1235 && y > 100 && y < 180)
        {
            registerKeyboardEvent(keyboardEvent);
            registerTimerEvent(timeEvent);
            startTimer(0, 10);
            startTimer(1, 1000);
            registerMouseEvent(nullptr);
        }
    }
}

void mouseEvent_(int x, int y, int button, int event)
{
    if (button == LEFT_BUTTON && event == BUTTON_DOWN)
    {
        if (x > 525 && x < 775 && y > 400 && y < 500)
        {
            beginPaint();
            clearDevice();
            loadImage("picture\\rank.jpg", &Rank_);
            putImageScale(&Rank_, 0, 0, WIDTH, HIGH);
            string_(RANKFIRST, FIRST);
            string_(RANKSECOND, SECOND);
            string_(RANKTHIRD, THIRD);
            setTextColor(BLACK);
            setTextBkColor(EMPTY);
            setTextSize(90);
            paintText(525, 50, "RANK");
            setTextSize(70);
            setTextColor(BLACK);
            paintText(400, 200, "FIRST:");
            setTextColor(RED);
            paintText(700, 200, FIRST);
            setTextColor(BLACK);
            paintText(400, 330, "SECOND:");
            setTextColor(RED);
            paintText(700, 330, SECOND);
            setTextColor(BLACK);
            paintText(400, 460, "THIRD:");
            setTextColor(RED);
            paintText(700, 460, THIRD);
            setTextBkColor(RED);
            setTextColor(WHITE);
            paintText(550, 590, "HOME");
            endPaint();
            registerMouseEvent(mouseEvent__);
        }
    }
}

void read(int *first, int *second, int *third)
{
    ifstream srcFile("rank.txt", ios::in);
    srcFile >> *first >> *second >> *third;
    srcFile.close();
}

void string_(int a, char *b)
{
    int a_ = a;
    for (int i = 0; i < SCORE_NUM; i++)
    {
        b[SCORE_NUM - 1 - i] = a_ % 10 + 48;
        a_ /= 10;
    }
}

void Rank()
{
    if (score > RANKTHIRD)
    {
        RANKTHIRD = score;
    }
    if (RANKTHIRD > RANKSECOND)
    {
        int a = RANKTHIRD;
        RANKTHIRD = RANKSECOND;
        RANKSECOND = a;
    }
    if (RANKFIRST < RANKSECOND)
    {
        int a = RANKSECOND;
        RANKSECOND = RANKFIRST;
        RANKFIRST = a;
    }
}

void write(int first, int second, int third)
{
    ofstream dest("rank.txt", ios::out);
    dest << first << " " << second << " " << third;
    dest.close();
}

void mouseEvent__(int x, int y, int button, int event)
{
    if (button == LEFT_BUTTON && event == BUTTON_DOWN)
    {
        if (x > 500 && x < 750 && y > 590 && y < 650)
        {
            HomePage();
            initScore();
            UserGenerate();
            CatchGenerate();
            registerMouseEvent(mouseEvent);
        }
    }
}

void initgame()
{
    for (int i = 0; i < escaped_num; i++)
    {
        delete escapedSprite[i];
    }
    escaped_num = 0;
}
