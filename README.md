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
* dwm-rotatestack
* dwm-scratchpad
* dwm-swallow (not installed due to errors)
* dwm-systray (not installed due to errors)
* dwm-uselessgap

## Installing my version of dwm

Clone the repo to your pc and run ``sudo make clean install``

## Keybinds

All keybinds can be found in the config.def.h file.

Here are some of the more imporant ones:

| Modifier    | Key               | Action                                      |
|-------------|-------------------|---------------------------------------------|
| Mod         | Enter             | Spawn terminal (default st)                 |
| Mod & Shift | Enter             | Spawn application launcher (default dmenu)  |
| Mod         | F1                | Spawm browser (default librewolf)           |
| Mod         | F2                | Spawn emacs                                 |
| Mod & Shift | C                 | Kill client                                 |
| Mod         | 1-9               | Move to workspace                           |
| Mod         | J-K               | Move to next/previous client                |
| Mod         | H-L               | Increase/decrease client size               |
| Mod         | I-D               | Increase/decrease amount of slots in master |
| Mod & Shift | J-K               | Rotate the stack                            |
| Mod & Shift | Comma, Period     | Cycle layout                                |
| Mod         | T                 | Set to Tiled layout                         |
| Mod         | F                 | Set to Floating layout                      |
| Mod         | M                 | Set to Monocle layout                       |
| Mod         | G                 | Set to Grid layout                          |
| Mod & Shift | F                 | Set to Fullscreen layout                    |
| Mod & Shift | Q                 | Quit dwm                                    |
| Mod & Shift | R                 | Restart dwm                                 |
| Mod         | Space             | Set client to Tiled                         |
| Mod & Shift | Space             | Set client to Floating                      |
| None        | Raise/Lower Audio | Raise/lower audio (default using amixer)    |
| None        | Mute Audio        | Mutes the audio (default using amixer)      |
| None        | Print             | Take a screenshot (default using scrot)     |
| Mod         | B                 | Toggle bar                                  |
