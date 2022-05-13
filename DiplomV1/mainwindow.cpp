#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <matrixconverter.h>
#include <employesloader.h>
#include <diagram_builder.h>

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
    QImage image;
    mScene->clear();
    image.load(file_name);
    mMatrix = MatrixConverter::FromImage(image, 100);
    DrawMatrix();
}


void MainWindow::on_pushButton_2_clicked()
{
    const auto& file_name = QFileDialog::getOpenFileName(this,
        tr("Выбор файла"), "", tr("")).toStdString();
    mEmployes = EmployesLoader::FromTextFile(file_name);
    qDebug() << "Загружено сотрудников: " << mEmployes.size();
}


void MainWindow::on_pushButton_3_clicked()
{
    mMatrix = DiagramBuilder::BuildDiagram(mMatrix, mEmployes);
    qDebug() << "Диаграмма построена";
    DrawMatrix();
}

void MainWindow::DrawMatrix()
{
    const auto& new_image = MatrixConverter::ToImage(mMatrix, mEmployes);
    mScene->addPixmap(QPixmap::fromImage(new_image));
    mScene->setSceneRect(new_image.rect());
    ui->mainImage->setScene(mScene);
}

