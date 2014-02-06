#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "../mylib.h"

int main()
{
	int data1, data2;
	int opt;
	int err=0;

	err = OpenDev();
	if(err < 0)
	{
		printf("\n open: Error in file open... ");
		return -1;
	}

	while(1)
	{
		printf("\n 1.Add\n2.Sub\n3.Mul\n4.Div\n \
				5.ExitApp\nChoose Operation:" );
		scanf("%d", &opt);

		if(opt == 5)
			break;

		if(opt < 1 || opt > 4)
		{
			printf("\n Invalid Option... ");
			continue;
		}
		
		printf("\n Enter Data1:");
		scanf("%d", &data1);
		printf("\n Enter Data2:");
		scanf("%d", &data2);

		switch(opt)
		{
			case 1:
			err = Add(data1, data2);
			break;
			case 2:
			err=Sub(data1, data2);
			break;
			case 3:
			err= Mul(data1, data2);
			break;
			case 4:
			err= Div(data1, data2);
			break;
		}
		printf("\n Result is :%d", err);
	}

	CloseDev();
	return 0;
}
