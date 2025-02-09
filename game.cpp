#include<iostream>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include"help.h"
#include<fstream>
using namespace std;


// Board Printing Function.
void printBoard( int data [][8] )
{
	//myRectangle(0,0,2000,1500,0,130,255,0,130,255);
	//THE MAIN GRID
	myRectangle(400,100,1200,900,255,255,255,0,0,0);
	//HORIZONTAL LINES
	myLine(400,200,1200,200,255);
	myLine(400,300,1200,300,255);
	myLine(400,400,1200,400,255);
	myLine(400,500,1200,500,255);
	myLine(400,600,1200,600,255);
	myLine(400,700,1200,700,255);
	myLine(400,800,1200,800,255);
	//VERTICAL LINES	
	myLine(500,100,500,900,255);
	myLine(600,100,600,900,255);
	myLine(700,100,700,900,255);
	myLine(800,100,800,900,255);
	myLine(900,100,900,900,255);
	myLine(1000,100,1000,900,255);
	myLine(1100,100,1100,900,255);

	//TO DISPLAY THE INTERNAL SHAPES
	for(int i = 0, y = 120 ; i < 8 ; i++ , y = y+100)
	{
		for(int j = 0 , x = 420 ; j < 8 ; j++ , x = x+100)
		{
			if ( data[i][j] == 0 )
			{
				myRectangle( x+2 , y , x+70 , y+50 , 255, 204, 153 , 255, 204, 153 );
			}
			else if( data[i][j] == 1 )
			{
				myEllipse( x , y , x+60 , y+60 , 0 , 0 , 155, 0, 0, 102 );
			}
			else if( data[i][j] == 2 )
			{
				myEllipse( x , y , x+70 , y+45 , 255, 255, 0, 204, 204, 0 );
			}
			else if( data[i][j] == 3 )
			{
				myRectangle ( x , y , x+60 , y+60 , 0 , 153 , 0 , 0 , 102 , 0 );
			}
			else if( data[i][j] == 4 )
			{
				tri ( x , y , x+60 , y+60 , 255 , 0 , 127, 51 , 0 , 25 );
			} 
			else if (data[i][j] == 5 )
			{
				myRectangle( x+2 , y , x+70 , y+50 , 255, 204, 153 , 255, 0, 0 );
			}
			else if (data[i][j] == 6 )
			{
				myEllipse( x , y , x+60 , y+60 , 0 , 0 , 155,  255, 0, 0 );
			}
			else if (data[i][j] == 7 )
			{
				myEllipse( x , y , x+70 , y+45 , 255, 255, 0,  255, 0, 0 );
			}
			else if (data[i][j] == 8 )
			{
				myRectangle ( x , y , x+60 , y+60 , 0 , 153 , 0 ,  255, 0, 0 );
			}
			else if (data[i][j] == 9 )
			{
				tri ( x , y , x+60 , y+60 , 255 , 0 , 127, 0 , 0 , 255 );
			}
		}
	}

}

//Re-Printing of Shapes
void singleimage(int num, int row, int col)
{
	int x=420+row*100, y=120+col*100;
	if ( num == 0 )
	{
		myRectangle(x-20,y-20,x+80,y+80,255,255,255,0,0,0);
		myRectangle( x+2 , y , x+70 , y+50 , 255, 204, 153 , 255, 204, 153 );
	}
	else if( num == 1 )
	{
		myRectangle(x-20,y-20,x+80,y+80,255,255,255,0,0,0);
		myEllipse(x , y , x+60 , y+60 , 0 , 0 , 155, 0, 0, 102);
	}
	else if( num == 2 )
	{
		myRectangle(x-20,y-20,x+80,y+80,255,255,255,0,0,0);
		myEllipse(x , y , x+70 , y+45 , 255, 255, 0, 204, 204, 0);
	}
	else if( num == 3 )
	{
		myRectangle(x-20,y-20,x+80,y+80,255,255,255,0,0,0);
		myRectangle ( x , y , x+60 , y+60 , 0 , 153 , 0 , 0 , 102 , 0 );
	}
	else if( num == 4 )
	{
		myRectangle(x-20,y-20,x+80,y+80,255,255,255,0,0,0);
		tri ( x , y , x+60 , y+60 , 255 , 0 , 127, 51 , 0 , 25 );
	}  
}


