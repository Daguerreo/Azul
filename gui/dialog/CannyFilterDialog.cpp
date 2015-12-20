#include "CannyFilterDialog.h"

CannyFilterDialog::CannyFilterDialog(QWidget *parent, Controller *controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Canny Edge Detector Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	QSpacerItem* spacer = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
	mThreshBox = new EntryGroupBox( this, 2 );
	mThreshBox->setTitle("Threshold");
	mThreshBox->placeEntry( 0, 0, 0, "Low Value", 50);
	mThreshBox->placeEntry( 1, 1, 0, "High Value", 150);
	mThreshBox->placeSpacer( spacer, 0, 2);

	setOptions();
}

CannyFilterDialog::~CannyFilterDialog()
{
	delete mThreshBox;
}

void CannyFilterDialog::setOptions()
{
	addComponent(mThreshBox);
	BaseDialog::setOptions();
}

void CannyFilterDialog::processImage()
{
	int low = mThreshBox->getValue( 0 );
	int high = mThreshBox->getValue( 1 );

	mController->cannyFilter( low, high );

	QImage image = mController->requestWCQImage();
	displayImage( image );
}
