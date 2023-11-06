#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainApplication; }
QT_END_NAMESPACE

class MainApplication : public QMainWindow
{
    Q_OBJECT

public:
    MainApplication(QWidget *parent = nullptr);
    ~MainApplication();

private slots:
    void onOpenImageClicked();
    QVector<int> findProperties(QVector<QVector<int>> &imageArray, unsigned int &rows, unsigned int &cols);
    int bfs(QVector<int> &position, QVector<QVector<int>> &explored, unsigned int &rows, unsigned int &cols, QVector<QVector<int>> &imageArray);

private:
    Ui::MainApplication *ui;
};
#endif
