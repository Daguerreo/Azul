#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <Mediator.h>
#include <OptionsFrame.h>
#include <CommitButtonsFrame.h>

class BaseDialog : public QDialog
{
	Q_OBJECT

public:
	explicit BaseDialog(QWidget *parent=0, Mediator *mediator=0, bool hasApplyButton=true);
	~BaseDialog();

	void addComponent(QWidget *widget);

public slots:
	void openDialog();
	void buttonOkClicked();
	void buttonCancelClicked();
	void buttonApplyClicked();

protected slots:
	void resizeEvent(QResizeEvent *event);
	virtual void setOptions();
	virtual void processImage();
	void displayImage(const QImage &image);

protected:
	QGraphicsView* mGraphicsView;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
	QVBoxLayout* mOptionVBox;
	QHBoxLayout* mLayout;
	OptionsFrame* mOptionsFrame;
	CommitButtonsFrame* mCommitFrame;
	QSpacerItem* mSpacer;
	Mediator* mMediator;

signals:
	void sigUpdateMainWindow();
	void sigApplyClicked();
};

#endif // MYDIALOG_H
