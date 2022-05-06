#include "updateitemdialogue.h"
#include "ui_updateitemdialogue.h"
#include <QFileDialog>
#include <QMessageBox>

updateItemDialogue::updateItemDialogue(Item* currentItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateItemDialogue)
{
    ui->setupUi(this);
    this->currentItem = currentItem;

    if(currentItem != nullptr){
        ui->lblItemName->setText(currentItem->getName());
        QPixmap pixmap(currentItem->getImageFilePath());
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);

        ui->sbQuantity->setValue(currentItem->getQuantity());

        imageFilePath = currentItem->getImageFilePath();
    }

    connect(ui->btnConfirmEdit, &QPushButton::clicked, this, &updateItemDialogue::confirmUpdate);
    connect(ui->btnLoadImage, &QPushButton::clicked, this, &updateItemDialogue::loadItemImage);
}

void updateItemDialogue::confirmUpdate(){

    int quantity = ui->sbQuantity->value();

    if(quantity >= 1){
        currentItem->setQuantity(quantity);
        currentItem->setImageFilePath(imageFilePath);
        this->close();
    }else{
        QMessageBox mb;
        mb.setText("Quantity must be at least 1.");
        mb.exec();
    }
}

void updateItemDialogue::loadItemImage(){

    QString fileName;

    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image Files (*.png, *.jpg)");

    if(fileName != "") {
        int lastSlash = fileName.lastIndexOf("/");
        QString shortName = fileName.right(fileName.size() - lastSlash -1);

        QFile::copy(fileName, "./images/" + shortName);
        QPixmap pixmap("./images/" + shortName);

        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);

        imageFilePath = "./images/" + shortName;
    }
}

updateItemDialogue::~updateItemDialogue()
{
    delete ui;
}
