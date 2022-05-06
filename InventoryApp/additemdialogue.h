#ifndef ADDITEMDIALOGUE_H
#define ADDITEMDIALOGUE_H
#include "item.h"
#include <QDialog>

namespace Ui {
class addItemDialogue;
}

class addItemDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit addItemDialogue(Item*& newItem, QWidget *parent = nullptr);
    ~addItemDialogue();

    void confirmAdd();
    void loadItemImage();

private:
    Ui::addItemDialogue *ui;
    Item** newItem;
    QString imageFilePath;
};

#endif // ADDITEMDIALOGUE_H
