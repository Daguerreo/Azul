#ifndef FRAMEBUTTONBOX_H
#define FRAMEBUTTONBOX_H

#include <QObject>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>

class CommitButtonsFrame : public QFrame
{
	Q_OBJECT

public:
	CommitButtonsFrame(QWidget *parent = 0, const bool& hasApplyButton=false);
	~CommitButtonsFrame();

	void addApplyButton();

public slots:
	void on_buttonOk_clicked();
	void on_buttonCancel_clicked();
	void on_buttonApply_clicked();

signals:
	void sigButtonOkClicked();
	void sigButtonCancelClicked();
	void sigButtonApplyClicked();

protected:
	QGridLayout *mGrid;
	QPushButton *mButtonOk;
	QPushButton *mButtonCancel;
	QPushButton *mButtonApply;
	QSpacerItem *mSpacer;
	bool		hasApply;

};

#endif // FRAMEBUTTONBOX_H
