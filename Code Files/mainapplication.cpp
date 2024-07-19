#include "mainapplication.h"
#include "ui_mainapplication.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QQueue>
#include <QTextStream>
#include <QFile>

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainApplication)
{
    ui->setupUi(this);
}

MainApplication::~MainApplication()
{
    delete ui;
}

void MainApplication::onOpenImageClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.xpm *.jpg)"));
    if (!fileName.isEmpty()) {
        QMessageBox::information(this, "Info", fileName);
        QImage image(fileName);
        QPixmap pixmap = QPixmap::fromImage(image);
        int width = ui->labelImage->width();
        int height = ui->labelImage->height();
        ui->labelImage->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

        unsigned int columns = image.width();
        unsigned int rows = image.height();
        unsigned int numBlackPixels = 0;
        QVector<QVector<int>> imageArray(rows, QVector<int>(columns, 0));

        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < columns) {
                QColor currentColor(image.pixel(j, i));
                int red = currentColor.red();
                int green = currentColor.green();
                int blue = currentColor.blue();
                int alpha = currentColor.alpha();

                if (red + green + blue < 20 && alpha > 240) {
                    imageArray[i][j] = 1;
                    numBlackPixels += 1;
                }
            }
        }

        QString filename = "C:/Users/vinay/Desktop/temp.txt";
        QFile outputFile(filename);
        if (outputFile.open(QFile::ReadWrite | QFile::Text)) {
            QTextStream out(&outputFile);
            for (unsigned int i = 0; i < rows; i++) {
                for (unsigned int j = 0; j < columns; j++) {
                    out << imageArray[i][j];
                }
                out << " " << Qt::endl;
            }
        }

        ui->dimensionsLabel->setText(QString::fromStdString("W: " + std::to_string(columns) + "  H: " + std::to_string(rows)));
        float pixelDensity = ((float)numBlackPixels / (float)(columns * rows)) * 100;
        ui->occupancyPercentageLabel->setText(QString::fromStdString(std::to_string(pixelDensity)));

        QVector<int> results = this->findProperties(imageArray, rows, columns);
        ui->numberOfBlobsLabel->setText(QString::fromStdString(std::to_string(results[0])));
        ui->maxBlobAreaLabel->setText(QString::fromStdString(std::to_string(results[1]));
    }
}

QVector<int> MainApplication::findProperties(QVector<QVector<int>> &imageArray, unsigned int &rows, unsigned int &columns)
{
    int numIslands = 0;
    int maxArea = 0;
    int area = 0;
    QVector<QVector<int>> explored(rows, QVector<int>(columns, 0));

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            if (imageArray[i][j] == 1 && explored[i][j] == 0) {
                QVector<int> position{(int)i, (int)j};
                area = this->bfs(position, explored, rows, columns, imageArray);
                if (area > maxArea) {
                    maxArea = area;
                }
                numIslands += 1;
            }
        }
    }

    QVector<int> results{numIslands, maxArea};
    return results;
}

int MainApplication::bfs(QVector<int> &position, QVector<QVector<int>> &explored, unsigned int &rows, unsigned int &columns, QVector<QVector<int>> &imageArray)
{
    QVector<int> up{-1, 0};
    QVector<int> down{1, 0};
    QVector<int> left{0, -1};
    QVector<int> right{0, 1};
    int islandArea = 0;
    QQueue<QVector<int>> notExplored;
    notExplored.enqueue(position);

    while (!notExplored.isEmpty()) {
        QVector<QVector<int>> potentialMoves{{position[0] + up[0], position[1] + up[1]}, {position[0] + down[0], position[1] + down[1]},
                                             {position[0] + left[0], position[1] + left[1]}, {position[0] + right[0], position[1] + right[1]}};
        for (QVector<int> move : potentialMoves) {
            if (move[0] < 0 || move[0] > (int)rows - 1 || move[1] < 0 || move[1] > (int)columns - 1 || explored[move[0]][move[1]] == 1 || imageArray[move[0]][move[1]] == 0) {
                continue;
            }
            notExplored.enqueue(move);
        }
        explored[position[0]][position[1]] = 1;
        islandArea += 1;
        notExplored.dequeue();
        if (!notExplored.isEmpty()) {
            position = notExplored.head();
        }
    }
    return islandArea;
}