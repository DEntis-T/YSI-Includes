/*----------------------------------------------------------------------------*\
					===========================
					 foreach efficient looping
					===========================
Description:
	Provides efficient looping through sparse data sets, such as connected
	players.  Significantly improved from the original version to be a generic
	loop system, rather then purely a player loop system.  When used for
	players this has constant time O(n) for number of connected players (n),
	unlike standard player loops which are O(MAX_PLAYERS), regardless of the
	actual number of connected players.  Even when n is MAX_PLAYERS this is
	still faster.
Legal:
	Version: MPL 1.1
	The contents of this file are subject to the Mozilla Public License Version
	1.1 (the "License"); you may not use this file except in compliance with
	the License. You may obtain a copy of the License at
	http://www.mozilla.org/MPL/
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	The Original Code is the YSI foreach include.
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2011
	the Initial Developer. All Rights Reserved.
	Contributors:
		ZeeX, koolk, JoeBullet/Google63, g_aSlice/Slice
	Thanks:
		JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	Very special thanks to:
		Thiadmer - PAWN, whose limits continue to amaze me!
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
Version:
	0.4
Changelog:
	28/04/11:
		Moved iterator identifiers to end of variables.
		Rewrote "foreach" to accept two syntaxes for "foreach (new i : Iter)".
	16/08/10:
		Removed all the "2" versions of the functions.
	14/08/10:
		Added Iter_Clear to reset an array.
	06/08/10:
		Added special array declaration format.
	18/12/09:
		Added Itter_Func2 functions for multi-dimensional iterators.
		Renamed foreact et al as keywords in the documentation.
		Changed licensing from GPL to MPL.
	02/09/09:
		Fixed (again) for 0.3.
		Added free slot finding.
	21/08/09:
		Updated to include random functions.
		Made entirely stand alone.
		Ported to 0.3 (separate version).
		Added automatic callback hook code.
		Removed debug information from stand alone version.
	06/01/08:
		Added debug information.
	09/10/07:
		Moved to system.
	16/09/07:
		Added list sorting.
		Made this part of Y SeRver Includes, not Y Sever Includes.
		Made list sorting optional.
		Fixed version number.
	08/09/07:
		First version.
Functions:
	Public:
		OnPlayerDisconnect - Called when a player leaves to remove them.
		OnPlayerConnect - Called when a player connects to add them.
	Core:
		-
	Stock:
		Itter_ShowArray - Displays the contents of the array.
		Itter_AddInternal - Add a value to an itterator.
		Itter_RemoveInternal - Remove a value from an itterator.
		Itter_RandomInternal - Get a random item from an itterator.
		Itter_FreeInternal - Gets the first free slot in the itterator.
		Itter_InitInternal - Initialises a multi-dimensional itterator.
	Static:
		-
	Inline:
		Itter_Create - Create a new itterator value set.
		Itter_Add - Wraps Itter_AddInternal.
		Itter_Remove - Wraps Itter_RemoveInternal.
		Itter_Random - Wraps Itter_RandomInternal.
		Itter_Count - Gets the number of items in an itterator.
		Itter_Debug - Wraps around Itter_ShowArray.
		Itter_Free - Wraps around Itter_FreeInternal.
		Itter_Create2 - Create a new itterator array value set.
		Itter_Add2 - Wraps Itter_AddInternal for arrays.
		Itter_Remove2 - Wraps Itter_RemoveInternal for arrays.
		Itter_Random2 - Wraps Itter_RandomInternal for arrays.
		Itter_Count2 - Gets the number of items in an itterator array.
		Itter_Debug2 - Wraps around Itter_ShowArray for arrays.
		Itter_Free2 - Wraps around Itter_FreeInternal for arrays.
	API:
		-
Callbacks:
	-
Hooks:
	Itter_OnPlayerConnect - Hook for the OnPlayerConnect callback.
	Itter_OnPlayerDisconnect - Hook for the OnPlayerDisconnect callback.
	Itter_OnGameModeInit - Only exists to make the code compile correctly...
Definitions:
	-
Enums:
	-
Macros:
	-
Keywords:
	foreach - Command to loop an iterator.
	foreachex - Like foreach but without a new variable.
	foreach2 - Command to loop through an iterator array.
	foreachex - Like foreach2 but without a new variable.
Tags:
	Iterator - Declare an iterator.
Variables:
	Global:
		-
	Static:
		YSI_g_OPC - Records wether Itter_OnPlayerConnect exists for speed.
		YSI_g_OPDC - Records wether Itter_OnPlayerDisconnect exists for speed.
Commands:
	-
Compile options:
	YSI_ITTER_NO_SORT - Removed.
	FOREACH_NO_BOTS - Remove the bot iterators for smaller code.
	FOREACH_NO_PLAYERS - Remove all default code for player itteration.
Operators:
	-
Iterators:
	Player - List of all players connected.
	Bot - List of all bots (npcs) connected.
	NPC - Alias of Bot.
	Character - All players and bots.
\*----------------------------------------------------------------------------*/

#if defined _y_foreach_included

#endinput

#endif

#define _y_foreach_included

#include "y_iterate"