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
		delay(50);
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(378,86,538,159)==2&& flag1 ==0)//��Ȼԭ��buttonh1����������if������λ�ã�����������ʽ�˵��ĺ���ѡ��Ҳ��Ҫif������λ�ú����ʾ��������������һ��if����������Ŀǰbug��ԭ��֮һ��
		{
			buttonhl(390,104,538,156,DB,LB,400,114,"��ѧ����",32,32,&flag1);
			/*��һ������ʽ�˵�*/
			xiala1();
			buttonhl(390,177,538,219,DB,LB,432,182,"����",32,32,&flag11);
	        buttonhl(390,240,538,282,DB,LB,432,245,"ר��",32,32,&flag12);
		}
		if (mouse_press(378,86,538,285)==0)//����ƿ���һ������ʽ�˵����ܷ�Χ�������������
		{
			MouseS=0;
			flag1=0;
			setfillstyle(1,NW);
	        bar(390,156,538,282);//�ð�ɫ���θ��Ǻ����������ﵽ���������Ч��
		}
		if (mouse_press(578,86,738,159)==2)
		{
			buttonhl(590,104,738,156,LB,DB,600,114,"ԺУ��ɫ",32,32,&flag2);
			/*�ڶ�������ʽ�˵�*/
			xiala2();
			buttonhl(590,156,738,198,LB,DB,620,161,"�Ű���",32,32,&flag21);
         	buttonhl(590,198,738,240,LB,DB,620,203,"��һһ",32,32,&flag22);
	        buttonhl(590,240,738,280,LB,DB,620,245,"˫һ��",32,32,&flag23);

		}
		if (mouse_press(578,86,738,285)==0)
		{
			MouseS=0;
			setfillstyle(1,NW);
	        bar(590,156,738,282);//ͬ�ϣ�����˵�+-
		}

		if(press==2){
			press=0;
			break;//��ʱ���˳������ܴ��룬�Ժ�Ľ�

		}
	} 
	press=0;
	getch();
	cleardevice();
	closesvga();
	return 0;
}

/*�ʼ�õĻ�����ʼ�����˵�������������ʵ����ɾ�ˣ���buttonh1�����֮ǰ�Ĺ���*/
void xiala1(void){
	setfillstyle(1,LB);
	bar(390,177,538,219);
	bar(390,240,538,282);
	puthz(432,182,"����",32,32,DB);
	puthz(432,245,"ר��",32,32,DB);

}

void xiala2(void){
	setfillstyle(1,LB);
	bar(590,156,738,198);
	bar(590,198,738,240);
	bar(590,240,738,280);
	puthz(620,161,"�Ű���",32,32,DB);
	puthz(620,203,"��һһ",32,32,DB);
	puthz(620,245,"˫һ��",32,32,DB);
	
}