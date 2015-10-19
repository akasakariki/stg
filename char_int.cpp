#include "main.h"

long char_int(char moji)
{
	long k=0;
	switch(moji)
	{
	case '0':
		k=0;
		break;
	case '1':
		k=1;
		break;
	case '2':
		k=2;
		break;
	case '3':
		k=3;
		break;
	case '4':
		k=4;
		break;
	case '5':
		k=5;
		break;
	case '6':
		k=6;
		break;
	case '7':
		k=7;
		break;
	case '8':
		k=8;
		break;
	case '9':
		k=9;
		break;
	case 'a':
		k=10;
		break;
	case 'b':
		k=11;
		break;
	case 'c':
		k=12;
		break;
	case 'd':
		k=13;
		break;
	case 'e':
		k=14;
		break;
	case 'f':
		k=15;
		break;
	case 'g':
		k=16;
		break;
	case 'h':
		k=17;
		break;
	case 'i':
		k=18;
		break;
	case 'j':
		k=19;
		break;
	case 'k':
		k=20;
		break;
	case 'l':
		k=21;
		break;
	case 'm':
		k=22;
		break;
	case 'n':
		k=23;
		break;
	case 'o':
		k=24;
		break;
	case 'p':
		k=25;
		break;
	case 'q':
		k=26;
		break;
	case 'r':
		k=27;
		break;
	case 's':
		k=28;
		break;
	case 't':
		k=29;
		break;
	case 'u':
		k=30;
		break;
	case 'v':
		k=31;
		break;
	case 'w':
		k=32;
		break;
	case 'x':
		k=33;
		break;
	case 'y':
		k=34;
		break;
	case 'z':
		k=35;
		break;
	case '<':
		k=50;
		break;
	case '>':
		k=60;
		break;
	case'=':
		k=70;
		break;
	case'+':
		k=80;
		break;
	case'-':
		k=90;
		break;
	default:
		k=100;
	}
	return k;
}