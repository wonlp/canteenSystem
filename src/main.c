#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
void HideCursor(int x);
void toxy(int x,int y);
void Amenu();//����Աϵͳ
void Smenu();//ѧ��ϵͳ
void welcome();//��ӭϵͳ
void load_A();
void load_S();
void register_();
void cancel_();//p��ʾ��Ҫע���Ŀ�//
void deposit_();//p��ʾ��Ҫ��ֵ�Ŀ�//
void lose_and_relive_lose_();//p��ʾ��Ҫ��ʧ�Ŀ�//
void add_();//�β�Ϊ��//
void look_up_card();//p��ʾ��Ҫ��ѯ�Ŀ�//
void figure_();//�β�Ϊ��//
void look_up_money_();//p��ʾ��Ҫ��ѯ���Ŀ�//
void look_up_record_();//p��ʾ��Ҫ��ѯ���Ѽ�¼�Ŀ�//
void buy_();//p��ʾ��Ҫģ�⹺��Ŀ�//
typedef struct student_card//ѧ������Ϣ//
    {
        char card[10];
		double money;
        char name[12];
        int state;
    }student_card;
typedef struct administrator//��������Ϣ//
    {
        int number;
        char code[10];
    }administrator;
typedef struct Menu//��Ʒ��Ϣ//
    {
        int number;
		char name[20];
        double price;
        int copy;//����//
    }Menu;
typedef struct Buy
{
	char name[20];
	int copy;
	double consuption;
	double money;
}Buy;
	Menu menu[7]={{1,"������˿",5.0,20},{2,"�Ǵ��Ｙ",6.0,25},{3,"���߲�",3.5,25},{4,"��������",5.5,30},{5,"����˿",2.5,30}};
    student_card student[20]={{"000001",200,"���",1},{"000002",200,"����",1},{"000003",200,"����",1},{"000004",200,"����",1},{"000005",200,"����",1},{"000006",200,"��ӱ",1}};
	administrator ad[4]={{1,"123456"},{2,"666666"}};
	int STU,kk[7]={0,0,0,0,0,0,0};/*STUΪ��¼ѧ���ı�ţ�kkΪ�������*/
void HideCursor(int x)//���ع�� ,��xΪ0ʱ�����أ�Ϊ1ʱ����ʾ 
{
	CONSOLE_CURSOR_INFO cursor_info ={1,x};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
 } 
