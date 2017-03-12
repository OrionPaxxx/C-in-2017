/*
	ZhangHua @ 2011-02-20

	���߼�����Ϸ����
	���ڡ�C++���Գ�����ơ��γ̣�ͨ���Ƚ�����ġ��׽��ܵķ�ʽ��ѧ��ȥ��ϰ�ṹ��������ƺͻ��ڶ����̡�

	����
	һ���˹������壬�����ڶ����Ŀռ��С�
	�����ߵĿռ��У����������������ƶ���ÿ���ƶ�һ�񣬲���ֱ�Ӵ�Խǽ�ڣ�
	������ĳһ���������һ�����ӡ�

	���ߵ�����ռ�
	������ǽ�ڣ��ڲ��ֳ������ݺ����еĿո�
	ÿ�����ӿ����ǿհ׵ġ�ǽ�ڡ����ӣ�
	��һ�����������ڴ˿ռ��ڡ�

	�޸ļ�¼��
	2014-03-04 ȥ��Ч�����õ��ٶȵ��ڹ��ܡ�
	           ���������ƶ�����ͳ�ƹ��ܡ�
	2012-10-05 ��������������Ƶ�XWawaSpace�У�Ҫ��ѧ����ƺͶ����Լ���XWawa��
*/

#ifndef XWAWA_H
#define XWAWA_H

// �ռ�Ŀ�Ⱥ͸߶ȵ����ֵ
const int XWAWAROOM_WIDTH_MAX = 16;
const int XWAWAROOM_HEIGHT_MAX = 8;

// �ռ���ÿһ���ֵ��/����ʾ״̬
const char XWAWAROOM_EMPTY = ' ';		// ��
const char XWAWAROOM_BEAN = 'o';		// �ж���
const char XWAWAROOM_WALL = 'H';		// ǽ��
const char XWAWAROOM_WAWA = '\x0C';		// ����
const char XWAWAROOM_WAWAANDBEAN = '8';	// �ж��ӣ�������Ҳ�ڸõ�

// ����
const int XWAWAROOM_DIR_UP = 0;
const int XWAWAROOM_DIR_DOWN = 1;
const int XWAWAROOM_DIR_LEFT = 2;
const int XWAWAROOM_DIR_RIGHT = 3;

// �ռ�
class XWawaSpace
{
private:
	int width, height; // �ռ��ʵ�ʿ�Ⱥ͸߶�
	char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]; // �ռ��״̬

	int wawa_cx, wawa_cy; // ���ߵ�λ��

public:
	XWawaSpace();
	XWawaSpace(int w, int h);

	// ��ʼ��
	void init();

	// ��ָ����״̬���г�ʼ��
	void init(char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]);

	// ���ƿռ�
	void paint();

	// ���»��ƿռ�
	void repaint();

	// ��ÿռ�ĳߴ�
	void getRect(int &width, int &height);

	// ���õ��״̬
	void setPoint(int x, int y, char value);

	// ��õ��״̬
	char getPoint(int x, int y);

	// �������ߵ�λ��
	void setWawaPos(int x, int y);

	// ������ߵ�λ��
	void getWawaPos(int &x, int &y);

	// ��ָ�������ƶ�����
	bool moveWawa(int dir);

	// ָ�����������λ���Ƿ���ǽ
	bool isClear(int dir);

	// �ռ��Ƿ��޶���
	bool isEmpty();

	// ���ݼ����������ߴ����½��ƶ����Ҳ࣬�������еĶ��Ӽ������������ռ�
	// ����0����ʾ
	// ����1�����ϰ�����ɽ����ɽ
	// ����2��Խ���̶��ϰ�
	// ����3��Խ���߶Ȳ�ȷ������ȹ̶����м��������ϰ�
	// ����4��Խ���߶ȡ���Ⱥͼ�඼��ȷ���������ϰ�
	void build(int task);

	// ��������Ƿ������
	bool check();
};

// ����
class XWawa
{
private:
	int moveCount; // �ƶ�����

protected:
	XWawaSpace space; // �ռ�

public:
	XWawa();

	// �ƶ�
	void moveUp();				// ����
	void moveDown();			// ����
	void moveLeft();			// ����
	void moveRight();			// ����

	int GetMoveCount() { return moveCount; }

	// ���ӺͷŶ���
	void pickupBean();				// ����
	void putdownBean();				// �Ŷ���

	// �ж���Χ����ǽ�ڣ��ϰ��
	bool leftIsClear();			// ���
	bool rightIsClear();		// �ұ�
	bool upsideIsClear();		// �ϱ�
	bool downsideIsClear();		// �·�

	// �жϵ�ǰλ�����޶���
	bool beanIsHere();

	// �����������
	void assignTask(int task);

	// ��������Ƿ������
	bool taskIsAccomplished();
};

#endif