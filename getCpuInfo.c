
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

float get_cpu_clock_speed()
{
	FILE *fp;
	char buffer[BUFF_SIZE];
    size_t bytes_read;
	char *match;
	float clock_speed;

	fp = fopen("/proc/cpuinfo", "r");
	bytes_read = fread(buffer, 1, sizeof(buffer), fp);
	fclose(fp);

	if (bytes_read == 0 || bytes_read == sizeof(buffer)) {
		return 0;
	}

	buffer[bytes_read] = '\0';
	match = strstr(buffer, "cpu MHz");
	if (match == NULL) {
		return 0;
	}
	sscanf(match, "cpu MHz : %f", &clock_speed);
	return clock_speed;
}

int main(int argc, char *argv[])
{
    printf("CPU clock speed : %4.0f MHz\n", get_cpu_clock_speed());
    return 0;
}


