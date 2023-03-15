#include "main.h"
#include "cinit.c"
#include "SVGAUTIL.C"
#include "hz.c"
#include "mouse.c"
#include "wlcm.c"
#include "moni.c"
#include "filerw.c"
#include "wi.c"
#include "cal.c"



void xiala1(void);
void xiala2(void);

 
void main(void){
	int flag1=0,flag11=0,flag12=0,flag2=0,flag21=0,flag22=0,flag23=0;
	initsvga();
	cleardevice();
	setfillstyle(1,NW);//画背景，白色
	bar(1,1,1024,768);
	
	setfillstyle(1,LY);
	bar(90,92,340,160);
	setfillstyle(1,LB);
	bar(390,104,538,156);
	bar(590,104,738,156);//画按钮

	puthz(416,25,"查大学",48,48,DB);
	puthz(100,102,"筛选选项：",48,48,LR);
	puthz(400,114,"办学类型",32,32,DB);
	puthz(600,114,"院校特色",32,32,DB);//输出标题及按钮内的字

	setcolor(256);
	setlinestyle(0,0,3);
	moveto(50,300);
	lineto(974,300);
	lineto(974,700);
	lineto(50,700);
	lineto(50,300);
	line(50,400,974,400);
	line(50,500,974,500);
	line(50,600,974,600);//画显示大学的方框

	mouseinit();
	while(1)
	{
		delay(50);
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(378,86,538,159)==2&& flag1 ==0)//虽然原本buttonh1函数内已有if检测鼠标位置，但由于下拉式菜单的后续选项也需要if检测鼠标位置后才显示，故这里再套了一层if。（可能是目前bug的原因之一）
		{
			buttonhl(390,104,538,156,DB,LB,400,114,"办学类型",32,32,&flag1);
			/*第一个下拉式菜单*/
			xiala1();
			buttonhl(390,177,538,219,DB,LB,432,182,"本科",32,32,&flag11);
	        buttonhl(390,240,538,282,DB,LB,432,245,"专科",32,32,&flag12);
		}
		if (mouse_press(378,86,538,285)==0)//鼠标移开第一个下拉式菜单的总范围后清除后续按键
		{
			MouseS=0;
			flag1=0;
			setfillstyle(1,NW);
	        bar(390,156,538,282);//用白色矩形覆盖后续按键来达到将其清除的效果
		}
		if (mouse_press(578,86,738,159)==2)
		{
			buttonhl(590,104,738,156,LB,DB,600,114,"院校特色",32,32,&flag2);
			/*第二个下拉式菜单*/
			xiala2();
			buttonhl(590,156,738,198,LB,DB,620,161,"九八五",32,32,&flag21);
         	buttonhl(590,198,738,240,LB,DB,620,203,"二一一",32,32,&flag22);
	        buttonhl(590,240,738,280,LB,DB,620,245,"双一流",32,32,&flag23);

		}
		if (mouse_press(578,86,738,285)==0)
		{
			MouseS=0;
			setfillstyle(1,NW);
	        bar(590,156,738,282);//同上，清除菜单+-
		}

		if(press==2){
			press=0;
			break;//暂时的退出程序功能代码，以后改进

		}
	} 
	press=0;
	getch();
	cleardevice();
	closesvga();
	return 0;
}

/*最开始用的画出初始下拉菜单的俩函数，其实可以删了，有buttonh1替代了之前的功能*/
void xiala1(void){
	setfillstyle(1,LB);
	bar(390,177,538,219);
	bar(390,240,538,282);
	puthz(432,182,"本科",32,32,DB);
	puthz(432,245,"专科",32,32,DB);

}

void xiala2(void){
	setfillstyle(1,LB);
	bar(590,156,738,198);
	bar(590,198,738,240);
	bar(590,240,738,280);
	puthz(620,161,"九八五",32,32,DB);
	puthz(620,203,"二一一",32,32,DB);
	puthz(620,245,"双一流",32,32,DB);
	
}