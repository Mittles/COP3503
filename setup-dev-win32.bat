@ECHO OFF
ECHO WAIT FOR WINDOW TO CLOSE
ECHO DOWNLOADING CODEBLOCKS
ECHO IF YOU HAVE OTHER VERSIONS OF CODEBLOCKS INSTALLED PLEASE REMOVE THEM NOW
powershell -ExecutionPolicy Unrestricted -File setup-dev.ps1
MKDIR bin
MKDIR bin\Debug
COPY lib\SDL2\bin\SDL2.dll bin\Debug
COPY lib\SDL2\bin\SDL2_image.dll bin\Debug
codeblocks.exe
