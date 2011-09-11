/***************************************************************************
 *   Copyright (C) 1-5-2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
 */
#ifndef MAIN_H
#define MAIN_H

#include "MainWin.h"
#include <qtextedit.h>

class ListBoxItem;
class QCloseEvent;

class Main: public MainWin {
Q_OBJECT
public:
    Main(QWidget *parent = 0, const char *name = 0);
	ListBoxItem *prevLbi; // previously selected lbi

private: 
void SaveNote();
void saveNotes();
void loadNotes();
bool delNote;

protected:
virtual void closeEvent( QCloseEvent* );
	
public slots:
    virtual void btNew_clicked();
    virtual void lsNotes_selected(QListBoxItem*);
    virtual void lsNotes_highlighted(QListBoxItem*);
    virtual void txtNote_textChanged();
    virtual void btSave_clicked();
	virtual void lsNotes_onItem( QListBoxItem * );
	virtual void btDel_clicked();
	virtual void lsNotes_clicked( QListBoxItem * );
};

#endif
