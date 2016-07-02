#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include <sys/time.h>
#include <math.h>
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <sys/ioctl.h>  
#include <stdlib.h>  
#include <linux/types.h>  
#include <linux/videodev2.h>  
#include <malloc.h>  
#include <math.h>  
#include <string.h>  
#include <sys/mman.h>  
#include <errno.h>  
#include <assert.h>  
#define VIDEO_DEVICE "/dev/video0"
int main()
{
	int fd;  
	int ret;
	//detail control value  

    struct v4l2_fmtdesc fmt;  

	//decive fuction, such as video input  
    struct v4l2_capability cap;  


	//get the format of video supply  
    memset(&fmt, 0, sizeof(fmt));  
    fmt.index = 0;  
    //supply to image capture  
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  


    //open video device with block  
	fd = open(VIDEO_DEVICE, O_RDONLY);  
	printf("fd is = %d\n, video0\n",fd);
	

	//枚举所有格式	
	if(ioctl(fd,VIDIOC_ENUM_FMT, &fmt)==0){
		printf("yangyi VIDIOC_ENUM_FMT\n");
	}

	
	ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);  
    if(ret < 0){  
       perror("Fail to ioctl VIDEO_QUERYCAP");  
        exit(EXIT_FAILURE);  
    } 
	return 0;
}

