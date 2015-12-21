#include "MorphologyDialog.h"

MorphologyDialog::MorphologyDialog(QWidget *parent, Controller *controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Binary Morphology Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage() ) );

	mOperatorRadio = new RadioButtonGroupBox( this, 4 );
	mOperatorRadio->setTitle("Operator");
	mOperatorRadio->placeRadioButtons( 0, 0, 0, "Dilate" );
	mOperatorRadio->placeRadioButtons( 1, 1, 0, "Erode" );
	mOperatorRadio->placeRadioButtons( 2, 0, 1, "Open" );
	mOperatorRadio->placeRadioButtons( 3, 1, 1, "Close" );

	connect( mOperatorRadio,	SIGNAL( sigRadioButtonChanged(int) ),
			 this,				SLOT( enableIterations(int) ) );

	mKernelRadio = new RadioButtonGroupBox( this, 3 );
	mKernelRadio->setTitle("Kernel Shape");
	mKernelRadio->placeRadioButtons( 0, 0, 0, "Rectangle" );
	mKernelRadio->placeRadioButtons( 1, 1, 0, "Cross" );
	mKernelRadio->placeRadioButtons( 2, 2, 0, "Ellipse" );

	QSpacerItem* spacer = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
	mOptionsBox = new EntryGroupBox( this, 2 );
	mOptionsBox->setTitle("Options");
	mOptionsBox->placeEntry( 0, 0, 0, "Kernel Radius", 1);
	mOptionsBox->placeEntry( 1, 1, 0, "Iterations", 1);
	mOptionsBox->placeSpacer( spacer, 0, 2);

	setOptions();
}

MorphologyDialog::~MorphologyDialog()
{
	delete mOptionsBox;
	delete mOperatorRadio;
	delete mKernelRadio;
}

void MorphologyDialog::setOptions()
{
	addComponent( mOperatorRadio );
	addComponent( mKernelRadio );
	addComponent( mOptionsBox );
	BaseDialog::setOptions();
}

void MorphologyDialog::processImage()
{
	int radius = mOptionsBox->getValue( 0 );
	int iter = mOptionsBox->getValue( 1 );
	int shape = mKernelRadio->checkedRadio();

	switch( mOperatorRadio->checkedRadio() )
	{
		case 0: // Dilate
		mController->morphologyDilate( radius, shape, iter );
		break;

		case 1: // Erode
		mController->morphologyErode( radius, shape, iter );
		break;

		case 2: // Open
		mController->morphologyOpen( radius, shape );
		break;

		case 3: // Close
		mController->morphologyClose( radius, shape );
		break;

		default:
		mController->morphologyDilate( radius, shape, iter );
		break;
	}

	QImage image = mController->requestWCQImage();
	displayImage( image );
}

void MorphologyDialog::enableIterations(int index)
{
	bool enabled = (index < 2) ? true : false;
	mOptionsBox->setEntryEnabled( 1, enabled );
}
