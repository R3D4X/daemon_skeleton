#include "deamon.h"

int
main()
{
	int res;
	int ttl=120;
	int delay=5;
	if( (res=daemonize("time-deamon","/tmp",NULL,NULL,NULL)) != 0 ) 
	{
		fprintf(stderr,"error: daemonize failed\n");
		exit(EXIT_FAILURE);
	}
	while( ttl>0 ) 
	{
		//daemon code here
		syslog(LOG_NOTICE,"daemon ttl %d",ttl);
		sleep(delay);
		ttl-=delay;
	}
	syslog(LOG_NOTICE,"daemon ttl expired");
	closelog();
	return(EXIT_SUCCESS);
}
