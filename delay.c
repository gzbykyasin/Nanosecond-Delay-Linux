#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int nsleep(long miliseconds)
{
   struct timespec req, rem;

   if(miliseconds > 999)
   {   
        req.tv_sec = (int)(miliseconds / 1000);                            /* Must be Non-Negative */
        req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
   }   
   else
   {   
        req.tv_sec = 0;                         /* Must be Non-Negative */
        req.tv_nsec = miliseconds * 1;    /* Must be in range of 0 to 999999999 */
   }   

   return nanosleep(&req , &rem);
}

int main()
{
	struct timeval currentTime;
	printf("timer baslangic\n");
        gettimeofday(&currentTime,NULL);
	printf("%ld\n",currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);
	nsleep(2);
	gettimeofday(&currentTime,NULL);
        printf("%ld\n",currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);
	printf("Nanosleep successfull \n");
	return 0;
}

