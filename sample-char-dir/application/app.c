#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "../sampleioctl.h"

int main()
{
	struct calc dat;
	int opt;
	int fd, err=0;
	
	fd = open("/dev/samplechar", O_RDWR);
	if(fd < 0)
	{
		perror("open:");
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
		scanf("%d", &dat.data1);

		printf("\n Enter Data2:");
		scanf("%d", &dat.data2);

		switch(opt)
		{
			case 1:
				err=ioctl(fd, SAMPLE_IOCTL_ADD, &dat);
				break;

			case 2:
				err=ioctl(fd, SAMPLE_IOCTL_SUB, &dat);
				break;
			case 3:
				err=ioctl(fd, SAMPLE_IOCTL_MUL, &dat);
				break;
			case 4:
				err= ioctl(fd, SAMPLE_IOCTL_DIV, &dat);
				break;
		}
			printf("\n Result is :%d", dat.result);
	}

	close(fd);
	return 0;
}
