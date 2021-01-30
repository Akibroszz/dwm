/* See LICENSE file for copyright and license details. */

/* Variables */
static const char browser[] = "librewolf";
static const char terminal[] = "st";

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "Hack Nerd Font:size=10:antialias=true:autohint=true",
                                        "Mononoki Nerd Font:size=10:antialias=true:autohint=true",
                                        "Iosevka Nerd Font:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       =   "Hack Nerd Font:size=10:antialias=true:autohint=true";

static const char col_bg[]                  = "#282a36";
static const char col_fg[]                  = "#f8f8f2";
static const char col_fg_focus[]            = "#ff79c6";
static const char col_border[]              = "#44475a";
static const char col_border_focus[]        = "#ff79c6";
static const unsigned int baralpha = 0xEE;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg            bg         border   */
	[SchemeNorm] = { col_fg,       col_bg,    col_border },
	[SchemeSel]  = { col_fg_focus, col_bg,    col_border_focus  },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class               instance    title       tags mask     isfloating   monitor */
	{ "Gimp",              NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",           NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "grid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0"; 

static const char *dmenucmd[] = { "dmenu_run", "-p", "Run: ", NULL };
static const char *termcmd[]  = { terminal, NULL };
static const char *browsercmd[] = { browser, NULL };
static const char *emacscmd[] = { "emacsclient", "-c", "-a", "emacs", NULL };

static const char *raisevolumecmd[] = { "amixer", "set", "Master", "5%+", NULL };
static const char *lowervolumecmd[] = { "amixer", "set", "Master", "5%-", NULL };
static const char *muteaudiocmd[]  = { "amixer", "-D", "pulse", "set", "Master", "1+", "toggle", NULL };

static const char *raisebacklightcmd[] = { "xbacklight", "-inc", "2", NULL };
static const char *lowerbacklightcmd[] = { "xbacklight", "-dec", "2", NULL };

static const char *screenshotcmd[] = { "scrot", "'Screenshot-%Y-%m-%d-%H_%M.jpg'", "-q", "20", "&&", "mv", "$HOME/Pictures/Screenshots", NULL };

/* A menu for logging out, hibernating, shutting of, ... */
static const char *accountmanagercmd[] = { "arcolinux-logout", NULL };

/* Scratchpad */
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { terminal, "-t", scratchpadname, "-g", "120x34", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static char *statuscmds[] = { "notify-send Mouse$BUTTON" };
static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key                         function        argument */
	/* General Keys */
	{ MODKEY,                       XK_Tab,                     view,           {0} },   
	{ MODKEY,                       XK_b,                       togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_c,                       killclient,     {0} },
	{ MODKEY,                       XK_x,                       spawn,          {.v = accountmanagercmd} },
	{ MODKEY,                       XK_0,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                       tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_Return,                  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,                       quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,                       quit,           {1} }, 

	/* Layout Manipulation */
	{ MODKEY,                       XK_j,                       focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,                       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,                       setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,                       setmfact,       {.f = +0.05} },

	{ MODKEY,                       XK_t,                       setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                       setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                       setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,                       setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_f,                       togglefullscr,  {0} },

	{ MODKEY|ShiftMask,             XK_comma,                   cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                  cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,                       rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,                       rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_space,                   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                   togglefloating, {0} },

	/* MOD + Key Applications */
	{ MODKEY,                       XK_Return,                  spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_F1,                      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_F2,                      spawn,          {.v = emacscmd } },
	{ MODKEY,                       XK_s,                       togglescratch,  {.v = scratchpadcmd } },

	/* MOD + Shift + Key Applications */
	{ MODKEY|ShiftMask,             XK_Return,                  spawn,          {.v = dmenucmd } },

	/* Audio */
	{ 0,                            XF86XK_AudioMute,		    spawn,	        {.v = muteaudiocmd } },	
	{ 0,                            XF86XK_AudioRaiseVolume,	spawn,		    {.v = raisevolumecmd } },
	{ 0,                            XF86XK_AudioLowerVolume,	spawn,		    {.v = lowervolumecmd } },

	/* Backlight */
	{ 0,                            XF86XK_MonBrightnessUp,	    spawn,          {.v = raisebacklightcmd} },
	{ 0,                            XF86XK_MonBrightnessDown,	spawn,          {.v = lowerbacklightcmd} },

	/* Screenshots */
	{ 0,                            XK_Print,                   spawn,          {.v = screenshotcmd } },


	/* Switching between monitors */
	{ MODKEY,                       XK_comma,                   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                  tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                                       0)
	TAGKEYS(                        XK_2,                                       1)
	TAGKEYS(                        XK_3,                                       2)
	TAGKEYS(                        XK_4,                                       3)
	TAGKEYS(                        XK_5,                                       4)
	TAGKEYS(                        XK_6,                                       5)
	TAGKEYS(                        XK_7,                                       6)
	TAGKEYS(                        XK_8,                                       7)
	TAGKEYS(                        XK_9,                                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

