#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <matrixconverter.h>
#include <employesloader.h>
#include <diagram_builder.h>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mMatrix{0, 0}
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    const auto& file_name = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Images (*.png *.jpg *.bmp)"));
    if (file_name.isNull())
        return;
    QImage image;
    image.load(file_name);
    mMatrix = MatrixConverter::FromImage(image, 100);
    DrawMatrix(mMatrix);
}


void MainWindow::on_pushButton_2_clicked()
{
    const auto& file_name = QFileDialog::getOpenFileName(this,
        tr("Выбор файла"), "", tr(""));
    if (file_name.isNull())
        return;
    mEmployes = EmployesLoader::FromTextFile(file_name.toStdString());
    qDebug() << "Загружено сотрудников: " << mEmployes.size();
}


void MainWindow::on_pushButton_3_clicked()
{
    mTimer.setInterval(100);
    connect(&mTimer, &QTimer::timeout, this, [this](){
        ++mTime;
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        const auto& diagramm = DiagramBuilder::BuildDiagram(mMatrix, mEmployes, mTime);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        ui->lblTime->setText("Текущее время: " + QString::number(mTime));
        const auto& building_time = QString::number(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count());
        ui->lblBuildingTime->setText("Время построения диаграммы: " + building_time + " µs");
        DrawMatrix(diagramm);
    });
    mTimer.start();
}

void MainWindow::DrawMatrix(const Matrix& matrix)
{
    mScene->clear();
    const auto& new_image = MatrixConverter::ToImage(matrix, mEmployes);
    mScene->addPixmap(QPixmap::fromImage(new_image));
    mScene->setSceneRect(new_image.rect());
    ui->mainImage->setScene(mScene);
}

