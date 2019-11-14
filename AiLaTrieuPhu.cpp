#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
struct Cauhoi
{
      char cauhoi[500];
      char dapanA[100];
      char dapanB[100];
      char dapanC[100];
      char dapanD[100];
      int ketqua;
};

struct Node
{
	Cauhoi data;
	Node* link;
};

struct List
{
	Node* first;
	Node* last;
};

void Init(List &l)
{
	l.first = l.last = NULL;
}

Node* GetNode(Cauhoi x)
{
	Node *p=new Node;
	p->data = x;
	p->link = NULL;
	return p;
}

void Addtail(List &l,  Node *p)
{
        if(l.first == NULL)
		{
			l.first=l.last = p;
		}
		else{
			l.last->link = p;
			l.last = p;
		}
}

void doc_file(Cauhoi &ch, FILE *fp)
{
	char *chuoi = new char[1000];
	char *str;
	fgets(chuoi,1000,fp);
	str=strtok(chuoi,",");
	strcpy(ch.cauhoi,str);
	str=strtok(NULL,",");
	strcpy(ch.dapanA,str);		
	str=strtok(NULL,",");
	strcpy(ch.dapanB,str);	
	str=strtok(NULL,",");
	strcpy(ch.dapanC,str);	
	str=strtok(NULL,",");
	strcpy(ch.dapanD,str);	
	str=strtok(NULL,",");
	ch.ketqua=atoi(str);		
}

void doc_danh_sach (List &l){
	FILE *fp;
	Cauhoi ch;
	Init(l);
	fp=fopen("data.txt","r");
	if(fp == NULL){
		printf("\nKhong mo duoc file");
	}
	else{
		while(!feof(fp)){
			doc_file(ch,fp);
			Node *p = GetNode(ch);
			Addtail(l,p);
		}
	}
	fclose(fp);
	printf("\n");
	
}

void xuatch(Cauhoi ch)
{
	printf("%s\n A. %s\n B. %s\n C. %s\n D. %s", ch.cauhoi, ch.dapanA, ch.dapanB, ch.dapanC, ch.dapanD);
}

void goidien(boolean &tg1)
{
	if(tg1==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		int a;
		do
		{
			a=rand()%4;
		}while(a==0);
		printf("\n Dap an nguoi than lua chon la %d", a);
		tg1=false;
	}
}

void bo(Cauhoi &k, boolean &tg2)
{
	if(tg2==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		int a, b;
		printf("\n Hai dap an sai la: ");
		do
		{
			a=rand()%4;
			b=rand()%4;
		}while(a==0||a==k.ketqua||b==0||b==k.ketqua||b==a);
		printf("%d\t%d", a, b);
		if(a==1||b==1)
			strcpy(k.dapanA, "");
		if(a==2||b==2)
			strcpy(k.dapanB, "");
		if(a==3||b==3)
			strcpy(k.dapanC, "");
		if(a==4||b==4)
			strcpy(k.dapanD, "");
		tg2=false;
	}
}

void hoiykien(boolean &tg3)
{
	if(tg3==false)
	{
		printf("\n Quyen tro giup nay da duoc su dung!");
		return;
	}
	else
	{
		int a, b , c, d;
		a=rand()%100;
		b=rand()%(100-a);
		c=rand()%(100-a-b);
		d=100-a-b-c;
		printf("\n Y kien khan gia trong truong quay la:\n 1:%d\n 2:%d\n 3:%d\n 4:%d", a, b, c, d);
		tg3=false;
	}
}

void trogiup(Cauhoi &k, boolean tg1, boolean tg2, boolean tg3)
{
    Beep(3000,200);
    int a;
    do
    {
  	 	printf("\n\n");
		printf("|======================================|\n");
	    printf("|                TRO GIUP              |\n");
    	printf("|======================================|\n");
    	printf("| 1.  GOI DIEN THOAI CHO NGUOI THAN    |\n");
		printf("|======================================|\n");
   	 	printf("|======================================|\n");
	 	printf("| 2.  LOAI BO 50/50                    |\n");
    	printf("|======================================|\n");
    	printf("|======================================|\n");
    	printf("| 3.  HOI Y KIEN KHAN GIA TRUONG QUAY  |\n");
    	printf("|======================================|\n");
    	printf("|======================================|\n");
    	printf("| 0.  QUAY LAI CAU HOI                 |\n");
    	printf("|======================================|\n");
    	do
    	{
	    	printf("\n Lua chon: "); scanf("%d", &a);
	    }while(a<0||a>3);
	    switch(a)
	    {
    		case 1:
    			goidien(tg1);
				break;
			case 2:
				bo(k, tg2);
				break;
			case 3:
				hoiykien(tg3);
				break; 
    	}
    }while(a!=0);
}

