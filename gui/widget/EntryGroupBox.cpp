#include "EntryGroupBox.h"
#include <QDebug>

EntryGroupBox::EntryGroupBox(QWidget *parent, const int& numEntry) : QGroupBox(parent)
{
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid = new QGridLayout(this);

	for( int i=0; i<numEntry; i++ )
	{
		mLabelEntries.push_back( new QLabel(this) );
		mLabelEntries.at(i)->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
		mLabelEntries.at(i)->setAlignment(Qt::AlignRight);

		mLineEditEntries.push_back( new QLineEdit(this) );
		mLineEditEntries.at(i)->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
		mLineEditEntries.at(i)->setMaximumSize( 40, 90 );
	}

	setLayout(mGrid);
}

EntryGroupBox::~EntryGroupBox()
{
	delete mGrid;
	qDeleteAll(mLabelEntries);
	qDeleteAll(mLineEditEntries);
}

void EntryGroupBox::placeEntry(const int& index, const int& row, const int& col, const QString& text, const int& value)
{
	if( mLabelEntries.size() <= index )
	{
		qWarning("Warning, placeEntry index exceed size of vector");
		return;
	}

	mLabelEntries.at(index)->setText( text );
	mLineEditEntries.at(index)->setText( QString::number(value) );

	mGrid->addWidget( mLabelEntries.at(index), row, col*2 );
	mGrid->addWidget( mLineEditEntries.at(index), row, col*2+1 );
}

void EntryGroupBox::placeEntry(const int &index, const int &row, const int &col)
{
	if( mLabelEntries.size() <= index )
	{
		qWarning("Warning, placeEntry index exceed size of vector");
		return;
	}

	mGrid->addWidget( mLabelEntries.at(index), row, col*2 );
	mGrid->addWidget( mLineEditEntries.at(index), row, col*2+1 );
}

void EntryGroupBox::placeSpacer( QSpacerItem* spacer, const int &row, const int &col)
{
	mGrid->addItem( spacer, row, col );
}

int EntryGroupBox::getValue(const int& index)
{
	if( index <= mLineEditEntries.size() )
	{
		return mLineEditEntries.at(index)->text().toInt();
	}

	return 0;
}

void EntryGroupBox::setValue(const int& index, QString text)
{
	if( index <= mLineEditEntries.size())
	{
		mLineEditEntries.at(index)->setText( text );
	}
}

void EntryGroupBox::setEntryEnabled(const int& index, const bool& enabled)
{
	if( index <= mLineEditEntries.size() )
	{
		mLineEditEntries.at(index)->setEnabled( enabled );
		mLabelEntries.at(index)->setEnabled( enabled );
	}
}
