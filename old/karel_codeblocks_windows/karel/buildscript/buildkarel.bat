echo Building Karel-Library...

gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\cursor.c -o .\lib\cursor.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\draw.c -o .\lib\draw.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\font.c -o .\lib\font.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\graphicsManager.c -o .\lib\graphicsManager.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\init.c -o .\lib\init.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\input.c -o .\lib\input.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\karel.c -o .\lib\karel.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\main.c -o .\lib\main.o
gcc -I"Z:\HS_Regensburg\Master\HSP Karol the Robot\karelc-Code\karel_codeblocks_windows\mingw\SDL-1.2.15\include" -c ..\world.c -o .\lib\world.o

cd lib
ar rvs libkarel.a cursor.o draw.o font.o graphicsManager.o init.o input.o karel.o main.o world.o

echo copying libs to starterprojects
copy libkarel.a ..\..\..\..\ideprojects\codeblocks_win\karel_starter_project\lib\ /Y
copy libkarel.a ..\..\..\..\ideprojects\codeblocks_win_testing\karel_starter_project\lib\ /Y
echo lib copied to codeblocks project

echo Hooray Karel-Library build succeeded...