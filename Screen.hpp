// 326627635 | adi.peisach@gmail.com

#ifndef TREE_ITERATORS_GUI_SCREEN_HPP
#define TREE_ITERATORS_GUI_SCREEN_HPP
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGuiApplication>
#include <QScreen>
#include "Tree.cpp"
#include "Constants.hpp"

using std::string;

template<typename T, unsigned int D>
class Screen {
    Tree<T, D>* tree;
    QGraphicsView* view;
    QGraphicsScene* scene;
    int screenWidth;
    int screenHeight;

public:
    Screen(Tree<T,D>& tree) {
        int argc = 1;
        char a = 'x';
        char* pa = &a;
        char* argv[1] = {pa};
        QApplication app(argc, argv);

        QMainWindow mainWindow;
        mainWindow.setWindowTitle("Tree Iterator Visualization | ★ Adi Peisach ★");
        mainWindow.showMaximized();

        scene = new QGraphicsScene(&mainWindow);
        view = new QGraphicsView(scene, &mainWindow);
        view->setRenderHint(QPainter::Antialiasing);
        mainWindow.setCentralWidget(view);

        QScreen *screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();
        screenWidth = screenGeometry.width()*0.75;
        screenHeight = screenGeometry.height();

        this->tree = &tree;
        displayTree();

        app.exec();
    }

private:
    void displayTree();
    void displayNode(typename Node<T>::Node* node, int x, int y, int leftBorder, int rightBorder);
    QPointF drawNode(typename Node<T>::Node* node, int x, int y);

};

template <typename T>
QString toQString(T value) {
    string valueString = std::to_string(value);
    return QString::fromStdString(valueString);
}

template <>
inline QString toQString<double>(double value) {
    string valueString = std::to_string(value);
    while (valueString.back() == '0') valueString.pop_back();
    return QString::fromStdString(valueString);
}

template <>
inline QString toQString<string>(string value) {
    return QString::fromStdString(value);
}

template<typename T, unsigned int D>
QPointF Screen<T, D>::drawNode(typename Node<T>::Node* node, int x, int y) {
    int nodeRadius = Constants::NODE_RADIUS;

    QGraphicsEllipseItem* ellipse = scene->addEllipse(x - nodeRadius, y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius);
    QBrush brush(Qt::black);
    QPen pen(Qt::black);
    ellipse->setBrush(brush);
    ellipse->setPen(pen);

    // Display node value as text
    QString textString = toQString(node->getValue());
    QGraphicsTextItem* text = scene->addText(textString);
    text->setDefaultTextColor(Qt::white);
    text->setPos(x - nodeRadius / 2, y - nodeRadius / 2);

    return ellipse->rect().center();
}

template<typename T, unsigned int D>
Screen<T, D> makeScreen(Tree<T, D> &inputTree) {
    return Screen<T, D>(inputTree);
}

template<typename T, unsigned int D>
void Screen<T, D>::displayTree() {
    if (tree->getRoot() == nullptr) return;

    // Starting coordinates and spacing
    int rootX = screenWidth / 2;
    int rootY = 10 + Constants::NODE_RADIUS;

    displayNode(tree->getRoot(), rootX, rootY, 0, screenWidth);
}

template<typename T, unsigned int D>
void Screen<T, D>::displayNode(typename Node<T>::Node* node, int x, int y, int leftBorder, int rightBorder) {
    QPointF currCenter = drawNode(node, x, y);

    for (unsigned int i = 0; i < node->numChildren(); i++) {
        Node<T>* child = node->getChild(i);
        int childX = (rightBorder-leftBorder)/(D+1)*(i+1) + leftBorder;
        int childLeftX = (rightBorder-leftBorder)/(D+1)*(i) + leftBorder;
        int childRightX = (rightBorder-leftBorder)/(D+1)*(i+2) + leftBorder;

        QPointF childCenter = drawNode(child, childX, y + Constants::VERTICAL_SPACING);
        scene->addLine(QLineF(currCenter, childCenter));
        displayNode(child,childX,y+Constants::VERTICAL_SPACING,
                    childLeftX+Constants::NODE_RADIUS*2.1,childRightX-Constants::NODE_RADIUS*2.1);
    }

}


#endif //TREE_ITERATORS_GUI_SCREEN_HPP
