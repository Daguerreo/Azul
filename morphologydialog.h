#ifndef MORPHOLOGYDIALOG_H
#define MORPHOLOGYDIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MorphologyDialog;
}

class MorphologyDialog : public QDialog
{
	Q_OBJECT

public:
	explicit MorphologyDialog(QWidget *parent = 0);
	~MorphologyDialog();

public slots:
	void processImage(const QImage &image);

protected slots:
	void resizeEvent(QResizeEvent *event);

	void dilate(const QImage &image, const int &size, const int &shape, const int &iterations);
	void erode(const QImage &image, const int &size, const int &shape, const int &iterations);
private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();
	void on_btnApply_clicked();
	void on_leKernel_textChanged(const QString &arg1);
	void on_leIterations_textChanged(const QString &arg1);

signals:
	void sigCommitImage(const QImage &image, const qint64 &time);

private:
	Ui::MorphologyDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	cv::Mat mMat;
	QImage mImage;
	QImage mImageOriginal;
	qint64 mTime;
	int mKernelSize;
	int mIter;
	int mShape;
};

#endif // MORPHOLOGYDIALOG_H