bool FoundFive(int d[][8])
{
	int flag=0;
	for (int i=0; i<8 && flag==0 ; i++)
	{
		for(int j=0; j<4 ; j++)
		{
			if((d[i][j]==d[i][j+1] && d[i][j]==d[i][j+2]  && d[i][j]==d[i][j+3]  && d[i][j]==d[i][j+4]) || (d[i][j]==d[i+1][j] && d[i][j]==d[i+2][j] && d[i][j]==d[i+3][j] && d[i][j]==d[i+4][j]))
			{
				flag=1;
			}

		}
	}

	if(flag==1)
		return true;
	else
		return false;
}

bool FoundF(int d[][8])
{
	int flag=0;
	for (int i=0; i<8 && flag==0 ; i++)
	{
		for(int j=0; j<5 ; j++)
		{
			if((d[i][j]==d[i][j+1] && d[i][j]==d[i][j+2]  && d[i][j]==d[i][j+3]) || (d[i][j]==d[i+1][j] && d[i][j]==d[i+2][j] && d[i][j]==d[i+3][j]))
			{
				flag=1;
			}

		}
	}

	if(flag==1)
		return true;
	else
		return false;
}

bool Found(int d[][8])
{
	int flag=0;
	for (int i=0; i<8 && flag==0 ; i++)
	{
		for(int j=0; j<6 ; j++)
		{
			if((d[i][j]==d[i][j+1] && d[i][j]==d[i][j+2]) || (d[i][j]==d[i+1][j] && d[i][j]==d[i+2][j]))
			{
				flag=1;
			}

		}
	}

	if(flag==1)
		return true;
	else
		return false;
}




