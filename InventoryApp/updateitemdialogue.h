#ifndef UPDATEITEMDIALOGUE_H
#define UPDATEITEMDIALOGUE_H
#include "item.h"
#include <QDialog>

namespace Ui {
class updateItemDialogue;
}

class updateItemDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit updateItemDialogue(Item* currentItem, QWidget *parent = nullptr);

    //not pass-by ref because were going to modify the values of the newItem
    //We would pass by ref if we wanted a ref to the object that we are not modifying
    void confirmUpdate();
    void loadItemImage();


    ~updateItemDialogue();

private:
    Ui::updateItemDialogue *ui;
    Item* currentItem;
    QString imageFilePath;
};

#endif // UPDATEITEMDIALOGUE_H
