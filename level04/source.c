#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv, char** envp) {
	pid_t pid = fork();
	char input[128];
	memset(input, 0, 128);
	int stat_loc = 0;

	if (pid != 0) { // Parent
		while (true) {
			wait(&stat_loc);

			if (((stat_loc & 127) == 0 || (((stat_loc & 127) + 1) >> 1) > 0)) {
				puts("child is exiting...");
				break;
			}

			if (ptrace(PTRACE_PEEKUSER, pid, 44, 0) != 11) continue;

			puts("no exec() for you");
			kill(pid, SIGKILL);
			break;
		}
	} else { // Child
		prctl(PR_SET_PDEATHSIG, SIGHUP);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(input);
	}
}