int main() 
{
	int data[8][8];
	int score=0;
	float timer=400;
	int x = 420 , y = 120 ;
	int m=1;
	int x1=400,x2=500,y1=100,y2=200;
	srand(time(0));
	cout<<"---------------PLEASE RUN THE GAME IN FULL SCREEN---------------"<<endl;
	cout<<"PRESS 1 TO START THE GAME :) " <<endl;
	cin>>m;


	// display the name of game
			//background
    myRectangle(0,0,2000,1500,0,130,255,0,130,255);
	//inner rectangle
	myRectangle(200,200,1300,500,255,0,0,255,0,0);
	//writting G
	myRectangle(250,450,280,250,0,0,0,0,0,0);
	myRectangle(250,450,350,420,0,0,0,0,0,0);
	myRectangle(250,250,350,280,0,0,0,0,0,0);
	myRectangle(320,450,350,370,0,0,0,0,0,0);
	myRectangle(300,395,350,370,0,0,0,0,0,0);
	//writing E
	myRectangle(360,450,390,250,0,0,0,0,0,0);
	myRectangle(390,450,450,420,0,0,0,0,0,0);
	myRectangle(390,250,450,280,0,0,0,0,0,0);
	myRectangle(390,360,450,330,0,0,0,0,0,0);

	//writing M
	myRectangle(470,450,500,250,0,0,0,0,0,0);
	myRectangle(500,250,570,280,0,0,0,0,0,0);
	myRectangle(570,450,540,250,0,0,0,0,0,0);
	myRectangle(570,250,640,280,0,0,0,0,0,0);
	myRectangle(610,450,640,250,0,0,0,0,0,0);



	//writing G
	myRectangle(700,450,800,420,0,0,0,0,0,0);
	myRectangle(700,250,800,280,0,0,0,0,0,0);
	myRectangle(700,450,730,250,0,0,0,0,0,0);
	myRectangle(770,450,800,370,0,0,0,0,0,0);
	myRectangle(750,395,800,370,0,0,0,0,0,0);
	//writing A
	myRectangle(810,450,840,250,0,0,0,0,0,0);
	myRectangle(910,450,940,250,0,0,0,0,0,0);
	myRectangle(810,250,940,280,0,0,0,0,0,0);
	myRectangle(810,360,940,330,0,0,0,0,0,0);

	
	//writing M
	myRectangle(470+490,450,500+490,250,0,0,0,0,0,0);
	myRectangle(500+490,250,570+490,280,0,0,0,0,0,0);
	myRectangle(570+490,450,540+490,250,0,0,0,0,0,0);
	myRectangle(570+490,250,640+490,280,0,0,0,0,0,0);
	myRectangle(610+490,450,640+490,250,0,0,0,0,0,0);
		//writing E
	myRectangle(360+790,450,390+790,250,0,0,0,0,0,0);
	myRectangle(390+790,450,450+790,420,0,0,0,0,0,0);
	myRectangle(390+790,250,450+790,280,0,0,0,0,0,0);
	myRectangle(390+790,360,450+790,330,0,0,0,0,0,0);

	Sleep(5000);


	// display of loading
	myRectangle(0,0,2000,1500,0,130,255,0,130,255);
	//inner rectangle
	myRectangle(200,200,1150,500,255,0,0,255,0,0);
	//writting L
	myRectangle(250,450,280,250,0,0,0,0,0,0);
	myRectangle(250,450,350,420,0,0,0,0,0,0);
	//writing O
	myRectangle(360,450,390,250,0,0,0,0,0,0);
	myRectangle(390,450,450,420,0,0,0,0,0,0);
	myRectangle(390,250,450,280,0,0,0,0,0,0);
	myRectangle(420,450,450,250,0,0,0,0,0,0);
	//writing A
	myRectangle(470,450,500,250,0,0,0,0,0,0);
	myRectangle(500,250,570,280,0,0,0,0,0,0);
	myRectangle(570,450,540,250,0,0,0,0,0,0);
	myRectangle(500,360,570,330,0,0,0,0,0,0);
	//writing D
	myRectangle(580,450,610,250,0,0,0,0,0,0);
	myRectangle(610,450,660,420,0,0,0,0,0,0);
	myRectangle(610,250,660,280,0,0,0,0,0,0);
	myRectangle(660,450,690,250,0,0,0,0,0,0);
	//writing I
	myRectangle(700,450,800,420,0,0,0,0,0,0);
	myRectangle(700,250,800,280,0,0,0,0,0,0);
	myRectangle(735,450,765,250,0,0,0,0,0,0);
	//writing N
	myRectangle(810,450,840,250,0,0,0,0,0,0);
	myRectangle(910,450,940,250,0,0,0,0,0,0);
	myLine(830,262,910,435,30);
	
	//writing G
	myRectangle(960,450,990,250,0,0,0,0,0,0);
	myRectangle(960,450,1070,420,0,0,0,0,0,0);
	myRectangle(960,250,1070,280,0,0,0,0,0,0);
	myRectangle(1040,450,1070,370,0,0,0,0,0,0);
	myRectangle(1020,395,1070,370,0,0,0,0,0,0);
	Sleep(5000);
	
	
	if(m=1)
		system("cls");


	

	for(int i = 0 ; i < 8 ; i++)
	{
		for(int j = 0 ; j < 8 ; j++)
		{
			data[i][j] = rand() % 5;
		}
	}
	myRectangleMove(400,60,990,80,255,255,255);
	printBoard(data);
	myRectangleMove(400,100,500,200,255,0,0);
	int b=0;
	while(Found(data)==1 || b==0) 
	{
		b=1;
		for(int  i= 0 ; i < 8; i++)
		{
			for(int  j = 0; j < 6 ; j++)
			{
				if(data[i][j] == data[i][j+1] && data[i][j] == data[i][j+2])
				{
					for(int  k = 0; k < 3 ; k++)
					{
						j = j + k;
						if (k == 2)
							j--;
						int x3=400+ j*100 ,y3=100+i*100 ;
						myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
						data[i][j] =10;
					}	
				}
			}
		}
		for(int i=0 ; i < 8 ; i++)
		{
			for ( int j=0 ; j< 8 ; j++)
			{
				if(data[i][j]==10)
				{
					data[i][j] = rand() % 5;
					singleimage(data[i][j],j,i);
				}
			}
		}
		for(int  i= 0 ; i < 8; i++)
		{
			for(int  j = 0; j < 6 ; j++)
			{
				if(data[i][j] == data[i+1][j] && data[i][j] == data[i+2][j])
				{
					for(int  k = 0; k < 3 ; k++)
					{
						i = i + k;
						if (k == 2)
							i--;
						int x3=400+ j*100 ,y3=100+i*100 ;
						myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
						data[i][j] =10;
					}
				}
			}
		}
		for(int i=0 ; i < 8 ; i++)
		{
			for ( int j=0 ; j< 8 ; j++)
			{
				if(data[i][j]==10)
				{
					data[i][j] = rand() % 5;
					singleimage(data[i][j],j,i);
				}
			}
		}

	}


	cout<<"\n\n\n\n\n\n";
	int n=1,row=0,col=0,a=0;
	while(timer!=1000)
	{
		myRectangle(400,60,timer,80,0,255,0,255,255,255);
		timer=timer+5;
		cout<<"\r   The Score Is :"<<score;
		int whichKey;  
		whichKey=0;	
		a=0;
		_getch();	
		isCursorKeyPressed(whichKey);
		if(whichKey==1 && x1 > 450)
		{
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			x1-=100;
			x2-=100;
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			myRectangleMove(x1+100,y1,x2+100,y2,255,255,255);
			col--;

		}
		else if(whichKey==2 && y1 > 150 )
		{
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			y1-=100;
			y2-=100;
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			myRectangleMove(x1,y1+100,x2,y2+100,255,255,255);
			row--;
		}
		else if(whichKey==3 && x2 < 1150)
		{
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			x1+=100;
			x2+=100;
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			myRectangleMove(x1-100,y1,x2-100,y2,255,255,255);
			col++;
		}
		else if(whichKey==4 && y2 < 850)
		{
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			y1+=100;
			y2+=100;
			myRectangleMove(x1,y1,x2,y2,255,0,0);
			myRectangleMove(x1,y1-100,x2,y2-100,255,255,255);
			row++;
		}

		else if(whichKey==5)
		{
			while(a==0)
			{
				if(isCursorKeyPressed(whichKey))
				{
					if(whichKey==3 && x1 < 1100)
					{
						swap(data[row][col],data[row][col+1]);
						singleimage(data[row][col], col, row);
						singleimage(data[row][col+1], col+1, row);
					}
					else if(whichKey==1 && x1 > 400)
					{
						swap(data[row][col],data[row][col-1]);
						singleimage(data[row][col], col, row);
						singleimage(data[row][col-1], col-1, row);
					}
					else if(whichKey==2 && y1 > 100)
					{
						swap(data[row][col],data[row-1][col]);
						singleimage(data[row][col], col, row);
						singleimage(data[row-1][col], col, row-1);
					}
					else if(whichKey==4 && y1 < 800) 
					{
						swap(data[row][col],data[row+1][col]);
						singleimage(data[row][col], col, row);
						singleimage(data[row+1][col], col, row+1);
					}
					a=1;

					// Printing the word of score and box.
					int p = 0;
					myRectangle(0, 90, 340, 160, 255, 0, 0, 0, 0, 0);
					myLine(7 + p, 5, 22 + p, 5, 255);
					myLine(27 + p, 35, 27 + p, 50, 255);
					myLine(7 + p, 55, 22 + p, 55, 255);
					myLine(2 + p, 10, 2 + p, 25, 255);
					myLine(7 + p, 30, 22 + p, 30, 255);
					p = p + 40;
					myLine(7 + p, 5, 22 + p, 5, 255);
					myLine(7 + p, 55, 22 + p, 55, 255);
					myLine(2 + p, 35, 2 + p, 50, 255);
					myLine(2 + p, 10, 2 + p, 25, 255);
					p = p + 40;
					myLine(7 + p, 5, 22 + p, 5, 255);
					myLine(27 + p, 10, 27 + p, 25, 255);
					myLine(27 + p, 35, 27 + p, 50, 255);
					myLine(7 + p, 55, 22 + p, 55, 255);
					myLine(2 + p, 35, 2 + p, 50, 255);
					myLine(2 + p, 10, 2 + p, 25, 255);
					p = p + 40;
					myLine(7 + p, 5, 22 + p, 5, 255);
					myLine(2 + p, 35, 2 + p, 50, 255);
					myLine(2 + p, 10, 2 + p, 25, 255);
					p = p + 40;
					myLine(7 + p, 5, 22 + p, 5, 255);
					myLine(7 + p, 55, 22 + p, 55, 255);
					myLine(2 + p, 35, 2 + p, 50, 255);
					myLine(2 + p, 10, 2 + p, 25, 255);
					myLine(7 + p, 30, 22 + p, 30, 255);
					p = p + 40;
	
					_getch();
					
//					// handling 5
//					int d=0;
//					while(FoundFive(data)==1 ||  d==0) 
//					{
//						d=1;
//						for(int  i= 0 ; i < 8; i++)
//						{
//							for(int  j = 0; j < 4 ; j++)
//							{
//								if(data[i][j] == data[i][j+1] && data[i][j] == data[i][j+2] &&  data[i][j] == data[i][j+3]  &&  data[i][j] == data[i][j+4])
//								{
//									for(int  k = 0; k < 5 ; k++)
//									{
//										j = j + k;
//										if (k == 2)
//											j--;
//										int x3=400+ j*100 ,y3=100+i*100 ;
//										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
//										data[i][j] =10;
//									}	
//									score=score+50;
//								}
//							}
//						}
//						for(int i=0 ; i < 8 ; i++)
//						{
//							for ( int j=0 ; j< 8 ; j++)
//							{
//								if(data[i][j]==10)
//								{
//									data[i][j] = rand() % 5;
//									singleimage(data[i][j],j,i);
//								}
//							}
//						}
//						for(int  i= 0 ; i < 3; i++)
//						{
//							for(int  j = 0; j < 8 ; j++)
//							{
//								if(data[i][j] == data[i+1][j] && data[i][j] == data[i+2][j] && data[i][j] == data[i+3][j] && data[i][j] == data[i+4][j])
//								{
//									for(int  k = 0; k < 5 ; k++)
//									{
//										i = i + k;
//										if (k == 2)
//											i--;
//										int x3=400+ j*100 ,y3=100+i*100 ;
//										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
//										data[i][j] =10;
//									}	
//									score=score+25;
//								}
//							}
//						}
//						for(int i=0 ; i < 8 ; i++)
//						{
//							for ( int j=0 ; j< 8 ; j++)
//							{
//								if(data[i][j]==10)
//								{
//									data[i][j] = rand() % 5;
//									singleimage(data[i][j],j,i);
//								}
//							}
//						}
//
//					}
//
//					//handlig 4
//
					/*int c=0;
					while(FoundF(data)==1 ||  c==0) 
					{
						c=1;
						for(int  i= 0 ; i < 8; i++)
						{
							for(int  j = 0; j < 4 ; j++)
							{
								if(data[i][j] == data[i][j+1] && data[i][j] == data[i][j+2] &&  data[i][j] == data[i][j+3])
								{
									data[i][j+3]=6;
									for(int  k = 0; k < 3 ; k++)
									{
										j = j + k;
										if (k == 2)
											j--;
										int x3=400+ j*100 ,y3=100+i*100 ;
										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
										data[i][j] =10;
									}	
									score=score+25;
								}
							}
						}
						for(int i=0 ; i < 8 ; i++)
						{
							for ( int j=0 ; j< 8 ; j++)
							{
								if(data[i][j+3]==10)
								{
									data[i][j] = rand() % 5;
									singleimage(data[i][j],j,i);
									
								}
								
							}
						}
						for(int  i= 0 ; i < 4; i++)
						{
							for(int  j = 0; j < 8 ; j++)
							{
								if(data[i][j] == data[i+1][j] && data[i][j] == data[i+2][j] && data[i][j] == data[i+3][j])
								{
									data[i+3][j] =6;
									for(int  k = 0; k < 3 ; k++)
									{
										i = i + k;
										if (k == 2)
											i--;
										int x3=400+ j*100 ,y3=100+i*100 ;
										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
										data[i][j] =10;
									}	
									score=score+25;
								}
							}
						}
						for(int i=0 ; i < 8 ; i++)
						{
							for ( int j=0 ; j< 8 ; j++)
							{
								if(data[i][j]==10)
								{
									data[i][j] = rand() % 5;								
									singleimage(data[i][j],j,i);
								}
								
							}
						}

					}*/
					//handling 3
					int b=0;
					while(Found(data)==1 ||  b==0) 
					{
						b=1;
						for(int  i= 0 ; i < 8; i++)
						{
							for(int  j = 0; j < 6 ; j++)
							{
								if(data[i][j] == data[i][j+1] && data[i][j] == data[i][j+2])
								{
									for(int  k = 0; k < 3 ; k++)
									{
										j = j + k;
										if (k == 2)
											j--;
										int x3=400+ j*100 ,y3=100+i*100 ;
										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
										data[i][j] =10;
									}	
									score=score+10;
								}
							}
						}
						for(int i=0 ; i < 8 ; i++)
						{
							for ( int j=0 ; j< 8 ; j++)
							{
								if(data[i][j]==10)
								{
									data[i][j] = rand() % 5;
									singleimage(data[i][j],j,i);
								}
							}
						}
						for(int  i= 0 ; i < 6; i++)
						{
							for(int  j = 0; j < 8 ; j++)
							{
								if(data[i][j] == data[i+1][j] && data[i][j] == data[i+2][j])
								{
									for(int  k = 0; k < 3 ; k++)
									{
										i = i + k;
										if (k == 2)
											i--;
										int x3=400+ j*100 ,y3=100+i*100 ;
										myRectangle(x3,y3,x3+100,y3+100,255,255,255,0,0,0);
										data[i][j] =10;
									}	
									score=score+10;
								}
							}
						}
						for(int i=0 ; i < 8 ; i++)
						{
							for ( int j=0 ; j< 8 ; j++)
							{
								if(data[i][j]==10)
								{
									data[i][j] = rand() % 5;
									singleimage(data[i][j],j,i);
								}
							}
						}

					}
				}
			}
		}
		Sleep(100);
	}
	system("cls");
	/*cout<<"you are out of moves please try again ";*/
	// display GAME OVER
			//background
    myRectangle(0,0,2000,1500,0,130,255,0,130,255);
	//inner rectangle
	myRectangle(200,200,1300,500,255,0,0,255,0,0);
	



	/*background*/
	myRectangle(0,0,2000,1500,0,130,255,0,130,255);
	//inner rectangle
	myRectangle(200,200,1400,500,255,0,0,255,0,0);
	//writing G
	myRectangle(700-450,450,800-450,420,0,0,0,0,0,0);
	myRectangle(700-450,250,800-450,280,0,0,0,0,0,0);
	myRectangle(700-450,450,730-450,250,0,0,0,0,0,0);
	myRectangle(770-450,450,800-450,370,0,0,0,0,0,0);
	myRectangle(750-450,395,800-450,370,0,0,0,0,0,0);
	//writing A
	myRectangle(810-450,450,840-450,250,0,0,0,0,0,0);
	myRectangle(910-450,450,940-450,250,0,0,0,0,0,0);
	myRectangle(810-450,250,940-450,280,0,0,0,0,0,0);
	myRectangle(810-450,360,940-450,330,0,0,0,0,0,0);

	
	//writing M
	myRectangle(470+490-450,450,500+490-450,250,0,0,0,0,0,0);
	myRectangle(500+490-450,250,570+490-450,280,0,0,0,0,0,0);
	myRectangle(570+490-450,450,540+490-450,250,0,0,0,0,0,0);
	myRectangle(570+490-450,250,640+490-450,280,0,0,0,0,0,0);
	myRectangle(610+490-450,450,640+490-450,250,0,0,0,0,0,0);
		//writing E
	myRectangle(360+790-450,450,390+790-450,250,0,0,0,0,0,0);
	myRectangle(390+790-450,450,450+790-450,420,0,0,0,0,0,0);
	myRectangle(390+790-450,250,450+790-450,280,0,0,0,0,0,0);
	myRectangle(390+790-450,360,450+790-450,330,0,0,0,0,0,0);

	//writing O
	myRectangle(360+470,450,390+470,250,0,0,0,0,0,0);
	myRectangle(390+470,450,450+470,420,0,0,0,0,0,0);
	myRectangle(390+470,250,450+470,280,0,0,0,0,0,0);
	myRectangle(420+470,450,450+470,250,0,0,0,0,0,0);

	//writing O
	myRectangle(360+460+120,450,390+460+120,250,0,0,0,0,0,0);
	myRectangle(390+460+120,450,450+460+120,420,0,0,0,0,0,0);
	myRectangle(420+460+120,450,450+460+120,250,0,0,0,0,0,0);

		//writing V
	myRectangle(360+340+350,450,390+340+350,250,0,0,0,0,0,0);
	myRectangle(390+340+350,450,450+340+350,420,0,0,0,0,0,0);
	myRectangle(390+340+350,250,450+340+350,280,0,0,0,0,0,0);
	myRectangle(390+340+350,360,450+340+350,330,0,0,0,0,0,0);

	//writing R
	myRectangle(360+340+350+110,450,390+340+350+110,250,0,0,0,0,0,0);
	
	myRectangle(390+340+350+110,250,450+340+350+110,280,0,0,0,0,0,0);
	myRectangle(390+340+350+110,360,450+340+350+110,330,0,0,0,0,0,0);
	myRectangle(1220,360,1250,250,0,0,0,0,0,0);

	Sleep(20000);

	


	_getch();
	system("pause");
	return 0;
}