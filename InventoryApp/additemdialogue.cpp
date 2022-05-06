#include "additemdialogue.h"
#include "ui_additemdialogue.h"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

addItemDialogue::addItemDialogue(Item*& newItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItemDialogue)
{
    ui->setupUi(this);

    this->newItem = &newItem;
    imageFilePath = "none.png";

    connect(ui->btnConfirmAdd, &QPushButton::clicked, this, &addItemDialogue::confirmAdd);

    connect(ui->btnLoadImage, &QPushButton::clicked, this, &addItemDialogue::loadItemImage);

    QDir pathDir("./images");
    if(!pathDir.exists()){
        QDir().mkdir("./images");
    }
}

addItemDialogue::~addItemDialogue()
{
    delete ui;
}

void addItemDialogue::confirmAdd() {

    QString productName = ui->txtProductName->text();
    int quantity = ui->sbQuantity->value();

    if(productName.trimmed()!="" && quantity >= 1) {
        *newItem = new Item(productName, quantity, imageFilePath);
        this->close();
    }
    else{
        QMessageBox mb;
        mb.setText("You must have a valid name and a quantity of at least 1");
        mb.exec();
    }
}

void addItemDialogue::loadItemImage() {

    QString fileName;

    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image Files (*.png *.jpg");

    if(fileName != "") {
        int lastSlash = fileName.lastIndexOf("/");
        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./images/" + shortName);

        QPixmap pixMap("./images/" + shortName);

        ui->lblImage->setPixmap(pixMap);
        ui->lblImage->setScaledContents(true);

        imageFilePath = "./images/" + shortName;
    }
}
