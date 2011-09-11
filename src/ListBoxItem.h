/***************************************************************************
 *   Copyright (C) 1-5-2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
- implement static instance variable
 */
#ifndef _LBI_H
#define _LBI_H

#include <qlistbox.h>

class QPainter;

class ListBoxItem : public QListBoxText {
public:
 ListBoxItem( QString title, QString noteText = QString::null );

QString NoteText(); // get note text
void NoteText( QString ntText ); // set note text

QString Title(); // get note title
void Title( QString title ); // set note title text

void repaint( QPainter paint );

int ID();

protected:

QString noteText;
QString title;

private:
static int _id;

}; // END CLASS ListBoxItem
#endif