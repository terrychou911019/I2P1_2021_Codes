#include<stdio.h>
char m[256];
char p,q,r,s;
int main(){
	scanf("%c%c%c%c%c%c%c%c%c\n",&m['1'],&m['2'],&m['3'],&m['4'],&m['5'],&m['6'],&m['7'],&m['8'],&m['9']);
	m[m['1']] = '1', m[m['2']] = '2', m[m['3']] = '3', 
	m[m['4']] = '4', m[m['5']] = '5', m[m['6']] = '6', 
	m[m['7']] = '7', m[m['8']] = '8', m[m['9']] = '9';
	scanf("%c%c%c%c",&p,&q,&r,&s);
	printf("%c%c%c%c",m[p],m[q],m[r],m[s]);
}
