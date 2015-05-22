#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core/core.hpp>

namespace Ui {
class ImageDialog;
}

class GrayscaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GrayscaleDialog(QWidget *parent = 0);
    ~GrayscaleDialog();

public slots:
	void processImage(const QImage &image);

protected slots:
	void resizeEvent(QResizeEvent *event);

	void grayscaleAvg(const QImage &image, int range);
	void grayscaleMin(const QImage &image);
	void grayscaleMax(const QImage &image);
	void grayscaleLuma(const QImage &image);
	void grayscaleDesaturation(const QImage &image);
private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();
	void on_btnApply_clicked();

private:
    Ui::ImageDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	cv::Mat mat;
	QImage mImage;
	QImage mImageOriginal;

	void setOptions();
	int maxRGB(const int &r, int &g, int &b);
	int minRGB(const int &r, int &g, int &b);
signals:
	void sigCommitImage(const QImage &image);
};

#endif // IMAGEDIALOG_H
