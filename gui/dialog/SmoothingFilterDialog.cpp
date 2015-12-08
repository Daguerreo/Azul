#include "SmoothingFilterDialog.h"

SmoothingFilterDialog::SmoothingFilterDialog(QWidget* parent, Controller* controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Smoothing Filter Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	mAlgoRadio = new RadioButtonGroupBox(this, 4);
	mAlgoRadio->setTitle("Algorithm");
	mAlgoRadio->placeRadioButtons(0,0,0,"Mean");
	mAlgoRadio->placeRadioButtons(1,1,0,"Median");
	mAlgoRadio->placeRadioButtons(2,0,1,"Gaussian");
	mAlgoRadio->placeRadioButtons(3,1,1,"Bilateral");
	mAlgoRadio->getRadio(3)->setEnabled(false);

	mKernelBox = new QGroupBox( this );
	mKernelBox->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mKernelBox->setTitle( "Kernel" );
	QGridLayout* grid = new QGridLayout( mKernelBox );
	QSpacerItem* spacer = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );

	labelKernel = new QLabel( "Radius", mKernelBox );
	labelKernel->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	labelKernel->setAlignment(Qt::AlignRight);

	leditKernel = new QLineEdit( "1", mKernelBox );
	leditKernel->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	leditKernel->setMaximumSize( 30, 90 );

	grid->addWidget(labelKernel,0,0);
	grid->addWidget(leditKernel,0,1);
	grid->addItem(spacer,0,2);
	mKernelBox->setLayout(grid);

	setOptions();
}

SmoothingFilterDialog::~SmoothingFilterDialog()
{
	delete mAlgoRadio;
}

void SmoothingFilterDialog::setOptions()
{
	addComponent(mAlgoRadio);
	addComponent(mKernelBox);
	BaseDialog::setOptions();
}

void SmoothingFilterDialog::processImage()
{
	int radius = leditKernel->text().toInt();
	switch( mAlgoRadio->checkedRadio() )
	{
	case 0: // Mean
		mController->meanFilter( radius );
		break;

	case 1: // Median
		mController->medianFilter( radius );
		break;

	case 2: // Gaussian
		mController->gaussianFilter( radius );
		break;

	default:
		mController->meanFilter( radius );
		break;
	}

	QImage image = mController->requestWCQImage();
	displayImage( image );
}
