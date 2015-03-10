##http://serverfault.com/questions/18872/how-to-zip-unzip-files-in-powershell
$shell_app=new-object -com shell.application
$filename = "win32_lib.zip"
$zip_file = $shell_app.namespace((Get-Location).Path + "\$filename")
$destination = $shell_app.namespace((Get-Location).Path)
$destination.Copyhere($zip_file.items())
##unrelated
$client = new-object System.Net.WebClient
$client.DownloadFile("http://iweb.dl.sourceforge.net/project/codeblocks/Binaries/13.12/Windows/codeblocks-13.12mingw-setup-TDM-GCC-481.exe","codeblocks.exe")