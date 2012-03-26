/*
 * OldSchoolHack GUI
 *
 * Copyright (c) 2012 KN4CK3R http://www.oldschoolhack.de
 *
 * See license in OSHGui.hpp
 */

#ifndef OSHGUI_EVENT_KEYEVENTARGS_HPP
#define OSHGUI_EVENT_KEYEVENTARGS_HPP

#include "Misc/Strings.hpp"
#include "KeyboardMessage.hpp"

namespace OSHGui
{
	/**
	 * Stellt Daten f�r das KeyUpEvent/KeyDownEvent bereit.
	 */
	class OSHGUI_EXPORT KeyEventArgs
	{
	public:
		Key::Keys KeyCode;
		Misc::AnsiChar KeyChar;
		Key::Keys Modifier;
		bool Handled;
		
	public:
		/**
		 * Konstruktor der Klasse
		 *
		 * @param keyboardEvent
		 */
		KeyEventArgs(const KeyboardMessage &keyboardEvent)
		{
			KeyCode = keyboardEvent.KeyCode;
			KeyChar = keyboardEvent.KeyChar;
			Modifier = keyboardEvent.Modifier;
			Handled = false;
		}
	};
}

#endif