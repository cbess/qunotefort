/****************************************************************************
** Form interface generated from reading ui file 'MainWin.ui'
**
** Created: Sat Jan 7 02:03:56 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINWIN_H
#define MAINWIN_H

#include <qvariant.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QPushButton;
class QListBox;
class QListBoxItem;
class QTextEdit;

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~MainWin();

    QPushButton* btHide;
    QPushButton* btNew;
    QPushButton* btDel;
    QPushButton* btSave;
    QListBox* lsNotes;
    QTextEdit* txtNote;

public slots:
    virtual void btNew_clicked();
    virtual void lsNotes_selected( QListBoxItem * );
    virtual void lsNotes_highlighted( QListBoxItem * );
    virtual void btSave_clicked();
    virtual void txtNote_textChanged();
    virtual void lsNotes_onItem( QListBoxItem * );
    virtual void btDel_clicked();
    virtual void lsNotes_clicked( QListBoxItem * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // MAINWIN_H
