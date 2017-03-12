/*
	ZhangHua @ 2011-02-20

	瓦瓦捡豆子游戏程序
	用于《C++语言程序设计》课程，通过比较形象的、易接受的方式让学生去练习结构化程序设计和基于对象编程。

	瓦瓦
	一种人工智能体，生活在独立的空间中。
	在瓦瓦的空间中，它可以上下左右移动，每次移动一格，不能直接穿越墙壁，
	可以在某一格捡起或放下一粒豆子。

	瓦瓦的生活空间
	四面有墙壁，内部分成若干纵横排列的空格，
	每个格子可能是空白的、墙壁、或豆子，
	有一个瓦瓦生活在此空间内。

	修改记录：
	2014-03-04 去掉效果不好的速度调节功能。
	           增加瓦瓦移动次数统计功能。
	2012-10-05 把设置任务操作移到XWawaSpace中，要求学生设计和定义自己的XWawa。
*/

#ifndef XWAWA_H
#define XWAWA_H

// 空间的宽度和高度的最大值
const int XWAWAROOM_WIDTH_MAX = 16;
const int XWAWAROOM_HEIGHT_MAX = 8;

// 空间中每一点的值和/或显示状态
const char XWAWAROOM_EMPTY = ' ';		// 空
const char XWAWAROOM_BEAN = 'o';		// 有豆子
const char XWAWAROOM_WALL = 'H';		// 墙壁
const char XWAWAROOM_WAWA = '\x0C';		// 瓦瓦
const char XWAWAROOM_WAWAANDBEAN = '8';	// 有豆子，且瓦瓦也在该点

// 方向
const int XWAWAROOM_DIR_UP = 0;
const int XWAWAROOM_DIR_DOWN = 1;
const int XWAWAROOM_DIR_LEFT = 2;
const int XWAWAROOM_DIR_RIGHT = 3;

// 空间
class XWawaSpace
{
private:
	int width, height; // 空间的实际宽度和高度
	char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]; // 空间的状态

	int wawa_cx, wawa_cy; // 瓦瓦的位置

public:
	XWawaSpace();
	XWawaSpace(int w, int h);

	// 初始化
	void init();

	// 用指定的状态进行初始化
	void init(char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]);

	// 绘制空间
	void paint();

	// 重新绘制空间
	void repaint();

	// 获得空间的尺寸
	void getRect(int &width, int &height);

	// 设置点的状态
	void setPoint(int x, int y, char value);

	// 获得点的状态
	char getPoint(int x, int y);

	// 设置瓦瓦的位置
	void setWawaPos(int x, int y);

	// 获得瓦瓦的位置
	void getWawaPos(int &x, int &y);

	// 按指定方向移动瓦瓦
	bool moveWawa(int dir);

	// 指定方向的相邻位置是否无墙
	bool isClear(int dir);

	// 空间是否无豆子
	bool isEmpty();

	// 根据捡豆子任务（瓦瓦从左下角移动到右侧，并把所有的豆子捡起来）构建空间
	// 任务0：演示
	// 任务1：无障碍的爬山和下山
	// 任务2：越过固定障碍
	// 任务3：越过高度不确定、宽度固定、有间距的若干障碍
	// 任务4：越过高度、宽度和间距都不确定的若干障碍
	void build(int task);

	// 检查任务是否已完成
	bool check();
};

// 瓦瓦
class XWawa
{
private:
	int moveCount; // 移动次数

protected:
	XWawaSpace space; // 空间

public:
	XWawa();

	// 移动
	void moveUp();				// 向上
	void moveDown();			// 向下
	void moveLeft();			// 向左
	void moveRight();			// 向右

	int GetMoveCount() { return moveCount; }

	// 捡豆子和放豆子
	void pickupBean();				// 捡豆子
	void putdownBean();				// 放豆子

	// 判断周围有无墙壁（障碍物）
	bool leftIsClear();			// 左边
	bool rightIsClear();		// 右边
	bool upsideIsClear();		// 上边
	bool downsideIsClear();		// 下方

	// 判断当前位置有无豆子
	bool beanIsHere();

	// 分配捡豆子任务
	void assignTask(int task);

	// 检查任务是否已完成
	bool taskIsAccomplished();
};

#endif