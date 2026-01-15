#include "pzd.h"
unsigned long long yyjy = 0,yyzy[66]={0};

void pjyj(unsigned long long DengJi, unsigned long long BAG0) {
//	std::cout << "pjyj\n";
	return;
	unsigned long long jy = 0;
	while (DengJi) {
		jy += DengJi * DengJi;
		DengJi--;
	}
//	std::cout << jy+BAG0 << " " << yyjy;
//	getch();
	if (jy + BAG0 != yyjy) {
		pdzrecg;
	}
}
void pbz(long long BAG[]){
	return;
//	std::cout << "pbz\n";
	for (int i=1;i<15;i++){
		if (BAG[i]!=yyzy[i]){
			pdzrecg;
		}
	}
}
void htree(){
//	resizewindow(1547,660);
	initgraph(1547, 660, 0);
//	initgraph(930, 660, 0);
	PIMAGE p = newimage();
	getimage(p, "tree.png");
//	getch();
//	putimage(0, 0, 1547, 1000, p, 0, 0, 1547, 1000);
	putimage(0, 0, 1547, 660, p, 0, 0, 1547, 660);
	usleep(20);
	for (int i = 0; i + 660 <= 7614; i++) {
//		putimage(0, 0, 1547, 1000, p, 0, i, 1547, 1000);
		putimage(0, 0, 1547, 660, p, 0, i, 1547, 660);
		usleep(20);
	}
//	getch();
}
void tztree(){
	htree();
}