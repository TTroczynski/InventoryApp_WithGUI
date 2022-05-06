#ifndef ITEM_H
#define ITEM_H
#include <QString>


class Item
{
    QString name;
    int quantity;
    QString imageFilePath;

public:
    Item(QString, int, QString = "none.png");
    void setName(QString);
    void setQuantity(int);
    void setImageFilePath(QString);

    QString getName() const;
    int getQuantity() const;
    QString getImageFilePath() const;



};

#endif // ITEM_H
