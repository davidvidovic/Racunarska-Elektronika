#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <wiringPi.h>

// Kompajlirati sa:
// gcc -o z2 z2.c -lwiringPi -lwiringPiDev
// i pokrenuti ga sa: 
// ./z2 xxxxxxx yy.yyy
// gde je xxxxxxx jedinstveni ID senzora
// yy.yyy zeljeni temperaturni prag (decimalna mesta su opciona)

int main(int argc, char *argv[])
{
	int fd = -1, ret;
	char *tmp1, tmp2[10], ch='t';
	char devname_head[50] = "/sys/devices/w1_bus_master1/28-00000";
	char devname_end[10] = "/w1_slave";
	char dev_name[100];
	double value;
	char buffer[100];

	strcpy(dev_name, devname_head);
	strcat(dev_name, argv[1]);
	strcat(dev_name, devname_end);
	
	// Ucitavanje praga prosledjenog kao argument
	double threshold = atof(argv[2]);
	
	printf("Postavljeni prag je %.3f\n", threshold);
	
	// Dioda 25 output
	pinMode(25, OUTPUT);
	
	while(1)
	{
		// Otvaranje i citanje iz fajla fajla
		if ((fd = open(dev_name, O_RDONLY)) < 0)
		{
			perror("Greška pri otvaranju!");
			exit(1);
		}
		
		ret = read(fd, buffer, sizeof(buffer));
		
		if (ret < 0)
		{
			perror("Greška pri čitanju!");
			exit(1);
		}
		
		close(fd);
		
		// Smestanje procitanog stringa u promenjivu
		tmp1 = strchr(buffer, ch);
		// Izdvajanje temperature iz stringa
		sscanf(tmp1, "t=%s", tmp2);
		// Obrada temperature u pozeljni format
		value = atof(tmp2);
		value = value / 1000;
		printf("Temperatura je %.3f\n", value);
		
		if(value >= threshold) {
			printf("ALARM\n");
			digitalWrite(25, 1);
			delay(200);
			digitalWrite(25, 0);
			delay(200);
		}
		else digitalWrite(25, 0);
		
		delay(100);
	}
	
	return 0;
}
