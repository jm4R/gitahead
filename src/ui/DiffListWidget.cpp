#include "DiffListWidget.h"

#include "BlameEditor.h"
#include "FileList.h"
#include "git/Patch.h"

#include <QVBoxLayout>

DiffListWidget::DiffListWidget(const git::Repository &repo, QWidget *parent)
		: ContentWidget(parent)
{
	mFiles = new FileList(repo, this);
	mEditor = new BlameEditor(repo, this);

	QSplitter *splitter = new QSplitter(Qt::Vertical, this);
	splitter->setHandleWidth(0);
	splitter->addWidget(mFiles);
	splitter->addWidget(mEditor);
	splitter->setStretchFactor(1, 1);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(splitter);

	RepoView *view = RepoView::parentView(this);
	connect(mEditor, &BlameEditor::linkActivated, view, &RepoView::visitLink);
}

QString DiffListWidget::selectedFile() const
{
	return "Kura.cpp";
}

void DiffListWidget::setDiff(const git::Diff &diff, const QString &file,
														 const QString &pathspec)
{
	mFiles->setDiff(diff);
}

#include "DiffListWidget.moc"
