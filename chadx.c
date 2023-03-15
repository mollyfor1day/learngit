#include "main.h"
#include "SVGAUTIL.C"
#include "cinit.c"
#include "hz.c"
#include "mouse.c"



void xiala1(void);
void xiala2(void);

 
void main(void){
	initsvga();
	cleardevice();
	setfillstyle(1,NW);//����������ɫ
	bar(1,1,1024,768);
	setfillstyle(1,LY);
	bar(90,92,340,160);
	setfillstyle(1,LB);
	bar(390,104,538,156);
	bar(590,104,738,156);//����ť
	puthz(416,25,"���ѧ",48,48,DB);
	puthz(100,102,"ɸѡѡ�",48,48,LR);
	puthz(400,114,"��ѧ����",32,32,DB);
	puthz(600,114,"ԺУ��ɫ",32,32,DB);//������⼰��ť�ڵ���
	setcolor(256);
	setlinestyle(0,0,3);
	moveto(50,300);
	lineto(974,300);
	lineto(974,700);
	lineto(50,700);
	lineto(50,300);
	line(50,400,974,400);
	line(50,500,974,500);
	line(50,600,974,600);//����ʾ��ѧ�ķ���

	mouseinit();
	while(1)
	{
		delay(30);
		newmouse(&MouseX,&MouseY,&press);

		if (mouse_press(390,104,538,156)==2)
		{
			MouseS=1;
			xiala1();
			if (mouse_press(390,156,538,240)==2){
				MouseS=1;
			}
		}
		if (mouse_press(390,104,538,240)==0)
		{
			MouseS=0;
			setfillstyle(1,NW);
	        bar(390,156,538,240);
		}
		if (mouse_press(590,104,738,156)==2)
		{
			MouseS=1;
			xiala2();
			if (mouse_press(590,156,738,282)==2){
				MouseS=1;
			}
		}
		if (mouse_press(590,104,738,282)==0)
		{
			MouseS=0;
			setfillstyle(1,NW);
	        bar(590,156,738,282);
		}

		if(press==2){
			press=0;
			break;

		}
	} 
	press=0;
	getch();
	cleardevice();
	closesvga();
	return 0;
}


void xiala1(void){
	setfillstyle(1,LB);
	bar(390,156,538,198);
	bar(390,198,538,240);
	puthz(432,161,"����",32,32,DB);
	puthz(432,203,"ר��",32,32,DB);

}

void xiala2(void){
	setfillstyle(1,LB);

	bar(590,156,738,198);
	bar(590,198,738,240);
	bar(590,240,738,280);
	settextstyle(1,0,4);
	outtextxy(640,161,"985");
	outtextxy(640,203,"211");
	puthz(620,245,"˫һ��",32,32,DB);
}