int goicauhoi(List l, int x, boolean &tg1, boolean &tg2, boolean &tg3)
{
	int a;
	Cauhoi k=l.first->data;
    quaylai:
	printf("\n Cau %d: ", x);
	xuatch(k);
	do
	{
		printf("\n De xem quyen tro giup: Nhan 0");
		printf("\n De chon A: Nhan 1");
		printf("\n De chon B: Nhan 2");
		printf("\n De chon C: Nhan 3");
		printf("\n De chon D: Nhan 4");
		printf("\n De dung cuoc choi: Nhan 5"); 
		printf("\n Lua chon: "); 
		scanf("%d", &a);
		
	}while(a<0||a>5);
	switch(a)
	{
		case 0:
			trogiup(k, tg1, tg2, tg3);
			goto quaylai;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			if(a==k.ketqua)
				return 1;
			else
				return 0;
			break;
		case 5:
			return -1;
			break;
	}
}

void tienthuong()
{
	Beep(3000,200);
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t| SO TIEN QUA MOI CAU HOI   |\n");
    printf("\t\t\t|===========================|\n\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 15: 150,000 DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 14: 85,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 13: 60,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 12: 40,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 11: 30,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 10: 22,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 9:  14,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 8:  10,000  DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 7:  6,000   DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 6:  3,000   DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 5:  2,000   DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 4:  1,000   DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 3:  600     DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 2:  400     DONG     |\n");
    printf("\t\t\t|===========================|\n");
    printf("\t\t\t|  Cau 1:  200     DONG     |\n");
    printf("\t\t\t|===========================|\n");
}

void tinhdiem(int x, int &diem)
{
	switch(x)
	{
		case 1:
			diem+=200;
			break;
		case 2:
			diem+=200;
			break;
		case 3:
			diem+=200;
			break;
		case 4:
			diem+=400;
			break;
		case 5:
			diem+=1000;
			break;
		case 6:
			diem+=1000;
			break;
		case 7:
			diem+=3000;
			break;
		case 8:
			diem+=4000;
			break;
		case 9:
			diem+=4000;
			break;
		case 10:
			diem+=8000;
			break;
		case 11:
			diem+=8000;
			break;
		case 12:
			diem+=10000;
			break;
		case 13:
			diem+=20000;
			break;
		case 14:
			diem+=25000;
			break;
		case 15:
			diem+=65000;
			break;
	}
}

void intienthuong(int diem)
{
		printf("\n Tien thuong cua ban la: %d", diem);
		Sleep(2000);
}

