#ifndef CONTRASTDIALOG_H
#define CONTRASTDIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class ContrastDialog;
}

class ContrastDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ContrastDialog(QWidget *parent = 0);
	~ContrastDialog();

public slots:
	void processImage(const QImage &image);

protected slots:
	void resizeEvent(QResizeEvent *event);
	void process(const QImage &image, const double &alpha, const int &beta);

private slots:
	void on_hsldBright_valueChanged(int value);
	void on_hsldContrast_valueChanged(int value);
	void on_btnApply_clicked();
	void on_buttonBox_rejected();
	void on_buttonBox_accepted();

signals:
	void sigCommitImage(const QImage &image, const qint64 &time);

private:
	Ui::ContrastDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	cv::Mat mat;
	QImage mImage;
	QImage mImageOriginal;
	qint64 mTime;
	double mContrast;
	int mBrightness;
};

#endif // CONTRASTDIALOG_H