void toxy(int x,int y)//������ƶ���x��y���괦
{
	COORD pos={x,y};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos); 
}
void welcome()
{
	int i;
	HideCursor(1);
	system("cls");
	system("color 74");
	toxy(20,6);
	printf("ʳ���Զ�������ϵͳ��ӭ����");
	toxy(15,9);
	printf("1.����Ա��¼");
	toxy(15,11);
	printf("2.ѧ����¼");
	HideCursor(0);
	scanf("%d",&i);
	if(i==1)
	{
		load_A();
	}
	if(i==2)
	{
		load_S();
	}
}
void Amenu()
{
	int a;
	HideCursor(1);
	system("cls");
	system("color 74");
	toxy(30,4);
	printf("����Աϵͳ");
	toxy(15,7);
	printf("1.ע���û�");
	toxy(15,9);
	printf("2.ע���û�");
	toxy(15,11);
	printf("3.��ֵ");
	toxy(15,13);
	printf("4.��ʧ���߽��");
	toxy(15,15);
	printf("5.��Ʒ���");
	toxy(15,17);
	printf("6.��Ϣ��ѯ");
	toxy(15,19);
	printf("7.ͳ��");
	scanf("%d",&a);
	switch(a)
	{
	case 1:register_();break;
	case 2: cancel_();break;
	case 3:deposit_();break;
	case 4:lose_and_relive_lose_();break;
	case 5:add_();break;
	case 6:look_up_card();break;
	case 7:figure_();break;
	}
	HideCursor(0);



}
void Smenu()
{
	int a;
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,4);
	printf("ѧ��ϵͳ");
	toxy(15,7);
	printf("1.��ѯ���");
	toxy(15,9);
	printf("2.��ѯ���Ѽ�¼");
	toxy(15,11);
	printf("3.ģ�⹺��");
	toxy(15,13);
	printf("4.��ӭ����");
	scanf("%d",&a);
	switch (a)
	{
	case 1:look_up_money_();break;
	case 2: look_up_record_();break;
	case 3:buy_();break;
	case 4:welcome();break;
	}
}
void load_A()
{
	FILE *p;
	int aa=0;
	int num;
	char cc[10];
	administrator ad_r[4];
	system("cls");
	HideCursor(1);
	system("color 74");
	p=fopen("data\\ad.dat","rb");
    if(p==0)
	{
		printf("file ad_r error\n");
		exit(1);
	}
	fread(ad_r+aa,sizeof(administrator),1,p);
	aa++;
	while(!feof(p))
	{
        fread(ad_r+aa,sizeof(administrator),1,p);
		aa++;
	}
	fclose(p);
	toxy(30,3);
	printf("����Ա��¼");
	toxy(17,6);
	printf("���:");
	toxy(17,8);
	printf("���룺");
	toxy(22,6);
	scanf("%d",&num);
	toxy(22,8);
    scanf("%s",cc);
	if(strcmp(cc,ad_r[num-1].code)==0)
			{
               system("cls");
	           HideCursor(1);
	           system("color 74");
			   toxy(35,15);
			   printf("��¼�ɹ�");
               HideCursor(0);
			   Sleep(1000);      //��ͣ1��
			   Amenu();
			}
	else
			{
			   system("cls");
	           HideCursor(1);
	           system("color 74");
			   printf("�����������");
			   Sleep(4000);
               load_A();
			   return;

			}		
}
void load_S()
{
	FILE *p;
	int bb;
	char ss[10];
	student_card student_r[20];
	int sss=0;
	p=fopen("data\\student.dat","rb");
    if(p==0)
	{
		printf("file student_r_load error\n");
		exit(1);
	}
	fread(student_r+sss,sizeof(student_card),1,p);
	sss++;
	while(!feof(p))
	{
        fread(student_r+sss,sizeof(student_card),1,p);
		sss++;
	}
	fclose(p);
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("ѧ����¼");
	toxy(17,6);
	printf("����:");
	toxy(22,6);
	scanf("%s",ss);
	for(bb=0;bb<8;bb++)
		{
			if(strcmp(ss,student_r[bb].card)==0)
			{
                system("cls");
	            HideCursor(1);
	            system("color 74");
	            printf("��ӭ�㣡%sͬѧ\n",student_r[bb].name );
				HideCursor(0);
				Sleep(1000);      //��ͣ1��
				STU=bb;
				Smenu();
                break;
                return;
			}
		}
	if(bb>7)
	{
		toxy(17,8);
		printf("���������������������");
		Sleep(2000);
		load_S();
	}
}
void register_()//ע���û�
{
	FILE *p;
	/*student_card st;*/
	student_card student_r[20];
	int ss=0;
	char nn[20],cc[10]="000007";
	p=fopen("data\\student.dat","rb");
    if(p==0)
	{
		printf("file student_r_register error\n");
		exit(1);
	}
	
	while(!feof(p))
	{
        fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
	system("cls");
	HideCursor(1);
	system("color 74");
	printf("%d",ss);
	toxy(30,3);
	printf("ע���û�");
	toxy(17,6);
	printf("����:");
	toxy(22,6);
	scanf("%s",nn);
	strcpy(student_r[ss-1].card ,cc);
	strcpy(student_r[ss-1].name ,nn);
	student_r[ss-1].money=200;
	student_r[ss-1].state=1;
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(20,8);
	printf("ע��ɹ�");
    toxy(17,10);
	printf("����:%s",student_r[ss-1].card );
	toxy(17,11);
	printf("����:%s",student_r[ss-1].name );
	toxy(17,12);
	printf("���:%lf",student_r[ss-1].money );
	toxy(17,13);
	printf("״̬:%d",student_r[ss-1].state);
	Sleep(4000);
	p=fopen("data\\student.dat","wb");
	if(p==0)
	{
		printf("file student_r_add error\n");
		exit(1);
	}
	fwrite(student_r,sizeof(student_card),ss,p);
	fclose(p);
	welcome();
	/*p=fopen("data\\student0.dat","rb");
    if(p==0)
	{
		printf("file student0_add error\n");
		exit(1);
	}
	fread(&st,sizeof(st),1,p);
	printf("%s   %s   %lf  %d",st.card ,st.name ,st.money ,st.state );
	fclose(p);*//*�˲��ֿ����ڲ鿴��¼�Ƿ���ӳɹ�*/
}
void cancel_()//ע���û�
{
	FILE *pp;
	/*student_card st;*/
	student_card student_r[20];
	int bb,i,ss=0;
	char p[10];
	pp=fopen("data\\student.dat","rb");
    if(pp==0)
	{
		system("cls");
	    HideCursor(1);
	    system("color 74");
		toxy(30,3);
		printf("file student_r_cancel error");
		exit(1);
	}
	fread(student_r+ss,sizeof(student_card),1,pp);
	ss++;
	while(!feof(pp))
	{
		fread(student_r+ss,sizeof(student_card),1,pp);
		ss++;
	}
	fclose(pp);
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("ע���û�");
	toxy(17,6);
	printf("����:");
	toxy(22,6);
	scanf("%s",&p);
	for(bb=0;bb<6;bb++)
		{
			if(strcmp(p,student_r[bb].card)==0)
			{

				break;
			}
		}
	for(i=0;i<6;i++)
	{
		student_r[bb].card[i]=0;
	}
	student_r[bb].state =3;
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("ע���ɹ�");
	Sleep(1000);
	pp=fopen("data\\student.dat","wb");
	if(pp==0)
	{
		system("cls");
	    HideCursor(1);
	    system("color 74");
		toxy(30,3);
		printf("file student_w error");
		exit(1);
	}
	fwrite(student_r,sizeof(student_card),ss,pp);
	fclose(pp);
	welcome();
	/*pp=fopen("data\\student.dat","rb");
    if(pp==0)
	{
		system("cls");
	    HideCursor(1);
	    system("color 74");
		toxy(30,3);
		printf("file student0 error");
		exit(1);
	}
	fread(&st,sizeof(student_card),1,pp);
	while(!feof(pp))
	{
		printf("%s   %s    %lf   %d\n",st.card ,st.name ,st.money ,st.state );
		fread(&st,sizeof(student_card),1,pp);
	}
	fclose(pp);*//*�˲������ڲ鿴�ļ����Ƿ�ע���ɹ�*/


}
void add_()//��Ӳ�Ʒ
{
	FILE *pp;
	int mm=0;
	Menu menu_r[10];
	Menu m;
	char cm[20];
	int c,i;
	double p;
	pp=fopen("data\\menu.dat","rb");
    if(pp==0)
	{
		system("cls");
	    HideCursor(1);
	    system("color 74");
		toxy(30,3);
		printf("file menu_r_add error");
		exit(1);
	}
	fread(menu_r+mm,sizeof(Menu),1,pp);
	mm++;
	while(!feof(pp))
	{
		fread(menu_r+mm,sizeof(Menu),1,pp);
		mm++;
	}
	fclose(pp);
	/*Menu m;*/
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("��Ʒ���");
	toxy(17,6);
	printf("����:");
	toxy(17,7);
	printf("����:");
	toxy(17,8);
	printf("����:");
	toxy(22,6);
	scanf("%s",cm);
	toxy(22,7);
	scanf("%lf",&p);
	toxy(22,8);
	scanf("%d",&c);
    system("cls");
	HideCursor(1);
	system("color 74");
	i=5;
	menu_r[i].number =i+1;
	strcpy(menu_r[i].name ,cm);
	menu_r[i].copy =c;
	menu_r[i].price =p;
	toxy(30,3);
	printf("��Ʒ��ӳɹ�!");
	pp=fopen("data\\menu.dat","wb");
	if(pp==0)
	{
		printf("file menu_add error\n");
		exit(1);
	}
	fwrite(menu_r,sizeof(Menu),i+1,pp);
	fclose(pp);
	pp=fopen("data\\menu.dat","rb");
	if(pp==0)
	{
		printf("file menu_add0 error\n");
		exit(1);
	}
	fread(&m,sizeof(m),1,pp);
    while(!feof(pp))
	{
        printf("%d  %s  %lf  %d      \n",m.number,m.name,m.price,m.copy   );
        fread(&m,sizeof(m),1,pp);
	}
	fclose(pp);
	Sleep(5000);
	welcome();/*�˲��ֿ����ڲ鿴��¼�Ƿ���ӳɹ�*/
}
void look_up_record_()
{
	FILE *pp;
	Buy buy_test;
	int bb=STU;
	student_card student_r[20];
	int ss=0;
	pp=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(pp==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,pp);
	ss++;
	while(!feof(pp))
	{
		fread(student_r+ss,sizeof(student_card),1,pp);
		ss++;
	}
	fclose(pp);
    system("cls");
	HideCursor(1);
	system("color 74");
	printf("%d",ss);//
	toxy(30,3);
	printf("%s�����Ѽ�¼",student_r[bb].name );
	toxy(1,5);
		switch(bb)
		{
		case 0:pp=fopen("data\\buy000001.dat","rb");break;
		case 1:pp=fopen("data\\buy000002.dat","rb");break;
        case 2:pp=fopen("data\\buy000003.dat","rb");break;
		case 3:pp=fopen("data\\buy000004.dat","rb");break;
		case 4:pp=fopen("data\\buy000005.dat","rb");break;
		case 5:pp=fopen("data\\buy000006.dat","rb");break;
		case 6:pp=fopen("data\\buy000007.dat","rb");break;
		}
		if(pp==0)
			{
				printf("file look_up_record error\n");
				exit(1);
			}
		fread(&buy_test,sizeof(Buy),1,pp);
		while(!feof(pp))
		{
			
			
			printf("�������˲�Ʒ%s %d��    ����%lf    ���Ϊ%lf\n",buy_test.name,buy_test.copy,buy_test.consuption,buy_test.money);
			fread(&buy_test,sizeof(Buy),1,pp);
		}
		fclose(pp);
		Sleep(7000);
		Smenu();
}
void buy_()
{
	int num,i,c,bb,ss,aa=0,mm=0;//cΪ����ķ���,bbΪ����ʱ��ѭ������,mmΪ����ʱ�����Ʒ������
	Buy buy[7];
	student_card st[20];
	Menu menu_r[10];
	FILE *b;
	bb=STU;
	b=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(b==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student origine error");
					exit(1);
	}
    fread(st+aa,sizeof(student_card),1,b);
	aa++;
	while(!feof(b))
	{
		fread(st+aa,sizeof(student_card),1,b);
		aa++;
	}
	fclose(b);
	b=fopen("data\\menu.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(b==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file menu origine error");
					exit(1);
	}
    fread(menu_r+mm,sizeof(Menu),1,b);
	mm++;
	while(!feof(b))
	{
		fread(menu_r+mm,sizeof(Menu),1,b);
		mm++;
	}
	fclose(b);
		system("cls");
	    HideCursor(1);
	    system("color 74");
		toxy(30,3);
		printf("ģ�⹺��");
		toxy(17,6);
		printf("����:");
		toxy(22,6);
	    scanf("%d",&num);
		for(i=0;i<7;i++)/*������Ҫ����Ĳ�Ʒ�������й���*/
		{
			if(num==menu_r[i].number)
			{
				system("cls");
	            HideCursor(1);
	            system("color 74");
				toxy(17,4);
				printf("������Ҫ����Ĳ�Ʒ����%d��",menu_r[i].copy);
				toxy(17,6);
				printf("����:");
				/*printf("%lf",st[bb].money );�۲����*/
				toxy(22,6);
				scanf("%d",&c);
			    st[bb].money=st[bb].money-menu_r[i].price*c;
				menu_r[i].copy -=c;
				if(st[bb].money<0)//����Ĳ���
				{
					system("cls");
	                HideCursor(1);
	                system("color 74");
                    st[bb].money+=menu_r[i].price*c;/*����ʧ�ܣ��ָ����*/
					menu_r[i].copy +=c;
					toxy(30,3);
					printf("��������!");
					toxy(17,5);
					printf("1.�������˵�����ӭ���棩");
					toxy(17,7);
					printf("2.��������");
					toxy(17,9);
					printf("3.ѡ��������Ʒ");
					scanf("%d",&ss);
					if(ss==1)
					{
						welcome();
						
					}
					if(ss==2)
					{
						Smenu();
					}
					if(ss==3)
					{
						buy_();
					}
				}
				b=fopen("data\\student.dat","wb");
				if(b==0)
				{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student error");
					exit(1);
				}
				fwrite(st,sizeof(student_card),aa,b);
				fclose(b);
                strcpy(buy[kk[bb]].name,menu_r[i].name);
				buy[kk[bb]].copy=c;
				buy[kk[bb]].consuption=menu_r[i].price*c;
				buy[kk[bb]].money=st[bb].money;
				b=fopen("data\\menu.dat","wb");
				if(b==0)
				{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file menu_r error");
					exit(1);
				}
				fwrite(menu_r,sizeof(Menu),mm,b);
				fclose(b);
				if(kk[bb]==0)
				{
					switch(bb)
				{
	 	        case 0:b=fopen("data\\buy000001.dat","wb");break;
		        case 1:b=fopen("data\\buy000002.dat","wb");break;
                case 2:b=fopen("data\\buy000003.dat","wb");break;
			    case 3:b=fopen("data\\buy000004.dat","wb");break;
				case 4:b=fopen("data\\buy000005.dat","wb");break;
                case 5:b=fopen("data\\buy000006.dat","wb");break;
				case 6:b=fopen("data\\buy000007.dat","wb");break;
				}
			 
			   if(b==0)
			   {
				   system("cls");
	               HideCursor(1);
	               system("color 74");
				   toxy(30,3);
				   printf("file buy error\n");
				   exit(1);
			   }
			   fwrite(buy+kk[bb],sizeof(Buy),1,b);
			   fclose(b);
			}
			else
			{
				switch(bb)
				{
		        case 0:b=fopen("data\\buy000001.dat","ab");break;
		        case 1:b=fopen("data\\buy000002.dat","ab");break;
                case 2:b=fopen("data\\buy000003.dat","ab");break;
			    case 3:b=fopen("data\\buy000004.dat","ab");break;
				case 4:b=fopen("data\\buy000005.dat","ab");break;
				case 5:b=fopen("data\\buy000006.dat","ab");break;
				case 6:b=fopen("data\\buy000007.dat","ab");break;
				}
				
				if(b==0)
				{
				    system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file buy error\n");
				    exit(1);
				}
				fwrite(buy+kk[bb],sizeof(Buy),1,b);
			    fclose(b);
			}
				system("cls");
	            HideCursor(1);
	            system("color 74");
				toxy(17,5);
				/*printf("%d  %lf\n",kk[bb],st[bb].money );�۲�kk*/
				printf("���ʼ���������");
				toxy(17,7);
				printf("1.��");
				toxy(17,9);
				printf("2.��");
				scanf("%d",&ss);
				if(ss==1)
				{
					
					kk[bb]++;
					buy_();
				}
				if(ss==2)
				{
				    Smenu();
				}
			}
			}
}
void deposit_()
{
	FILE *p;
	student_card student_r[20];
	int ss=0,i;
	double m;
	char cc[10];
	p=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(p==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,p);
	ss++;
	while(!feof(p))
	{
		fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("��ֵ");
	toxy(17,5);
	printf("����:");
	toxy(17,7);
	printf("��");
	toxy(22,5);
	scanf("%s",cc);
	toxy(22,7);
	scanf("%lf",&m);
	for(i=0;i<7;i++)
	{
		if(strcmp(cc,student_r[i].card)==0)
		{
			student_r[i].money +=m;
			break;
		}
	}
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(17,5);
	printf("��ֵ�ɹ���");
	toxy(17,7);
	printf("�������Ϊ��%lf",student_r[i].money );
	Sleep(4000);
	p=fopen("data\\student.dat","wb");
	if(p==0)
	{
		printf("file student_deposit error\n");
		exit(1);
	}
	fwrite(student_r,sizeof(student_card),ss,p);
	fclose(p);
	welcome();
}
void lose_and_relive_lose_()
{
	FILE *p;
	student_card student_r[20];
	int ss=0,i,a;
	char cc[10];
	p=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(p==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,p);
	ss++;
	while(!feof(p))
	{
		fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("��ʧ�ͽ��");
	toxy(17,5);
	printf("1.��ʧ");
	toxy(17,7);
	printf("2.���");
	scanf("%d",&a);
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(17,5);
	printf("����:");
	toxy(22,5);
	scanf("%s",cc);
	for(i=0;i<7;i++)
	{
		if(strcmp(cc,student_r[i].card)==0)
		{
			break;
		}
	}
	switch(a)
	{
	case 1:student_r[i].state =2;
		system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,6);
	printf("��ʧ�ɹ���");
	Sleep(4000);break;
	case 2:student_r[i].state =1;system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,6);
	printf("��ҳɹ���");
	Sleep(4000);break;
	}
    p=fopen("data\\student.dat","wb");
	if(p==0)
	{
		printf("file student_deposit error\n");
		exit(1);
	}
	fwrite(student_r,sizeof(student_card),ss,p);
	fclose(p);
	welcome();
}
void look_up_card()
{
	FILE *p;
	student_card student_r[20];
	int ss=0,i;
	char cc[10];
	p=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(p==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,p);
	ss++;
	while(!feof(p))
	{
		fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("��Ϣ��ѯ");
	toxy(17,5);
	printf("����:");
	toxy(22,5);
	scanf("%s",cc);
    for(i=0;i<7;i++)
	{
		if(strcmp(cc,student_r[i].card)==0)
		{
			break;
		}
	}
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(17,5);
	printf("����: %s",student_r[i].card );
	toxy(17,7);
    printf("������ %s",student_r[i].name );
	toxy(17,9);
	printf("�� %lf",student_r[i].money );
	toxy(17,11);
    printf("״̬�� %d",student_r[i].state );
	Sleep(4000);
	welcome();
}
void look_up_money_()
{
	int bb=STU;
	FILE *p;
	student_card student_r[20];
	int ss=0;
	p=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(p==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,p);
	ss++;
	while(!feof(p))
	{
		fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
    system("cls");
	HideCursor(1);
	system("color 74");
	toxy(17,7);
	printf("�������Ϊ��%lf",student_r[bb].money );
	Sleep(4000);
	Smenu();
}
void figure_()
{
	int b=0,c=0,d=0,i;
	FILE *p;
	student_card student_r[20];
	int ss=0;
	p=fopen("data\\student.dat","rb");//��ѧ������Ϣ�������Ա�����иĶ��ٶ���ȥ
    if(p==0)
	{
					system("cls");
	                HideCursor(1);
	                system("color 74");
					toxy(30,3);
					printf("file student_r error");
					exit(1);
	}
    fread(student_r+ss,sizeof(student_card),1,p);
	ss++;
	while(!feof(p))
	{
		fread(student_r+ss,sizeof(student_card),1,p);
		ss++;
	}
	fclose(p);
    for(i=0;i<20;i++)
	{
		switch(student_r[i].state )
		{
		case 1:b++;break;
		case 2:c++;break;
		case 3:d++;break;
		}
	}
	system("cls");
	HideCursor(1);
	system("color 74");
	toxy(30,3);
	printf("ͳ��");
	toxy(17,5);
	printf("����: %d",b);
	toxy(17,7);
	printf("��ʧ: %d",c);
	toxy(17,9);
    printf("ע��: %d",d);
	Sleep(5000);
	welcome();
}
int main()
{
	FILE *p;
	p=fopen("data\\student.dat","wb");
	if(p==0)
	{
		printf("file student_write error");
		exit(1);
	}
	fwrite(student,sizeof(student_card),6,p);
	fclose(p);
	p=fopen("data\\menu.dat","wb");
	if(p==0)
	{
		printf("file menu_write error");
		exit(1);
	}
	fwrite(menu,sizeof(Menu),5,p);
	fclose(p);
    p=fopen("data\\ad.dat","wb");
	if(p==0)
	{
		printf("file ad_write error");
		exit(1);
	}
	fwrite(ad,sizeof(administrator),2,p);
	fclose(p);
	welcome();
	return 0;
	
}