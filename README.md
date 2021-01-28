# dwm 

This is my heavily patched and customised version of the dynamic window manager (dwm)

## What is dwm 

dwm is a window manager created by the folks at [Suckless](https://suckless.org), it's created to be extremely fast and lightweight.
As with all Suckless programs you will need to modify the source code to make changes, no config files are used here.
Some of the features you would expect from a window manager are missing from the base build of dwm, luckily the community has created patches to add these features in.

## Patches used

All patches can also be found in the patches folder.

* dwm-actualfullscreen
* dwm-alpha
* dwm-anybar
* dwm-attachaside
* dwm-clientopacity
* dwm-cyclelayouts
* dwm-focusonclick
* dwm-gridmode
* dwm-restartsig
* dwm-scratchpad
* dwm-swallow 
* dwm-uselessgap

## Installing my version of dwm

Clone the repo to your pc and run ``sudo make clean install``

## Keybinds

All keybinds can be found in the config.def.h file.
