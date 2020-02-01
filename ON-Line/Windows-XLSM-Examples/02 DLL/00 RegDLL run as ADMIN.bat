cd %~dp0
copy ComDuinoDLL.dll C:\Windows\system\ComDuinoDLL.dll
copy ComDuinoDLL.tlb C:\Windows\system\ComDuinoDLL.tlb
C:\Windows\Microsoft.NET\Framework\v4.0.30319\Regasm.exe ComDuinoDLL.dll /tlb: ComDuinoDLL.tlb /codebase
pause