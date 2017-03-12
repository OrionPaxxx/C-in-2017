#include <iostream>
#include <conio.h>
using namespace std;

#include "XWawa.h"

#pragma comment(lib, "XWawa.lib")

void BEGIN();
void END(XWawa&);

int main()
{
	XWawa wawa;

	wawa.assignTask(4);

	BEGIN();
	while (wawa.beanIsHere())
	{
		wawa.pickupBean();
		if (wawa.rightIsClear())
			wawa.moveRight();
		else
			break;
	}

	//======================
	while(1)
	{
		while(wawa.downsideIsClear())
		{
			wawa.moveDown();
			wawa.pickupBean();
		}
		while(!wawa.downsideIsClear())
		{
			wawa.moveRight();
			wawa.pickupBean();
			if((! wawa.rightIsClear()) && (!wawa.downsideIsClear()))
			{
				while(1)
				{
				wawa.moveUp();
				if(wawa.rightIsClear())
					{
					wawa.moveRight();
					break;
					}
				}
			}
		}
	}
	//=============

	END(wawa);
}

void BEGIN()
{
	_getch();
}

void END(XWawa &wawa)
{
	_getch();
}
