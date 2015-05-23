#ifndef SHARPENDIALOG_H
#define SHARPENDIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class SharpenDialog;
}

class SharpenDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SharpenDialog(QWidget *parent = 0);
	~SharpenDialog();

public slots:
	void processImage(const QImage &image);

protected slots:
	void sharpen( const QImage &image );

signals:
	void sigCommitImage(const QImage &image);

private slots:
	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

private:
	Ui::SharpenDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	cv::Mat mat;
	QImage mImage;
	QImage mImageOriginal;
};

#endif // SHARPENDIALOG_H
