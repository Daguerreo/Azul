#ifndef SMOOTHINGDIALOG_H
#define SMOOTHINGDIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class SmoothingDialog;
}

class SmoothingDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SmoothingDialog(QWidget *parent = 0);
	~SmoothingDialog();

public slots:
	void processImage(const QImage &image);

protected slots:
	void resizeEvent(QResizeEvent *event);
	void meanFilter(const QImage &image, const int &kernel);
	void medianFilter(const QImage &image, const int &kernel);
	void bilateralFilter(const QImage &image, const int &kernel);
	void gaussianFilter(const QImage &image, const int &kernel);

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();
	void on_btnApply_clicked();
	void on_leKernel_textChanged(const QString &arg1);

signals:
	void sigCommitImage(const QImage &image, const qint64 &time);

private:
	Ui::SmoothingDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	cv::Mat mMat;
	QImage mImage;
	QImage mImageOriginal;
	qint64 mTime;
	int mKernel;

};

#endif // SMOOTHINGDIALOG_H
