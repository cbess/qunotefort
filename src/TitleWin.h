/****************************************************************************
** Form interface generated from reading ui file 'TitleWin.ui'
**
** Created: Sat Jan 7 00:09:07 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TITLEWIN_H
#define TITLEWIN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class TitleWin : public QDialog
{
    Q_OBJECT

public:
    TitleWin( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~TitleWin();

    QPushButton* btOk;
    QPushButton* btCancel;
    QLabel* textLabel1;
    QLineEdit* leTitle;

    virtual QString ShowDia( QString str );

public slots:
    virtual void btOk_clicked();
    virtual void btCancel_clicked();

protected:
    QString title;

    QHBoxLayout* Layout1;
    QSpacerItem* Horizontal_Spacing2;

protected slots:
    virtual void languageChange();

};

#endif // TITLEWIN_H
