#include <fcntl.h>
#include <unistd.h>

int main() {
	char buf[40];
	for (int i = 0; i < 40; i++) {
		buf[i] = '\0';
	}
	int fd = open("/home/users/level05/.pass", O_RDONLY);
	read(fd, buf, 40);
	write(1, buf, 40);
}