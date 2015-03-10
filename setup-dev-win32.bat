@ECHO OFF
ECHO WAIT FOR WINDOW TO CLOSE
ECHO DOWNLOADING GITHUB CLIENT FOR WINDOWS AND CODEBLOCKS
powershell -ExecutionPolicy Unrestricted -File setup-dev.ps1
codeblocks.exe
MKDIR Debug
COPY SDL2\bin\SDL2.dll Debug