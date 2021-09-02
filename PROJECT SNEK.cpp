#include <iostream>                              
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include <fcntl.h>
#include <io.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading(int x, int y)
{
	int r = 1;
	for (int i = 0; i < 3; i++)
	{
		//39,10
		int e = y + 1;
		gotoxy(x, e);
		SetConsoleTextAttribute(hConsole, r);
		wcout << "*";
		Sleep(200);
		r++;
		int u = y + 2;
		int f = x + 2;
		gotoxy(f, u);
		SetConsoleTextAttribute(hConsole, r);
		wcout << "*";
		Sleep(200);
		r++;


		int d = x - 2;
		gotoxy(d, u);
		SetConsoleTextAttribute(hConsole, r);
		wcout << "*";
		Sleep(200);
		r++;
		int u2 = u + 1;
		gotoxy(x, u2);
		SetConsoleTextAttribute(hConsole, r);
		wcout << "*";
		Sleep(200);
		r++;

		SetConsoleTextAttribute(hConsole, 7);
	}
}
struct point
{
	int x;
	int y;
};
void displaybox()
{
	//Changes color	(0 for background color) (2 for text color)
	int x = 0;
	int y = 0;
	SetConsoleTextAttribute(hConsole, 8);
	for (x; x <= 49; x++)
	{

		gotoxy(x, y);


		wcout << L"\u2588";

	}
	x = 0;
	y = 0;
	for (y = 1; y <= 19; y++)
	{
		gotoxy(x, y);
		wcout << L"\u2588";//L"
	}
	x = 49;
	y = 0;
	for (y = 1; y <= 19; y++)
	{
		gotoxy(x, y);
		wcout << L"\u2588";
	}
	x = 0;
	y = 19;
	for (x = 1; x < 49; x++)
	{
		gotoxy(x, y);
		wcout << L"\u2588";
	}
	wcout << endl;

}  // 50,19
void displaysnek(point p[], int size)
{
	for (int i = 0; i < size; i++)
	{
		SetConsoleTextAttribute(hConsole, 2);
		gotoxy(p[i].x, p[i].y);
		if (i == 0)
		{
			wcout << L"\u263B";

		}
		else
		{


			wcout << L"\u25CF";
		}


	}
	SetConsoleTextAttribute(hConsole, 7);
}
int chkhitsnek(point p[],int size)
{
	int j = 0, x, y;                       //x= 11,12 11 13  
									 //y= 11 11 11 11
	for (int i = 1;i <= size - 1;i++)
	{
		
		if (p[i].x == p[0].x && p[i].y ==p[0].y)
		{
			j++;
		}
	}
	if (j > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void remsnek(point p[], int size)
{
	for (int i = 0; i < size; i++)
	{
		gotoxy(p[i].x, p[i].y);
		wcout << " ";
	}
}
void hdc(point p[])
{
	p[0].x = 19;
	p[1].x = 20;
	p[2].x = 21;
	p[3].x = 22;

	p[0].y = 9;
	p[1].y = 9;
	p[2].y = 9;
	p[3].y = 9;

	//p[0].x = 22;
	//p[1].x = 22;
	//p[2].x = 22;
	//p[3].x = 22;

	//p[0].y = 9;
	//p[1].y = 10;
	//p[2].y = 11;
	//p[3].y = 12;

}
void moveup(point p[], int size)
{
	int i;
	for (i = size; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].y = p[i].y - 1;
}
void movedn(point p[], int size)
{
	int i;
	for (i = size; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].y = p[i].y + 1;
}
void movelft(point p[], int size)
{
	int i;
	for (i = size; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].x = p[i].x - 1;
}
void movert(point p[], int size)
{
	int i;
	for (i = size; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].x = p[i].x + 1;
}
int checkwalls(point p[])
{
	if (p[0].x < 1)
	{
		return true;
	}
	else if (p[0].x >= 49)
	{
		return true;
	}
	else if (p[0].y <= 1)
	{
		return true;
	}
	else if (p[0].y > 18)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int isfound(point p[], point q)
{
	if (p[0].x == q.x && p[0].y == q.y)
	{
		return 0;
	}

}
int isfoundpl(point p[], point h[], int n, int n1) //*******
{
	for (int i = n; i < n1; i++)
	{
		if (p[0].x == h[i].x && p[0].y == h[i].y)
		{
			return 0;

		}
	}
}
int isfoundpl2(point p, point h[], int n, int n1)
{
	for (int i = n; i < n1; i++)
	{
		if (p.x == h[i].x && p.y == h[i].y)
		{
			return 0;

		}
	}
}
void hdch(point h[])
{
	h[0].x = 19;
	h[1].x = 20;
	h[2].x = 21;
	h[3].x = 22;
	h[4].x = 23;
	h[5].x = 24;
	h[6].x = 25;
	h[7].x = 26;
	h[8].x = 27;
	h[9].x = 28;
	h[10].x = 29;
	h[11].x = 30;
	h[12].x = 31;

	h[0].y = 7;
	h[1].y = 7;
	h[2].y = 7;
	h[3].y = 7;
	h[4].y = 7;
	h[5].y = 7;
	h[6].y = 7;
	h[7].y = 7;
	h[8].y = 7;
	h[9].y = 7;
	h[10].y = 7;
	h[11].y = 7;
	h[12].y = 7;





}
void hdch2(point h[])
{
	h[0].x = 19;
	h[1].x = 20;
	h[2].x = 21;
	h[3].x = 22;
	h[4].x = 23;
	h[5].x = 24;
	h[6].x = 25;
	h[7].x = 26;
	h[8].x = 27;
	h[9].x = 28;
	h[10].x = 29;
	h[11].x = 30;
	h[12].x = 31;

	h[0].y = 13;
	h[1].y = 13;
	h[2].y = 13;
	h[3].y = 13;
	h[4].y = 13;
	h[5].y = 13;
	h[6].y = 13;
	h[7].y = 13;
	h[8].y = 13;
	h[9].y = 13;
	h[10].y = 13;
	h[11].y = 13;
	h[12].y = 13;
}
void M2HTR(point h[])
{
	h[0].x = 35;
	h[1].x = 36;
	h[2].x = 37;
	h[3].x = 38;
	h[4].x = 39;
	h[5].x = 40;
	h[6].x = 41;

	h[7].x = 41;
	h[8].x = 41;
	h[9].x = 41;



	h[0].y = 4;
	h[1].y = 4;
	h[2].y = 4;
	h[3].y = 4;
	h[4].y = 4;
	h[5].y = 4;
	h[6].y = 4;

	h[7].y = 5;
	h[8].y = 6;
	h[9].y = 7;

}
void M2HDR(point h[])
{

	h[0].x = 41;
	h[1].x = 41;
	h[2].x = 41;
	h[3].x = 41;

	h[4].x = 35;
	h[5].x = 36;
	h[6].x = 37;
	h[7].x = 38;
	h[8].x = 39;
	h[9].x = 40;


	h[0].y = 13;
	h[1].y = 14;
	h[2].y = 15;
	h[3].y = 16;

	h[4].y = 16;
	h[5].y = 16;
	h[6].y = 16;
	h[7].y = 16;
	h[8].y = 16;
	h[9].y = 16;

}
void M2HDL(point h[])
{
	h[0].x = 10;
	h[1].x = 11;
	h[2].x = 12;
	h[3].x = 13;
	h[4].x = 14;
	h[5].x = 15;
	h[6].x = 16;

	h[7].x = 10;
	h[8].x = 10;
	h[9].x = 10;


	h[0].y = 16;
	h[1].y = 16;
	h[2].y = 16;
	h[3].y = 16;
	h[4].y = 16;
	h[5].y = 16;
	h[6].y = 16;

	h[7].y = 13;
	h[8].y = 14;
	h[9].y = 15;

}
void M2HTL(point h[])
{

	h[0].x = 10;
	h[1].x = 10;
	h[2].x = 10;

	h[3].x = 10;
	h[4].x = 11;
	h[5].x = 12;
	h[6].x = 13;
	h[7].x = 14;
	h[8].x = 15;
	h[9].x = 16;



	h[0].y = 4;
	h[1].y = 5;
	h[2].y = 6;
	h[3].y = 7;

	h[4].y = 4;
	h[5].y = 4;
	h[6].y = 4;
	h[7].y = 4;
	h[8].y = 4;
	h[9].y = 4;

}
int randx()
{
	for (int i = 0; i < 50; i++)
	{
		int number = rand() % 50;
		if (number == 0 || number == 1)
		{
			return number + 2;
		}
		return number;
	}
}
int randy()
{
	for (int i = 0; i < 19; i++)
	{
		int number = rand() % 19;
		if (number == 0 || number == 1)
		{
			return number + 2;
		}
		return number;
	}
}
void letters()
{
	SetConsoleTextAttribute(hConsole, 11);
	wcout << "________________________________________________________________________________________________________" << endl;
	wcout << "   SSS      N     N         A        K   K   EEEEEE        GGGG          A        M         M   EEEEEE    " << endl;
	wcout << "  S    S    N N   N        A A       K  K    E            G    G        A A       M M     M M   E    " << endl;
	wcout << "   S        N  N  N       A   A      K K     E            G            A   A      M  M   M  M   E   " << endl;
	wcout << "     S      N   N N      AAAAAAA     KK      EEEE         G           AAAAAAA     M    M    M   EEEE       " << endl;
	wcout << "  S     S   N    NN     A       A    K  K    E            G  GGG     A       A    M         M   E      " << endl;
	wcout << "    SSS     N     N    A         A   K   K   EEEEEE        GGG G    A         A   M         M   EEEEEE       " << endl;
	wcout << "_________________________________________________________________________________________________________" << endl;
	SetConsoleTextAttribute(hConsole, 23);
}
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);//sets cout mode to unicode 
	int map = 2;
	point p[100]; //snake    
	point q; //fruit
	point h[100]; //hurdle 1
	point h2[100];//hurdle 2
	point mh1[100];//map 2 hur1
	point mh2[100];//map 2 hur2
	point mh3[100];//map 2 hur3
	point mh4[100];//map 2 hur4
	int size = 4, n = 0, dot = 0, score = 0, ui = 0, size2 = 0, hur = 0, level;
	int snkclr = 0;

	letters();
	Sleep(1000);
	gotoxy(40, 8);
	wcout << "LOADING.......";
	for (int i = 0; i < 2; i++)
	{
		loading(45, 9);
	}
	system("cls");
x:
	gotoxy(39, 7);
	SetConsoleTextAttribute(hConsole, 8);
	wcout << "Press 1 to start the game " << endl;
	gotoxy(39, 8);
	wcout << "Press 2 to see the controls " << endl;
	gotoxy(39, 9);
	SetConsoleTextAttribute(hConsole, 7);
	cin >> ui;
	system("cls");

	if (ui == 1)
	{
		SetConsoleTextAttribute(hConsole, 2);
		gotoxy(39, 6);
		wcout << "Enter 1 if you are a beginner (no hurdles & slow speed)" << endl;
		gotoxy(39, 7);
		SetConsoleTextAttribute(hConsole, 4);
		wcout << "Enter 2 if you are a expert  (hurdles & FAST speed)" << endl;
		gotoxy(39, 8);
		SetConsoleTextAttribute(hConsole, 7);
		cin >> level;

		system("cls");
		if (level == 1)
		{
			int speed = 180;

			hdc(p);

			displaysnek(p, size);
			displaybox();
			q.x = randx();
			q.y = randy();
			gotoxy(q.x, q.y);
			SetConsoleTextAttribute(hConsole, 3);
			wcout << L"\u2666";
			SetConsoleTextAttribute(hConsole, 15);
			for (int i = 0;; i++)
			{
				if (_kbhit())
				{

					n = _getch();
					n = _getch();
				ax:
					if (dot > 0)
					{
						q.x = randx();
						q.y = randy();
						int c1 = isfoundpl2(q, h, 0, 13);
						int c2 = isfoundpl2(q, h2, 0, 13);
						if (c1 == 0 || c2 == 0 )
						{
							q.x = q.x + 1;
							q.y = q.y + 1;
						}
						gotoxy(q.x, q.y);
						SetConsoleTextAttribute(hConsole, 3);
						wcout << L"\u2666";
						SetConsoleTextAttribute(hConsole, 15);

						gotoxy(66, 11);
						wcout << "SCORE IS " << score;
					}
					dot = 0;

					if (n == 72)//up
					{
						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}

							if (checkwalls(p))
							{
								goto az;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							moveup(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto az;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 80)
								{
									goto ax;
								}
							}
						}

					}
					else if (n == 80)//down
					{
						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}

							if (checkwalls(p))
							{
								goto az;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movedn(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto az;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 72)
								{
									goto ax;
								}

							}
						}
					}
					else if (n == 77)//right
					{

						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}

							if (checkwalls(p))
							{
								goto az;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movert(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto az;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 75)
								{
									goto ax;
								}
							}
						}

					}
					else if (n == 75)//left
					{

						for (int i = 0; ; i++)
						{


							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}

							if (checkwalls(p))
							{
								goto az;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movelft(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto az;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 77)
								{
									goto ax;
								}
							}
						}
					}
					else
					{
					az:
						wcout << "\a";
						break;
					}


				}

			}
			system("color 04");
			gotoxy(66, 7);
			wcout << "GAME OVER " << endl;
			gotoxy(66, 11);
			wcout << "SCORE IS " << score;
			gotoxy(80, 7);
			SetConsoleTextAttribute(hConsole, 3);
			wcout << "MADE BY";
			gotoxy(80, 8);
			wcout << "ENTER YOUR NAME";
			gotoxy(80, 9);
			SetConsoleTextAttribute(hConsole, 7);
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
		}
		if (level == 2)
		{
			system("cls");
			gotoxy(39, 6);
			wcout << "PLEASE SELECT MAP";
			gotoxy(39, 7);
			wcout << "PRESS 1 TO SELECT FIRST MAP";
			gotoxy(39, 8);
			wcout << "PRESS 2 TO SELECT SECOND MAP";
			gotoxy(39, 10);
			cin >> map;
			system("cls");
			int speed = 100;
			hdc(p);//snake
			hdch(h);//hurdl  1 hrdcd
			if (map == 1)
			{

				for (int i = 0; i < 13; i++)
				{

					gotoxy(h[i].x, h[i].y);
					SetConsoleTextAttribute(hConsole, 12);//changes clr to red
					wcout << L"\u2588";

				}//print 1st line
				hdch2(h2);//hr2 hrdcde
				for (int i = 0; i < 13; i++)
				{
					gotoxy(h2[i].x, h2[i].y);
					SetConsoleTextAttribute(hConsole, 12);
					wcout << L"\u2588";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			if (map == 2)
			{
				M2HTR(mh1);//putting hurdle 1 vlaues in mh1
				for (int i = 0; i < 10; i++)
				{

					gotoxy(mh1[i].x, mh1[i].y);
					SetConsoleTextAttribute(hConsole, 12);//changes clr to red
					wcout << L"\u2588";

				}
				M2HDR(mh2);
				for (int i = 0; i < 10; i++)
				{
					gotoxy(mh2[i].x, mh2[i].y);
					SetConsoleTextAttribute(hConsole, 12);
					wcout << L"\u2588";
					SetConsoleTextAttribute(hConsole, 15);
				}
				M2HTL(mh3);
				for (int i = 0; i < 10; i++)
				{
					gotoxy(mh3[i].x, mh3[i].y);
					SetConsoleTextAttribute(hConsole, 12);
					wcout << L"\u2588";
					SetConsoleTextAttribute(hConsole, 15);
				}
				M2HDL(mh4);
				for (int i = 0; i < 10; i++)
				{
					gotoxy(mh4[i].x, mh4[i].y);
					SetConsoleTextAttribute(hConsole, 12);
					wcout << L"\u2588";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			displaysnek(p, size);
			displaybox();
			q.x = randx();
			q.y = randy();
			gotoxy(q.x, q.y);
			SetConsoleTextAttribute(hConsole, 3);
			wcout << L"\u2666";
			SetConsoleTextAttribute(hConsole, 15);
			for (int i = 0;; i++)
			{
				if (_kbhit())
				{

					n = _getch();
					n = _getch();
				ac:
				
					if (dot > 0)//prints new friut
					{
						q.x = randx();
						q.y = randy();
						//fruit no print on hurdle
						
						int c3 = isfoundpl2(q, mh1, 0, 10);
						int c4 = isfoundpl2(q, mh2, 0, 10);
						int c5 = isfoundpl2(q, mh3, 0, 10);
						int c6 = isfoundpl2(q, mh4, 0, 10);
						if (c3 == 0 ||c4 == 0 ||c5 == 0 ||c6 == 0)
						{
							q.x = q.x + 1;
							q.y = q.y + 1;
						}
						gotoxy(q.x, q.y);
						SetConsoleTextAttribute(hConsole, 3);
						wcout << L"\u2666";
						SetConsoleTextAttribute(hConsole, 15);

						gotoxy(66, 11);
						wcout << "SCORE IS " << score;
					}
					dot = 0;

					if (n == 72)//up
					{
						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
								
							}
							if (map == 1)
							{
								int d = isfoundpl(p, h, 0, 13);
								if (d == 0)
								{
									goto ab;
								}
								int y = isfoundpl(p, h2, 0, 13);
								if (y == 0)
								{
									goto ab;
								}
							}
							if (map == 2)
							{
								int mho = isfoundpl(p, mh1, 0, 10);
								if (mho == 0)
								{
									goto ab;
								}
								int mht = isfoundpl(p, mh2, 0, 10);
								if (mht == 0)
								{
									goto ab;
								}
								int mhth = isfoundpl(p, mh3, 0, 10);
								if (mhth == 0)
								{
									goto ab;
								}
								int mhf = isfoundpl(p, mh4, 0, 10);
								if (mhf == 0)
								{
									goto ab;
								}
							}
							if (checkwalls(p))
							{
								goto ab;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							moveup(p, size);
							displaysnek(p, size);
							if (chkhitsnek(p, size))
							{
								goto ab;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 80)
								{
									goto ac;
								}
							}
						}

					}
					else if (n == 80)//down
					{
						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}
							if (map == 1)
							{
								int d = isfoundpl(p, h, 0, 13);
								if (d == 0)
								{
									goto ab;
								}
								int y = isfoundpl(p, h2, 0, 13);
								if (y == 0)
								{
									goto ab;
								}
							}
							if (map == 2)
							{
								int mho = isfoundpl(p, mh1, 0, 10);
								if (mho == 0)
								{
									goto ab;
								}
								int mht = isfoundpl(p, mh2, 0, 10);
								if (mht == 0)
								{
									goto ab;
								}
								int mhth = isfoundpl(p, mh3, 0, 10);
								if (mhth == 0)
								{
									goto ab;
								}
								int mhf = isfoundpl(p, mh4, 0, 10);
								if (mhf == 0)
								{
									goto ab;
								}

							}
							if (checkwalls(p))
							{
								goto ab;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movedn(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto ab;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 72)
								{
									goto ac;
								}

							}
						}
					}
					else if (n == 77)//right
					{

						for (int i = 0; ; i++)
						{

							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}
							if (map == 1)
							{
								int d = isfoundpl(p, h, 0, 13);
								if (d == 0)
								{
									goto ab;
								}
								int y = isfoundpl(p, h2, 0, 13);
								if (y == 0)
								{
									goto ab;
								}
							}
							if (map == 2)
							{
								int mho = isfoundpl(p, mh1, 0, 10);
								if (mho == 0)
								{
									goto ab;
								}
								int mht = isfoundpl(p, mh2, 0, 10);
								if (mht == 0)
								{
									goto ab;
								}
								int mhth = isfoundpl(p, mh3, 0, 10);
								if (mhth == 0)
								{
									goto ab;
								}
								int mhf = isfoundpl(p, mh4, 0, 10);
								if (mhf == 0)
								{
									goto ab;
								}
							}
							if (checkwalls(p))
							{
								goto ab;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movert(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto ab;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 75)
								{
									goto ac;
								}
							}
						}

					}
					else if (n == 75)//left
					{

						for (int i = 0; ; i++)
						{


							int c = isfound(p, q);
							if (c == 0)
							{
								size++;
								dot++;
								score++;
							}
							if (map == 1)
							{
								int d = isfoundpl(p, h, 0, 13);
								if (d == 0)
								{
									goto ab;
								}
								int y = isfoundpl(p, h2, 0, 13);
								if (y == 0)
								{
									goto ab;
								}
							}
							if (map == 2)
							{
								int mho = isfoundpl(p, mh1, 0, 10);
								if (mho == 0)
								{
									goto ab;
								}
								int mht = isfoundpl(p, mh2, 0, 10);
								if (mht == 0)
								{
									goto ab;
								}
								int mhth = isfoundpl(p, mh3, 0, 10);
								if (mhth == 0)
								{
									goto ab;
								}
								int mhf = isfoundpl(p, mh4, 0, 10);
								if (mhf == 0)
								{
									goto ab;
								}
							}
							if (checkwalls(p))
							{
								goto ab;
							}
							displaysnek(p, size);
							Sleep(speed);
							remsnek(p, size);
							movelft(p, size);
							displaysnek(p, size);

							if (chkhitsnek(p, size))
							{
								goto ab;
							}
							if (_kbhit())
							{
								n = 0;
								n = _getch();
								n = _getch();
								if (n != 77)
								{
									goto ac;
								}
							}
						}
					}
					else
					{
					ab:
						wcout << "\a";//sound
						break;
					}


				}

			}

			system("color 04");
			gotoxy(66, 7);
			wcout << "GAME OVER " << endl;
			gotoxy(66, 11);
			wcout << "TOTAL SCORE IS " << score;
			gotoxy(80, 7);
			SetConsoleTextAttribute(hConsole, 3);
			wcout << "MADE BY";
			gotoxy(80, 8);
			wcout << "ENTER YOUR NAME";
			gotoxy(80, 9);
			SetConsoleTextAttribute(hConsole, 7);
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;
			wcout << endl;

		}
		
	}
	if (ui == 2)

	{
		system("cls");
		int ui2 = 0;
		gotoxy(39, 10);
		SetConsoleTextAttribute(hConsole, 8);
		wcout << L"\u2191" << " to move up ";
		gotoxy(39, 11);

		wcout << L"\u2193" << " to move down ";
		gotoxy(39, 12);
		wcout << L"\u2190" << " to move left ";
		gotoxy(39, 13);
		wcout << L"\u2192" << " to move right ";
		gotoxy(39, 14);
		wcout << "\n                                       press 1 to return to main menu \n";
		gotoxy(39, 15);
		wcout << "\n                                       press 2 to end program \n";
		gotoxy(39, 17);
		SetConsoleTextAttribute(hConsole, 7);
		cin >> ui2;
		if (ui2 == 1)
		{
			system("cls");
			goto x;
		}
		if (ui2 == 1)
		{
			exit(1);
		}
}

}
