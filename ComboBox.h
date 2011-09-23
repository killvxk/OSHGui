#ifndef __OSHGUI_COMBOBOX_H__
#define __OSHGUI_COMBOBOX_H__

#include "Event\EventHandler.h"
#include "Button.h"
#include "ScrollBar.h"

#define COMBOBOX_ITEM_HEIGHT 22
#define COMBOBOX_MAX_HEIGHT 220

namespace OSHGui
{
	/**
	 * Tritt auf, wenn sich der Wert der SelectedIndex-Eigenschaft �ndert.
	 */
	typedef EventHandler<void(Control*)> SelectedIndexChangedEvent;

	/**
	 * Stellt ein Kombinationsfeld-Steuerelement dar.
	 */
	class ComboBox : public Button
	{
	public:
		/**
		 * Konstruktor der Klasse.
		 *
		 * @param parent das Elternsteuerelement
		 */
		ComboBox(Control *parent = 0);
		virtual ~ComboBox();
		
		/**
		 * Legt die Hintergrundfarbe des DropDown-Steuerelements fest.
		 *
		 * @param color
		 */
		void SetDropDownColor(const Drawing::Color &color);
		/**
		 * Ruft die Hintergrundfarbe des DropDown-Steuerelements ab.
		 *
		 * @return color
		 */
		Drawing::Color GetDropDownColor() const;
		/**
		 * Gibt das Item an der Stelle index zur�ck.
		 *
		 * @param index
		 * @return das Item
		 */
		const Misc::UnicodeString& GetItem(int index) const;
		/**
		 * Gibt den ausgew�hlten Index zur�ck.
		 *
		 * @return der ausgew�hlte Index
		 */
		int GetSelectedIndex() const;
		/**
		 * Gibt das ausgew�hlte Item zur�ck.
		 *
		 * @return das Item
		 */
		const Misc::UnicodeString& GetSelectedItem() const;
		/**
		 * Gibt die Anzahl der Items zur�ck.
		 *
		 * @return Anzahl der Items
		 */
		int GetItemsCount() const;
		/**
		 * Ruft das SelectedIndexEvent f�r das Steuerelement ab.
		 *
		 * @return selectedIndexEvent
		 */
		SelectedIndexChangedEvent& GetSelectedIndexChangedEvent();
		
		/**
		 * �berpr�ft, ob sich der Punkt innerhalb des Steuerelements befindet.
		 *
		 * @param point
		 * @return ja / nein
		 */
		virtual bool ContainsPoint(const Drawing::Point &point) const;
		
		/**
		 * F�gt ein neues Item hinzu.
		 *
		 * @param text der Text des Items
		 * @return im Fehlerfall false
		 */
		bool AddItem(const Misc::UnicodeString &text);
		/**
		 * F�gt ein neues Item am gew�hlten Index hinzu.
		 *
		 * @param index
		 * @param text der Text des Items
		 * @return im Fehlerfall false
		 */
		bool InsertItem(int index, const Misc::UnicodeString &text);
		/**
		 * L�scht das Item am gew�hlten Index.
		 *
		 * @param index
		 * @return im Fehlerfall false
		 */
		bool RemoveItem(int index);
		/**
		 * L�scht alle Items.
		 */
		bool Clear();
		/**
		 * Selektiert ein Item.
		 *
		 * @param newIndex
		 */
		void SelectItem(int newIndex);

		/**
		 * Veranlasst das Steuerelemt seine interne Struktur neu zu berechnen.
		 * Wird au�erdem f�r alle Kindelemente aufgerufen.
		 *
		 * Sollte nicht vom Benutzer aufgerufen werden!
		 */
		virtual void Invalidate();
		
		/**
		 * Verarbeitet ein Event und gibt es wenn n�tig an Kindelemente weiter.
		 *
		 * @param event
		 * @return NextEventTypes
		 */
		virtual Event::NextEventTypes ProcessEvent(Event *event);
		/**
		 * Zeichnet das Steuerelement mithilfe des �bergebenen IRenderers.
		 *
		 * @param renderer
		 */
		virtual void Render(Drawing::IRenderer *renderer);
	
	protected:
		virtual void SetFocus(bool focus);

		ScrollBar scrollBar;
		
		int dropdownHeight;
		
		int selectedIndex,
			firstVisibleItemIndex,
			mouseOverItemIndex;
		bool open;
		
		Drawing::Rectangle dropDownRect,
						   itemsRect;
		Drawing::Color dropDownColor;
		
		std::vector<Misc::UnicodeString> items;

		SelectedIndexChangedEvent selectedIndexChangedEvent;
	};
}

#endif