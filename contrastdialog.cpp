#include "contrastdialog.h"
#include "ui_contrastdialog.h"

ContrastDialog::ContrastDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ContrastDialog)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&mScene);
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	mContrast = 1.0;
	mBrightness = 0;

	connect( this,		SIGNAL( sigCommitImage(QImage) ),
			 parent,	SLOT( updateImage(QImage) ) );
}

ContrastDialog::~ContrastDialog()
{
	delete ui;
	delete mPixmapItem;
}

void ContrastDialog::resizeEvent(QResizeEvent *event)
{
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

void ContrastDialog::processImage( const QImage &image )
{
	mImageOriginal = image.copy(0,0,image.width(),image.height());
	mImage = image.copy(0,0,image.width(),image.height());
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void ContrastDialog::on_hsldContrast_valueChanged(int value)
{
	mContrast = ((double) ui->hsldContrast->value())/10.0;
	ui->lblCurrContrast->setNum( mContrast );
}

void ContrastDialog::on_hsldBright_valueChanged(int value)
{
	mBrightness = ui->hsldBright->value();
	ui->lblCurrBright->setNum( mBrightness );
}

void ContrastDialog::on_buttonBox_accepted()
{
	emit( sigCommitImage( mImage ) );

	ContrastDialog::close();
}

void ContrastDialog::on_buttonBox_rejected()
{
	ContrastDialog::close();
}

void ContrastDialog::on_btnApply_clicked()
{
	process( mImageOriginal, mContrast, mBrightness );
	mImage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void ContrastDialog::process( const QImage &image, const double &alpha, const int& beta )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );

	tmp.convertTo( mat, -1, alpha, beta );
}
