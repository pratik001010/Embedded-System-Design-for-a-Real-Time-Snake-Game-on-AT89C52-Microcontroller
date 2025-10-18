#include <reg51.h>
#define uchar unsigned char
#define SNAKE 20                 //????
#define TIME 50                 //??????
#define SPEED 80              //????
sbit keyenable=P2^6;			//????
sbit right=P2^4;       
sbit left=P2^0;
sbit down=P2^2;
sbit up=P2^1;
///////////////////////////////////////
uchar x[SNAKE+1];
uchar y[SNAKE+1];          
uchar time,n,i,e;              //????,????,??????,????		
char addx,addy;                //?????
/********************
????
*********************/
void delay(char MS)
{
	char us,usn;
	while(MS!=0)
	{
		usn = 0;
		while(usn!=0)
		{
			us=0xff;
			while (us!=0){us--;};
			usn--;
		}
		MS--;
	}
}
/*******************************************
????
*******************************************/
bit knock()
{
	bit k;
	k=0;
	if(x[1]>7||y[1]>7)k=1;                             //??
	for(i=2;i<n;i++)if((x[1]==x[i])&(y[1]==y[i]))k=1;  //???
	return k;
}
/*****************
????????
*****************/
void turnkey()// interrupt 0 using 2  
{
		if(left){addy=0;if(addx!=1)addx=-1; else addx=1;}
		if(right){addy=0;if(addx!=-1)addx=1; else addx=-1;}
		if(up){addx=0;if(addy!=-1)addy=1; else addy=-1;}
		if(down){addx=0;if(addy!=1)addy=-1; else addy=1;}
}
/*****************
????
*****************/
uchar mux(uchar temp) 
{
	if(temp==7)return 128;//0x80
	if(temp==6)return 64; //0x40
	if(temp==5)return 32; //0x20
	if(temp==4)return 16; //0x10
	if(temp==3)return 8;  //0x08
	if(temp==2)return 4;  //0x04
	if(temp==1)return 2;  //0x02
	if(temp==0)return 1;  //0x01
	return 0;
}
/*****************
????
*****************/
void timer0(uchar k)
{
	while(k--)
	{
		for(i=0;i<SNAKE+1;i++)
		{
			P0=mux(x[i]);P1=255-mux(y[i]);
			P2=0x00;
			turnkey();                     //????????
			delay(TIME);                   //????
			P0=0x00;P1=0xff;
		}
	}
} 
/*****************
???
*****************/	
void main(void)
{
	e=SPEED;
	P0=0x00;
	P2=0x00;
	P1=0xff;
	while(1)       
	{
		for(i=3;i<SNAKE+1;i++)x[i]=100;
		for(i=3;i<SNAKE+1;i++)y[i]=100;//???

		x[0]=4;y[0]=4;                                                //??                            
		n=3;                                                          //?? n=-1
		x[1]=1;y[1]=0;                                                //??
		x[2]=0;y[2]=0;                                                //??1
		addx=0;addy=0;                                                //????
		while(1)
		{
			if(keyenable)break;timer0(1);
		}

		while(1)         
		{
			timer0(e);
			if(knock()){e=SPEED;break;}                     //????

			if((x[0]==x[1]+addx)&(y[0]==y[1]+addy))         //?????
			{
				n++;
				if(n==SNAKE+1)
				{
					n=3;e=e-10;
					for(i=3;i<SNAKE+1;i++)x[i]=100;
					for(i=3;i<SNAKE+1;i++)y[i]=100;
				}
				x[0]=x[n-2];
				y[0]=y[n-2];
			}
			for(i=n-1;i>1;i--)
			{
				x[i]=x[i-1];
				y[i]=y[i-1];
			} 
			       
			x[1]=x[2]+addx;
			y[1]=y[2]+addy;                     //??
		}						
	}			
}


