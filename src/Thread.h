/***************************************************************************
 *   Copyright (C) 1-7-06 2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
 */

#include <qthread.h>

class Thread : public QThread {
public:
Thread() : QThread() { }

protected:
virtual void run()
{ }

public:
static void sleep( unsigned long sec )
{
	sleep( sec );
} // end

}; // end CLASS