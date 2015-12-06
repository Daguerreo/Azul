#include "BaseDialog.h"

BaseDialog::BaseDialog(QWidget* parent, Mediator* mediator, bool hasApplyButton) : QDialog(parent)
{
	setWindowTitle(tr("Dialog"));
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred );
	setModal(true);

	QPalette pal = this->palette();
	QColor color = QColor(0, 175, 255);
	pal.setColor(this->backgroundRole(), color);
	this->setPalette(pal);

	mLayout = new QHBoxLayout(this);
	mSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
	mMediator = mediator;

	/*
	 * Set up the graphic view
	*/
	mGraphicsView = new QGraphicsView(this);
	mGraphicsView->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	mGraphicsView->setBackgroundBrush(QBrush(QColor(200,220,255), Qt::SolidPattern));
	mGraphicsView->setBaseSize( 320, 240 );
	mGraphicsView->setMinimumSize( 320, 240 );
	mPixmapItem = new QGraphicsPixmapItem();
	mGraphicsView->setScene(&mScene);
	mScene.addItem( mPixmapItem );

	/*
	 * Set up the options frame
	*/
	mOptionsFrame = new OptionsFrame(this);
	mCommitFrame = new CommitButtonsFrame(mOptionsFrame);
	mOptionVBox = new QVBoxLayout(mOptionsFrame);
	mOptionVBox->setAlignment(Qt::AlignTop);

	/*
	 * Add to layout
	*/
	mLayout->addWidget(mGraphicsView);
	mLayout->addWidget(mOptionsFrame);
	if( hasApplyButton )
		mCommitFrame->addApplyButton();

	/*
	 * Additional components for derivated classes
	*/
	setOptions();

	/*
	 * Connect the buttons
	*/
	connect( mCommitFrame,	SIGNAL( sigButtonOkClicked() ),
			 this,			SLOT( buttonOkClicked() ));
	connect( mCommitFrame,	SIGNAL( sigButtonCancelClicked() ),
			 this,			SLOT( buttonCancelClicked() ));
	connect( mCommitFrame,	SIGNAL( sigButtonApplyClicked() ),
			 this,			SLOT( buttonApplyClicked() ));
	connect( this,			SIGNAL( sigUpdateMainWindow() ),
			 parent,		SLOT( updateView() ));
}

BaseDialog::~BaseDialog()
{
	delete mGraphicsView;
	delete mPixmapItem;
	delete mLayout;
	delete mOptionsFrame;
	delete mCommitFrame;
	delete mOptionVBox;
}

void BaseDialog::resizeEvent(QResizeEvent *event)
{
	mGraphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

void BaseDialog::addComponent(QWidget* widget)
{
	mOptionVBox->addWidget(widget);
}

void BaseDialog::openDialog()
{
	mMediator->createWorkingCopy();
	processImage();
}

void BaseDialog::displayImage(const QImage& image)
{
	mPixmapItem->setPixmap(QPixmap::fromImage(image));
	mScene.setSceneRect(0, 0, image.width(), image.height());
	mGraphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
}

void BaseDialog::processImage()
{
	QImage image = mMediator->requestWCQImage();
	displayImage( image );
}

void BaseDialog::setOptions()
{
	mOptionVBox->addItem(mSpacer);
	addComponent(mCommitFrame);

	/*
	 * Fill in child view if component before the commit
	 * buttons are needed.
	 * Call addComponent() here
	*/
}

void BaseDialog::buttonOkClicked()
{
	mMediator->commitImage();
	emit( sigUpdateMainWindow() );
	close();
}

void BaseDialog::buttonCancelClicked()
{
	mMediator->cleanWorkingCopy();
	close();
}
void BaseDialog::buttonApplyClicked()
{
	emit( sigApplyClicked() );
}
