#include "CommitButtonsFrame.h"

CommitButtonsFrame::CommitButtonsFrame(QWidget *parent, const bool &hasApplyButton) : QFrame(parent)
{
	setFrameStyle( QFrame::NoFrame );
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );

	mGrid = new QGridLayout(this);
	mSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
	mButtonOk = new QPushButton(tr("Ok"), this);
	mButtonCancel = new QPushButton(tr("Cancel"), this);
	hasApply = hasApplyButton;

	mGrid->addItem(mSpacer,			0,0);
	mGrid->addWidget(mButtonOk,		0,2);
	mGrid->addWidget(mButtonCancel,	1,2);

	connect( mButtonOk, SIGNAL(clicked()),
			 this,		SLOT(on_buttonOk_clicked()));

	connect( mButtonCancel, SIGNAL(clicked()),
			 this,		SLOT(on_buttonCancel_clicked()));

	if(hasApply)
	{
		mButtonApply = new QPushButton(tr("Apply"), this);
		mGrid->addWidget(mButtonApply,	0,1);
		connect( mButtonApply,	SIGNAL(clicked()),
				 this,			SLOT(on_buttonApply_clicked()));
	}

}

CommitButtonsFrame::~CommitButtonsFrame()
{
	delete mButtonOk;
	delete mButtonApply;
	delete mButtonCancel;
	delete mSpacer;
}

void CommitButtonsFrame::addApplyButton()
{
	if( !hasApply )
	{
		hasApply = true;
		mButtonApply = new QPushButton(tr("Apply"), this);
		mGrid->addWidget(mButtonApply,	0,1);
		connect( mButtonApply, SIGNAL(clicked()),
				 this,		SLOT(on_buttonApply_clicked()));
	}
}

void CommitButtonsFrame::on_buttonOk_clicked()
{
	emit sigButtonOkClicked();
}

void CommitButtonsFrame::on_buttonCancel_clicked()
{
	emit sigButtonCancelClicked();
}

void CommitButtonsFrame::on_buttonApply_clicked()
{
	if( hasApply )
		emit sigButtonApplyClicked();
}
