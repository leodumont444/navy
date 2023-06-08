# NAVY
EPITECH first year project, part of B1-Unix System Programming : my_navy (2023)                                  
2 student - 3 weeks 

Result : **93%**

## Build :
`make`

## Run : 
`./navy boat_positions`                            
`./navy ennemy_pid boat_positions`

### Display help :
`./navy -h`

## Info about project :

**Authorized functions :** 
     *open, close, read, write, lseek, malloc, free, getpid, kill, signal,
    sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause, getline, fopen,
    fclose*

### What is it ?

The goal of the project was to recreate a terminal version of the battleship game, playable between 2 terminals on the same computer, only using SIGUSR1 and SIGUSR2.

The player must give a text file filled with his ships positions following this schema :

LENGTH : FIRST_SQUARE : LAST_SQUARE

**exemple :**

2:C1:C2                                                                   
3:D4:F4                                                                               
4:B5:B8                                            
5:D7:H7                                                       

or

2:C4:D4                                          
3:H1:H3                                            
4:E6:H6                                          
5:B1:F1                                    

Then each player will, turn by turn, choose a coordonate to nuke, and the map will be displayed.
If a player hit all ennemy's ships, he win.
