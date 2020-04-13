# AssaultCube-ESP-Hack

# AssaultCube-DirectX-GDI-Overlay
Simple proof of concept on how to draw to an overlay through the use of GDI in Assault Cube.

- WHAT IS THIS:
  - This small hack finds players on the game map and draws a distance from one self to the enemy.
    ![alt text](https://github.com/Ctrl-Alt-1337/AssaultCube-GDI-ESP-Overlay/blob/master/screenshot.jpg)

- HOW TO RUN THE HACK:
  - If using Visual Studio then Right Click on the project -> Properties
    - -> Advanced -> Character Set -> Make sure you use 'Use Multi-Byte Character Set'
  - Build the hack (platform: Win32)
  - Enter AssaultCube
  - Start the hack
  
- OTHER RELEVANT INFO:
	- Base address and offsets for entities (names, positions, health etc.) are found through OllyDbg and Cheat Engine.
  - Relevant WinAPI functions: ```FindWindowA```, ```GetWindowThreadProcessId```, ```OpenProcess```, ```ReadProcessMemory```

- CREDITS:
	- WorldToScreen: Guidedhacking.com
  
- DISCLAIMER:
  - Run this in singleplayer mode ONLY. This hack should never be used to ruin the game for other players. This serves solely as a purpose for learning and to better understand the workings of memory forensics and the WinAPI.