void batdauchoi(List l)
{
	system("cls");
	doc_danh_sach(l);
	tienthuong();
	Sleep(2000);
	system("cls");
	int x=1, diem=0, a, b, o;
	boolean tg1=true;
	boolean tg2=true;
	boolean tg3=true;
	
	while(l.first!=NULL)
	{
		int kq=goicauhoi(l, x, tg1, tg2, tg3);
		if(kq==1)
		{
			tinhdiem(x, diem);
			printf("\n SO TIEN HIEN TAI CUA BAN LA: %d", diem);
			if(x>5)
			{
				 do
				{
					printf("\n Nhan 1 de choi tiep hoac 0 de dung cuoc choi: "); scanf("%d", &a);
				}while(a<0||a>1);
				if(a==0)
				{
					intienthuong(diem);
					printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
					goto end;
				}
			}
			if(x==6)
			{
				printf("\n               THANG CUOC                   ");
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			x++;         
		}
		else if(kq==0)
		{
			if(x<=5)
			{
				diem = 0;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			else if(x<=10)
			{
				diem = 2000;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
			else
			{
				diem = 22000;
				intienthuong(diem);
				printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
				goto end;
			}
		}
		else
		{
			intienthuong(diem);
			printf("\n Nhan so bat ki de thoat!!"); scanf("%d", &b);
			goto end;
		}
		system("cls");
		l.first=l.first->link;
	}
end:;
}

void huongdan()
{
	system("cls");
 	printf("\t\t|============================================|\n");
  	printf("\t\t|\t\t HUONG DAN                   |\n");
 	printf("\t\t|============================================|\n\n");
  	printf("VUOT QUA DUOC 15 CAU HOI CUA CHUONG TRINH BAN SE NHAN DUOC 150 TRIEU DONG |\n");
  	printf("BAN CO CAC QUYEN TRO GIUP                                                 |\n");
  	printf("\n\n|=========================================================================|\n");
  	printf("|1. GOI DIEN THOAI CHO NGUOI THAN                                         |\n");
  	printf("|  BAN CO 30S DE GOI DIEN THOAI NHO SU GIUP SO CUA NGUOI THAN             |\n");
 	printf("|=========================================================================|\n");
 	printf("\n|=========================================================================|\n");
  	printf("|2. TRO GIUP 50/50 MAY TINH SE TU DONG LOAI BO HAI PHUONG AN SAI          |\n");
  	printf("|=========================================================================|\n");
  	printf("\n|=========================================================================|\n");
  	printf("|3. HOI Y KIEN KHAN GIA : KHAN GIA TRONG TRUONG QUAY SE DUA RA            |\nNHUNG DAP AN MA HO CHO LA CHINH XAC NHAT  |\n");
  	printf("|=========================================================================|\n\n\n");
  	Sleep(6000);
}

void nhapch(Cauhoi &a)
{
	printf("Nhap cau hoi: ");
	fflush(stdin);
	gets(a.cauhoi);
	printf("Nhap dap an 1: ");
	fflush(stdin);
	gets(a.dapanA);
	printf("Nhap dap an 2: ");
	fflush(stdin);
	gets(a.dapanB);
	printf("Nhap dap an 3: ");
	fflush(stdin);
	gets(a.dapanC);
	printf("Nhap dap an 4: ");
	fflush(stdin);
	gets(a.dapanD);
	printf("Nhap dap an dung(1-4): ");
	scanf("%d", &a.ketqua); 
}

void Themch()
{
	system("cls");
	Cauhoi ch;
	int a;
	FILE *fp;
	fp=fopen("data.txt","a");
	if(fp==NULL){
		printf("fdsfdsasdfds");
	}
	while(true)
	{
		nhapch(ch);
		fprintf(fp,"\n");
		fprintf(fp, "%s,%s,%s,%s,%s,%d", ch.cauhoi, ch.dapanA, ch.dapanB, ch.dapanC, ch.dapanD, ch.ketqua);
		do
		{
			printf("\n Nhap tiep: nhan 1\n Thoat: nhan 0");scanf("%d", &a);
		}while(a<0||a>1);
		if(a==0)
			break;		
	}
	fclose(fp);
}

int main()
{
	List l;
	Init(l);
	int chon;
	do
    {

        printf("\n\n\n|==============================================================================|\n");
        printf("|                   CHAO MUNG BAN DEN GAME AI LA TRIEU PHU                     |\n");
        printf("|==============================================================================|\n\n\n");
        printf("|==============================================================================|\n");
        printf("|                               1. BAT DAU                                     |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               2. HUONG DAN                                   |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               3. THEM CAU HOI                                |\n");
        printf("|==============================================================================|\n");
        printf("|==============================================================================|\n");
        printf("|                               4. THOAT                                       |\n");
        printf("|==============================================================================|\n");
        do
        {
            printf("\n CHON MUC : ");
            scanf("%d", &chon);
            if(chon<1||chon>4)
                printf(" Lua chon khong phu hop vui long chon lai \n");
        }while(chon<1 && chon>4);
        switch(chon)
        {
        	case 1:
        		Beep(3000,200);
        		batdauchoi(l);
        		break;
       		case 2:
       			Beep(3000,200);
       			huongdan();
       			break;
       		case 3:
				Beep(3000,200);
				Themch();
				break;
			case 4:
		 	
			break;
        }
        system("cls");
    }while(chon!=5);
    
     
    
	return 0;
}
