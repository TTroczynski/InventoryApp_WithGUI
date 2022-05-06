#include "item.h"

Item::Item(QString name, int quantity, QString imageFilePath){
    this->name = name;
    this->quantity = quantity;
    this->imageFilePath = imageFilePath;
}
void Item::setName(QString name){

    this->name = name;
}
void Item::setQuantity(int quantity){
    this->quantity = quantity;
}
void Item::setImageFilePath(QString path){
    this->imageFilePath = path;
}

QString Item::getName() const{
    return name;
}
int Item::getQuantity() const{
    return quantity;
}
QString Item::getImageFilePath() const{
    return imageFilePath;
}
