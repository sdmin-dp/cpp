#include "treasure.h"
void treasure(int c,int &x,int &y) {
	for (int i=0;i<10;++i)
		for (int j=0;j<10;++j)
			if (query(i,j)==0) {
				x=i; y=j;
				return;
			}
}
