#include "CannyFilterDialog.h"

CannyFilterDialog::CannyFilterDialog(QWidget *parent, Controller *controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Canny Edge Detector Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	threshBox = new QGroupBox( this );
	threshBox->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	threshBox->setTitle( "Threshold" );
	QGridLayout* grid = new QGridLayout( threshBox );
	QSpacerItem* spacer = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );

	labelLowThresh = new QLabel( "Low", threshBox );
	labelLowThresh->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	labelLowThresh->setAlignment(Qt::AlignRight);
	leditLow = new QLineEdit( "50", threshBox );
	leditLow->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	leditLow->setMaximumSize( 40, 90 );

	labelHighThresh = new QLabel( "High", threshBox );
	labelHighThresh->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	labelHighThresh->setAlignment(Qt::AlignRight);
	leditHigh = new QLineEdit( "150", threshBox );
	leditHigh->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	leditHigh->setMaximumSize( 40, 90 );

	grid->addWidget(labelLowThresh,0,0);
	grid->addWidget(leditLow,0,1);
	grid->addWidget(labelHighThresh,1,0);
	grid->addWidget(leditHigh,1,1);
	grid->addItem(spacer,0,2);
	threshBox->setLayout(grid);

	setOptions();
}

CannyFilterDialog::~CannyFilterDialog()
{
	delete threshBox;
	delete labelHighThresh;
	delete labelLowThresh;
	delete leditHigh;
	delete leditLow;
}

void CannyFilterDialog::setOptions()
{
	addComponent(threshBox);
	BaseDialog::setOptions();
}

void CannyFilterDialog::processImage()
{
	int low = leditLow->text().toInt();
	int up = leditHigh->text().toInt();

	mController->cannyFilter( low, up );

	QImage image = mController->requestWCQImage();
	displayImage( image );
}
